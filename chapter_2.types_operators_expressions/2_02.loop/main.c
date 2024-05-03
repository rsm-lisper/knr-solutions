
# include <stdio.h>

# define LIM 128


int main ()
{
  int i, c;
  char s[LIM];

  i = 0;
  while (i < LIM-1) {
    c = getchar();
    if (c == '\n')
      break;
    if (c == EOF)
      break;

    s[i++] = c;
  }

  if (c == '\n')
    s[i++] = '\n';
  s[i++] = '\0';
  fputs(s, stdout);
  
  return 0;
}
