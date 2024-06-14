# include <string.h>
# include <ctype.h>

# include "gettoken.h"
# include "dcl.h"
# include "getch.h"

int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */

/* ignspaces: ignore white space characters (' ', '\t') */
void ignspaces (void)
{
  int c;
  while ((c = getch()) == ' ' || c == '\t')
    ;
  ungetch(c);
}

/* gettoken: return next token */
int gettoken (void)
{
  int c;
  char *p = token;

  ignspaces();
  if ((c = getch()) == '(') {
    ignspaces();
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    }
    else {
      ungetch(c);
      return tokentype = '(';
    }
  }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  }
  else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  }
  else
    return tokentype = c;
}
