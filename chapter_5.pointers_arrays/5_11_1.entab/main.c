# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "entab.h"


int main (int argc, char *argv[])
{
  unsigned char tabsize = 8;

  if ((argc > 1) && (argc != 3 ||
                     strcmp(argv[1], "-t") != 0 ||
                     (tabsize = atoi(argv[2])) < 1))
    printf("Syntax: entab -t <tabsize>\n");
  else
    entab(tabsize);

  return 0;
}
