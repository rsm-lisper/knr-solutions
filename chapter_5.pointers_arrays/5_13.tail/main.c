# include <stdio.h>
# include <stdlib.h>
# include "readlines.h"

# define MAXLINES 5000 /* max number of lines */
# define DEF_LASTN 10 /* number of lines to print by default */

char *lineptr[MAXLINES]; /* pointers to lines of text */

int main (int argc, char *argv[])
{
  int lastn = DEF_LASTN; /* number of lines to print */
  int nlines; /* number of lines read */

  if (argc == 2)
    if (*(++argv)[0] != '-' || (lastn = atoi((*argv)+1)) == 0) {
      printf("Syntax: tail -n\n\tn\tprint last n lines, %d by default\n", DEF_LASTN);
      return 1;
    }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    int l;
    for (l = (nlines-lastn < 0 ? 0 : nlines-lastn); l < nlines; l++)
      printf("%s\n", lineptr[l]);
  }
  else {
    switch (nlines) {
    case -1: printf("error: too many lines\n"); break;
    case -2: printf("error: not enough memory\n"); break;
    default: printf("internal error\n");
    }
    return 2;
  }
  return 0;
}
