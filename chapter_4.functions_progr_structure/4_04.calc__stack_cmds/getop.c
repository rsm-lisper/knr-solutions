# include <stdio.h>
# include <ctype.h>

# include "getop.h"
# include "getch.h"


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

