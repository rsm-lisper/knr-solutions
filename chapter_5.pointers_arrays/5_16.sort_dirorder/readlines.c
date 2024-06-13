# include <stdio.h>
# include <string.h>
# include "get_line.h"
# include "alloc.h"

# define MAXLEN 2000

int readlines (char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return nlines >= maxlines ? -1 : -2;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}
