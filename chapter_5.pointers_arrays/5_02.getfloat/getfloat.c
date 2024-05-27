# include <stdio.h>
# include <ctype.h>
# include <math.h>
# include "getch.h"

/*
  getfloat: get next floating-point number from input into *pn
  return:
   - 0 when it's not a number
   - EOF when read ok and EOF reached
   - positive integer when read ok
*/
int getfloat (float *pn)
{
  int c, sign;
  unsigned int d;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (! isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    if (! isdigit(c = getch()) && c != '.') {
      ungetch(c);
      ungetch(sign ? '+' : '-');
      return 0;
    }
  }
  *pn = 0;
  while (isdigit(c)) {
    *pn = 10 * *pn + (c - '0');
    c = getch();
  }
  if (c == '.') {
    d = 0;
    while (isdigit(c = getch())) {
      *pn = 10 * *pn + (c - '0');
      d++;
    }
    *pn /= pow(10.0, d);
  }
  if (*pn != 0)
    *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
