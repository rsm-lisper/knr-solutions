# include <stdio.h>
# include <error.h>
# include <stdlib.h>
# include "knr_io.h"


int main (int argc, char *argv[])
{
  KNR_FILE *fp;
  int i, c, pos, len;
  
  if (argc < 4)
    printf("Usage: %s <file> <pos1> <len1> ... <posN> <lenN>\n", argv[0]);
  else {
    if ((fp = knr_fopen(*++argv, "r")) == KNR_NULL)
      error(1, 0, "Can't open file %s.", *argv);
    argc--;
    while (argc > 1) {
      argc -= 2;
      pos = atoi(*++argv);
      len = atoi(*++argv);
      if (knr_fseek(fp, pos, KNR_SEEK_SET) != 0)
        error(2, 0, "Can't seek to position %d.", pos);
      for (i = 0; i < len; i++) {
        if ((c = knr_getc(fp)) == KNR_EOF)
          error(3, 0, "End of file reached while reading.");
        knr_putchar(c);
      }
    }
    if (knr_fclose(fp) != 0)
      error(4, 0, "Can't close file %s.", *argv);
    knr_putchar('\n');
  }
  knr_fflush(knr_stdout);
  knr_fflush(knr_stderr);

  return 0;
}
