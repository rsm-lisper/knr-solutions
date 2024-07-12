# include <stdio.h>

int getline (char *line, int lim)
{
  int c;
  char *l0 = line;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *line++ = c;
  *line = '\0';

  return c == EOF ? -1 : line - l0;
}
