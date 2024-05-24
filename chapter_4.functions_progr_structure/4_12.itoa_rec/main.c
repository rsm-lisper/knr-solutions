# include <stdio.h>
# include <limits.h>
# include "itoa.h"

void test_itoa (int n)
{
  char str[128];
  int r = itoa(n, str);
  printf("itoa(%d) => \"%s\" (r:%d)\n", n, str, r);
}

int main ()
{
  test_itoa(-5);
  test_itoa(0);
  test_itoa(1);
  test_itoa(45);
  test_itoa(777);
  test_itoa(-65);
  test_itoa(-333);
  test_itoa(12345);
  test_itoa(-98765);
  test_itoa(INT_MIN+1);
  test_itoa(INT_MAX);
  return 0;
}
