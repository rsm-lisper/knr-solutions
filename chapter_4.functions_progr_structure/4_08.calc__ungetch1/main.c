# include <stdio.h>
# include <stdlib.h> /* for atof */
# include <string.h> /* strcmp */
# include <math.h>

# include "stack.h"
# include "getop.h"
# include "vars.h"

# define MAXOP 128    /* max size of operand or operator */


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
