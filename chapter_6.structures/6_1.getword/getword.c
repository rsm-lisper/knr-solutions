# include <stdio.h>
# include <ctype.h>

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
