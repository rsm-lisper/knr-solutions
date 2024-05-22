# include <stdio.h>
# include <stdbool.h>

char buf;
int bufp = false; /* does buffer have a content? */


/* getch: get a (possibly pushed-back) character */
int getch (void)
{
  if (bufp) {
    bufp = false;
    return buf;
  } else {
    return getchar();
  }
}


/* ungetch: push character back on input */
void ungetch (int c)
{
  if (bufp) {
    printf("ungetch: buffer already taken\n");
  } else {
    buf = c;
    bufp = true;
  }
}
