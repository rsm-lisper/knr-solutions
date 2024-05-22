# include <stdio.h>
# include <stdlib.h> /* for atof */

# include "stack.h"
# include "getop.h"

# define MAXOP 128    /* max size of operand or operator */


/* reverse Polish calculator */
int main ()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
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
