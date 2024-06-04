# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "detab.h"


int main (int argc, char *argv[])
{
  char *bin = argv[0];
  unsigned int tabstart = 0, tabsize = 8, err = 0;

  while (--argc > 0)
    if ((*++argv)[0] == '-') {
      if ((tabstart = atoi((*argv)+1)) == 0) {
        printf("tabstart (%s) must be >0\n", (*argv)+1);
        err = 1;
      }
    }
    else if ((*argv)[0] == '+') {
      if ((tabsize = atoi((*argv)+1)) == 0) {
        printf("tabsize (%s) must be >0\n", (*argv)+1);
        err = 1;
      }
    }
    else {
      printf("unrecognised option %s\n", *argv);
      err = 1;
    }
  if (err) {
    printf("Syntax: %s -m +n\n\t-m : tabs start at column m\n\t+n : tab stops every n columns (starting at column m)\n", bin);
    return 1;
  }
  detab(tabsize, tabstart);
  
  return 0;
}
