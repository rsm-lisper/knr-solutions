
# include <stdio.h>

int get_line (char line[], int maxline);
void reverse (char to[], char from[]);

# define MAXLINE 1024


int main ()
{
  int len;
  char line[MAXLINE];
  char revline[MAXLINE];
  
  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(revline, line);
    printf("%s", revline);
  }
}


int get_line (char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}


void reverse (char to[], char from[])
{
  int len, f, t;

  for (len = 0; from[len] != '\0'; len++) {}
  to[len] = '\0';
  if (len > 0 && from[len-1] == '\n') {
    to[--len] = '\n';
  }
  for (f = 0, t = len-1; t >= 0; f++, t--) {
    to[t] = from[f];
  }
}
