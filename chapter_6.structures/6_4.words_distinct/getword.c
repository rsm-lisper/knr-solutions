# include <stdio.h>
# include <ctype.h>
# include <string.h>

# define BUFSIZE 128

int buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */


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


/* getword: get next word or character from input */
int getword (char *word, int lim)
{
  int c;
  char *w = word;

  while ((c = getch()) != EOF && !isalpha(c))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
