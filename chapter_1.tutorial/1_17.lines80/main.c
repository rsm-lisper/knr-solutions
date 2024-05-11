# include <stdio.h>

# define MAXLINE 256
# define PRINTLEN 80

int get_line (char line[], int maxline);


int main ()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > PRINTLEN) {
      printf("%s", line);
      if (len > MAXLINE) {
	printf("(...)\n");
      }
    }
  }

  return 0;
}


int get_line (char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < lim-1) {
      s[i] = c;
    }
  }
  
  if (i < lim-1) {
    if (c == '\n') {
      s[i] = c;
      i++;
    }
    s[i] = '\0';
  }
  else {
    if (c == '\n') {
      i++;
    }
    s[lim-1] = '\0';
  }
  
  return i;
}
