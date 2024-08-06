# include <stdio.h>
# include <error.h>
# include "knr_io.h"


int main (int argc, char *argv[])
{
  KNR_FILE *fp;
  int c;
  
  if (argc == 1)
    printf("Usage: %s <file1> <...fileN>\n", argv[0]);
  else
    while (--argc > 0) {
      if ((fp = knr_fopen(*++argv, "r")) == KNR_NULL)
        error(1, 0, "Can't open file %s.", *argv);
      while ((c = knr_getc(fp)) != KNR_EOF)
        knr_putchar(c);
      if (knr_fclose(fp) != 0)
        error(2, 0, "Can't close file %s.", *argv);
    }
  knr_fflush(knr_stdout);
  knr_fflush(knr_stderr);

  return 0;
}
