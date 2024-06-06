# include <stdio.h>
# include <string.h>
# include "readlines.h"
# include "writelines.h"
# include "qsort.h"
# include "num_cmp.h"
# include "str_cmp.h"

# define MAXLINES 5000 /* max number of lines */
char *lineptr[MAXLINES]; /* pointers to lines of text */

int main (int argc, char *argv[])
{
  char *bin = argv[0];
  int nlines; /* number of lines read */
  int numeric = 0; /* 1 if numeric sort */
  int reverse = 0; /* 1 if reverse order sort */
  int c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'n': numeric = 1; break;
      case 'r': reverse = 1; break;
      default:
        printf("error: unrecognized option %c\n", c);
        argc = 0;
        break;
      }
  if (argc != 0) {
    printf("Syntax: %s -n -r\n", bin);
    return 1;
  }
  else if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void**) lineptr, 0, nlines-1,
          (int (*)(void*, void*)) (numeric && reverse ? num_rev_cmp :
                                   numeric && !reverse ? num_cmp :
                                   !numeric && reverse ? str_rev_cmp :
                                   str_cmp));
    writelines(lineptr, nlines);
    return 0;
  }
  else {
    switch (nlines) {
    case -1: printf("error: too many lines\n"); break;
    case -2: printf("error: not enough memory\n"); break;
    default: printf("internal error\n");
    }
    return 2;
  }
}
