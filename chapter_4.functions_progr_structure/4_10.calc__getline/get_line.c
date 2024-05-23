# include <stdio.h>

int get_line (char s[], int lim)
{
  int c, i;
  
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  if (i == 0 && c == EOF) {
    i = EOF;
  }
  
  return i;
}
