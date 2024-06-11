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
  int help = 0; /* 1 if display help */
  int numeric = 0; /* 1 if numeric sort */
  int reverse = 0; /* 1 if reverse order sort */
  int fold = 0; /* 1 if fold upper and lower case together */
  int c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'h': help = 1; break;
      case 'n': numeric = 1; break;
      case 'r': reverse = 1; break;
      case 'f': fold = 1; break;
      default:
        printf("error: unrecognized option %c (-h for help)\n", c);
        return 1;
      }
  if (help) {
    printf("Syntax: %s <options>\n"
           "Options:\n"
           "\t-n\tnumeric sort\n"
           "\t-r\treverse order sort\n"
           "\t-f\tfold upper and lower case together\n"
           "\t-h\tdisplay this help message\n", bin);
    return 0;
  }
  if (numeric && fold) {
    printf("Option -f can't be combined with -n\n");
    return 3;
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void**) lineptr, 0, nlines-1,
          (int (*)(void*, void*))
          (numeric && reverse ?           num_rev_cmp :
           numeric && !reverse ?          num_cmp :
           !numeric && reverse && fold ?  str_rev_ic_cmp :
           !numeric && reverse && !fold ? str_rev_cmp :
           !numeric && !reverse && fold ? str_ic_cmp :
           str_cmp)); /* !numeric && !reverse && !fold */
    writelines(lineptr, nlines);
    return 0;
  }

  switch (nlines) {
  case -1: printf("error: too many lines\n"); break;
  case -2: printf("error: not enough memory\n"); break;
  default: printf("internal error\n");
  }
  return 2;
}
