# include <stdio.h>
# include <ctype.h>
# include "getch.h"

/*
  Our version of getword does not properly handle underscores, string
  constants, comments, or preprocessor control lines. Write a better version.
*/

int ignore_nonwords ()
{
  int c = getch();

  /* ignore white spaces */
  if (isspace(c)) {
    while (isspace(c = getch()))
      ;
    ungetch(c);
    return 1;
  }

  /* ignore character constants */
  if (c == '\'') {
    do {
      if ((c = getch()) == '\\') {
        getch();
        c = getch();
      }
    } while (c != '\'' && c != EOF);
    return 1;
  }

  /* ignore string constants */
  if (c == '"') {
    do {
      if ((c = getch()) == '\\') {
        getch();
        c = getch();
      }
    } while (c != '"' && c != EOF);
    return 1;
  }

  /* ignore preprocessor commands */
  if (c == '#') {
    while ((c = getch()) != EOF && c != '\n')
      if ((c = getch()) == '\\') {
        if ((c = getch()) == '\n')
          c = getch();
        else
          ungetch(c);
      }
    return 1;
  }

  /* ignore comments */
  if (c == '/') {
    if ((c = getch()) == '*') {
      while (c != EOF)
        if ((c = getch()) == '*') {
          if ((c = getch()) == '/')
            break;
          else
            ungetch(c);
        }
      return 1;
    }
    else
      ungetch(c);
  }

  /* ignore numbers */
  if (isdigit(c)) {
    while (isdigit(c = getch()) || c == '.')
      ;
    ungetch(c);
    return 1;
  }

  ungetch(c);
  return 0;
}

/* getword: get next word or character from input */
int getword (char *word, int lim)
{
  int c;
  char *w = word;

  while (ignore_nonwords())
    ;
  
  if ((c = getch()) != EOF)
    *w++ = c;  
  if (!isalpha(c) && c!='_') {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch()) && *w!='_') {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
