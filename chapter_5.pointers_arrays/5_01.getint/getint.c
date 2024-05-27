# include <stdio.h>
# include <ctype.h>
# include "getch.h"

/*
  getint: get next integer from input to *pn
  return:
   - 0 when it's not a number
   - EOF when read ok and EOF reached
   - positive integer when read ok
*/
int getint (int *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (! isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    if (! isdigit(c = getch())) {
      ungetch(c);
      ungetch(sign ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
