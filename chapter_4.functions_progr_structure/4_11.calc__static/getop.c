# include <stdio.h>
# include <ctype.h>

# include "getop.h"

# define BUFEMPTY -111

/* getop: get next character, numeric operand or function/command */
int getop (char s[])
{
  int i, c;
  static int buf = BUFEMPTY;

  /* \n from buffer */
  if (buf == '\n') {
    buf = BUFEMPTY;
    return '\n';
  }
  /* skip white space character in buffer */
  if (buf == BUFEMPTY || buf == ' ' || buf == '\t') {
    buf = BUFEMPTY;
    s[0] = c = getchar();
  }
  /* get character from buffer */
  else {
    s[0] = c = buf;
    buf = BUFEMPTY;
  }
  /* skip leading white spaces */
  while (c == ' ' || c == '\t') {
    s[0] = c = getchar();
  }

  if (c == EOF || c == '\n') {
    return c;
  }
  /* operator, single digit number or single letter symbol */
  if ((s[1] = c = getchar()) == ' ' || c == '\t' || c == '\n' || c == EOF) {
    buf = c;
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
    buf = c;
    c = s[0];
    /* number */
    if (isdigit(c) || c == '-' || c == '.') {
      i = 0;
      if (c == '-') { /* move by a minus (-) sign */
	s[++i] = c = buf;
	buf = BUFEMPTY;
      }
      if (isdigit(c)) { /* collect integer part */
	if (buf != BUFEMPTY) {
	  s[++i] = c = buf;
	  buf = BUFEMPTY;
	} else {
	  s[++i] = c = getchar();
	}
	while (isdigit(c)) {
	  s[++i] = c = getchar();
	}
      }
      if (c == '.') { /* collect fraction part */
	if (buf != BUFEMPTY) {
	  s[++i] = c = buf;
	  buf = BUFEMPTY;
	} else {
	  s[++i] = c = getchar();
	}
	while (isdigit(c)) {
	  s[++i] = c = getchar();
	}
      }
      s[i] = '\0';
      buf = c;
      return GETOP_NUMBER;
    }
    /* symbol */
    else {
      i = 0;
      s[++i] = buf;
      buf = BUFEMPTY;
      while ((s[++i] = c = getchar()) != ' ' && c != '\t' && c != '\n' && c != EOF) {
      }
      s[i] = '\0';
      buf = c;
      return GETOP_SYMBOL;
    }
  }
}
