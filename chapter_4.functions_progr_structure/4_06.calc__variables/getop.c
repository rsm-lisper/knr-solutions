# include <stdio.h>
# include <ctype.h>

# include "getop.h"
# include "getch.h"


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
