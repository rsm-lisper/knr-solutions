# include <stdio.h>
# include <stddef.h>

int get_line (char *s, int lim)
{
  int c;
  char *s0 = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return c == EOF ? -1 : s - s0;
}
