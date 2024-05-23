# include <stdio.h>

# define MAXVAL 128 /* max depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */


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
