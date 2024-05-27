# include <stdio.h>
# include "getfloat.h"

int main ()
{
  int r;
  float n;

  for (r = getfloat(&n); r != EOF && r != 0; r = getfloat(&n)) {
    printf("float read: %f\n", n);
  }
  if (r == EOF) {
    printf("(EOF)\n");
  } else {
    printf("not a number\n");
  }

  return 0;
}
