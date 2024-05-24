# include <stdio.h>
# include <string.h> /* strlen */

# define MAXLINE 1024

int strrindex (char s[], char t[]);
int get_line (char s[], int lim);

char pattern[] = "one";


int main ()
{
  char line[MAXLINE];
  int i;

  while (get_line(line, MAXLINE) > 0) {
    if ((i = strrindex(line, pattern)) >= 0) {
      printf("Pattern \"%s\" found at position %d:\n%s\n", pattern, i, line);
    }
  }
  return 0;
}


int strrindex (char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s)-1; i >= 0; i--) {
    for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
    }
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}


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
  
  return i;
}
