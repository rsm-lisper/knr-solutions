# include <stdio.h>
# include "swap.h"

int main ()
{
  char c0 = '0', c1 = '1';
  int i0 = 10, i1 = 222;

  printf("char: '%c', '%c' => '", c0, c1);
  swap(char, c0, c1);
  printf("%c', '%c'\n", c0, c1);
  printf("int: %d, %d => ", i0, i1);
  swap(int, i0, i1);
  printf("%d, %d\n", i0, i1);

  return 0;
}
