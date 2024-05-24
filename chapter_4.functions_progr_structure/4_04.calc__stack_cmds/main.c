# include <stdio.h>
# include <stdlib.h> /* for atof */
# include <ctype.h>

int getop (char s[]);
int getch (void);
void ungetch (int c);
void push (double f);
double pop (void);
double peek (void);
void clear (void);

# define GETOP_NUMBER '0'   /* signal that a number was found */
# define MAXOP 128    /* max size of operand or operator */
# define BUFSIZE 128
# define MAXVAL 128 /* max depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */


/* reverse Polish calculator */
int main ()
{
  int type;
  double op2, op_r;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case ':': /* print the top stack element without popping */
      printf("\t%.8g\n", peek());
      break;
    case '|': /* swap top two stack elements */
      op_r = pop();
      op2 = pop();
      push(op_r);
      push(op2);
      break;
    case '!': /* clear the stack */
      clear();
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
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}


/* getop: get next character or numeric operand */
int getop (char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
  }
  s[1] = '\0';
  i = 0;
  if (c == '-') {       /* this can be operator or negative number */
    c = getch();
    if (isdigit(c) || c == '.') {
      s[++i] = c;
    } else {
      ungetch(c);
      return s[0];
    }
  }
  if (!isdigit(c) && c != '.') {
    return c;           /* not a number */
  }
  if (isdigit(c)) {     /* collect integer part */
    while (isdigit(s[++i] = c = getch())) {
    }
  }
  if (c == '.') {       /* collect fraction part */
    while (isdigit(s[++i] = c = getch())) {
    }
  }
  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return GETOP_NUMBER;
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
