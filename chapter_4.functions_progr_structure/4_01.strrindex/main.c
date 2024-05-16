# include <stdio.h>
# include "get_line.h"
# include "strrindex.h"

# define MAXLINE 1024

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
