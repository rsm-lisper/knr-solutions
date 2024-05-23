# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>

# include "getop.h"
# include "get_line.h"

# define GETOP_MAXLINE 256

char line[GETOP_MAXLINE];
int lsize, lpos, first_run = true;


/* getop: get next character, numeric operand or function/command */
int getop (char s[])
{
  int c, i;

  if (first_run || line[lpos] == '\0') {
    first_run = false;
    if ((lsize = get_line(line, GETOP_MAXLINE)) == EOF) {
      return EOF;
    } else {
      lpos = 0;
    }
  }
  
  /* skip leading white space. c and s[0] will contain first character */
  while ((s[0] = c = line[lpos++]) == ' ' || c == '\t') {
  }

  if (c == '\n') {
    return c;
  }
  /* operator, single digit number or single letter symbol */
  if ((s[1] = c = line[lpos++]) == ' ' || c == '\t' || c == '\n') {
    lpos--;
    s[1] = '\0';
    c = s[0];
    /* single digit number */
    if (isdigit(c)) {
      return GETOP_NUMBER;
    }
    /* one letter symbol [a-zA-Z] */
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
    lpos--;
    c = s[0];
    /* number */
    if (isdigit(c) || c == '-' || c == '.') {
      i = 0;
      if (c == '-') { /* move by a minus (-) sign */
	s[++i] = c = line[lpos++];
      }
      if (isdigit(c)) { /* collect integer part */
	while (isdigit(s[++i] = c = line[lpos++])) {
	}
      }
      if (c == '.') { /* collect fraction part */
	while (isdigit(s[++i] = c = line[lpos++])) {
	}
      }
      s[i] = '\0';
      lpos--;
      return GETOP_NUMBER;
    }
    /* symbol */
    else {
      i = 0;
      while ((s[++i] = c = line[lpos++]) != ' ' && c != '\t' && c != '\n') {
      }
      s[i] = '\0';
      lpos--;
      return GETOP_SYMBOL;
    }
  }
}
