# include <stdio.h>
# include "get_line.h"
# include "atof_sci.h"

# define MAXLINE 1024

int main()
{
  char line[MAXLINE];

  if (get_line(line, MAXLINE) > 0) {
    printf("%lf\n", atof_sci(line));
  }
  
  return 0;
}
