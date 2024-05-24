# include <stdio.h>
# include <stdlib.h> /* for atof */
# include <string.h> /* strcmp */
# include <math.h>
# include <ctype.h>

int getop (char s[]);
int getch (void);
void ungetch (int c);
void push (double f);
double pop (void);
double peek (void);
void clear (void);
void set_var (char var_name, double value);
double get_var (char var_name);
double set_last (double value);
double get_last (void);

# define GETOP_NUMBER '0'   /* signal that a number was found */
# define GETOP_SYMBOL 'a'   /* signal that a symbol was found */
# define MAXOP 128    /* max size of operand or operator */
# define BUFSIZE 128
# define MAXVAL 128 /* max depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

int buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

double vars['Z'-'A'];
double last_val;


/* reverse Polish calculator */
int main ()
{
  int type;
  double op2, op_r;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case GETOP_SYMBOL:
      if (strcmp("sin", s) == 0) {          /* math sin */
	push(sin(pop()));
      } else if (strcmp("cos", s) == 0) {   /* math cos */
	push(cos(pop()));
      } else if (strcmp("tan", s) == 0) {   /* math tan */
	push(tan(pop()));
      } else if (strcmp("asin", s) == 0) {  /* math asin */
	push(asin(pop()));
      } else if (strcmp("acos", s) == 0) {  /* math acos */
	push(acos(pop()));
      } else if (strcmp("atan", s) == 0) {  /* math atan */
	push(atan(pop()));
      } else if (strcmp("atan2", s) == 0) { /* math atan2 */
	push(atan2(pop(), pop()));
      } else if (strcmp("sinh", s) == 0) {  /* math sinh */
	push(sinh(pop()));
      } else if (strcmp("cosh", s) == 0) {  /* math cosh */
	push(cosh(pop()));
      } else if (strcmp("tanh", s) == 0) {  /* math tanh */
	push(tanh(pop()));
      } else if (strcmp("exp", s) == 0) {   /* math exp */
	push(exp(pop()));
      } else if (strcmp("log", s) == 0) {   /* math log */
	push(log(pop()));
      } else if (strcmp("log10", s) == 0) { /* math log10 */
	push(log10(pop()));
      } else if (strcmp("pow", s) == 0) {   /* math pow */
	op2 = pop();
	push(pow(pop(), op2));
      } else if (strcmp("sqrt", s) == 0) {  /* math sqrt */
	push(sqrt(pop()));
      } else if (strcmp("ceil", s) == 0) {  /* math ceil */
	push(ceil(pop()));
      } else if (strcmp("floor", s) == 0) { /* math floor */
	push(floor(pop()));
      } else if (strcmp("abs", s) == 0) {   /* math fabs */
	push(fabs(pop()));
      } else if (strcmp("clear", s) == 0) { /* clear the stack */
	clear();
      } else if (strcmp("peek", s) == 0) {   /* peek top stack element */
	printf("\t%.8g\n", peek());
      } else if (strcmp("swap", s) == 0) { /* swap top two stack elements */
	op_r = pop();
	op2 = pop();
	push(op_r);
	push(op2);
      } else if (strlen(s)==2 &&
		 ((s[0]==':' && ((s[1]>='A' && s[1]<='Z') || (s[1]=='?'))) ||
		  (s[1]=='=' && s[0]>='A' && s[0]<='Z'))) { /* variables */
	if (s[1]=='=') { /* variable set */
	  set_var(s[0], pop());
	} else if (s[1]=='?') { /* last return */
	  push(get_last());
	} else { /* variable get */
	  push(get_var(s[1]));
	}
      } else {
	printf("error: unknown symbol %s\n", s);
      }
      break;
    case GETOP_NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
	push(pop() / op2);
      } else {
	printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0) {
	push((long int) pop() % (long int) op2);
      } else {
	printf("error: zero modulus\n");
      }
      break;
    case '\n':
      printf("\t%.8g\n", set_last(pop()));
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}


/* getop: get next character, numeric operand or function/command */
int getop (char s[])
{
  int i, c;
  
  while ((s[0] = c = getch()) == ' ' || c == '\t') {
  }

  if (c == EOF || c == '\n') {
    return c;
  }
  /* operator, single digit number or single letter symbol */
  if ((s[1] = c = getch()) == ' ' || c == '\t' || c == '\n' || c == EOF) {
    ungetch(c);
    s[1] = '\0';
    c = s[0];
    /* number */
    if (isdigit(c)) {
      return GETOP_NUMBER;
    }
    /* single letter symbol [a-zA-Z] */
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      return GETOP_SYMBOL;
    }
    /* operator */
    else {
      return c;
    }
  }
  /* number or symbol */
  else {
    ungetch(c);
    c = s[0];
    /* number */
    if (isdigit(c) || c == '-' || c == '.') {
      i = 0;
      if (c == '-') { /* move by a minus (-) sign */
	s[++i] = c = getch();
      }
      if (isdigit(c)) { /* collect integer part */
	while (isdigit(s[++i] = c = getch())) {
	}
      }
      if (c == '.') { /* collect fraction part */
	while (isdigit(s[++i] = c = getch())) {
	}
      }
      s[i] = '\0';
      ungetch(c);
      return GETOP_NUMBER;
    }
    /* symbol */
    else {
      i = 0;
      while ((s[++i] = c = getch()) != ' ' && c != '\t' && c != '\n' && c != EOF) {
      }
      s[i] = '\0';
      ungetch(c);
      return GETOP_SYMBOL;
    }
  }
}


/* getch: get a (possibly pushed-back) character */
int getch (void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch: push character back on input */
void ungetch (int c)
{
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}


/* push: push f onto stack */
void push (double f)
{
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}


/* pop: pop and return top value from stack */
double pop (void)
{
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}


/* peek: return top value from stack without popping */
double peek (void)
{
  if (sp > 0) {
    return val[sp - 1];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}


/* clear: clear the stack */
void clear (void)
{
  sp = 0;
}


/* set_var: set variable */
void set_var (char var_name, double value)
{
  vars[var_name-'A'] = value;
}


/* get_var: get variable value */
double get_var (char var_name)
{
  return vars[var_name-'A'];
}


/* set_last: set last returned value */
double set_last (double value)
{
  return last_val = value;
}


/* get_last: get last returned value */
double get_last (void)
{
  return last_val;
}
