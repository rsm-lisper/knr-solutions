# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* file_open: open a file, and handle errors */
FILE *file_open (char *name, char *mode, char *prog)
{
  FILE *fp;
  if ((fp = fopen(name, mode)) == NULL) {
    fprintf(stderr, "%s ERROR! Can't open %s.\n", prog, name);
    exit(1);
  }
  return fp;
}

/* fgetline: read a line from a file, return length */
