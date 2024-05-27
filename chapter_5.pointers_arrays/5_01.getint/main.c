# include <stdio.h>
# include "getint.h"

int main ()
{
  int n, r;
  
  for (r = getint(&n); r != EOF && r != 0; r = getint(&n)) {
    printf("int read: %d\n", n);
  }
  if (r == EOF) {
    printf("(EOF)\n");
  } else {
    printf("not a number\n");
  }

  return 0;
}
