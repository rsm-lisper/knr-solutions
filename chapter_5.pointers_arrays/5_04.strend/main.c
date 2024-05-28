# include <stdio.h>
# include "strend.h"


void test (char *s, char *t)
{
  printf("strend(\"%s\", \"%s\") => %d\n", s, t, strend(s, t));
}


int main ()
{
  char s[] = "Write the function";

  test(s, "");
  test(s, "n");
  test(s, "x");
  test(s, "nn");
  test(s, "ion");
  test(s, "enction");
  test(s, "Write");
  test(s, "1. Write the function");
  test(s, " Write the function");
  test(s, "Write the function");
  test(s, "function");
  test(s, " function");
  test(s, "ite the function");

  return 0;
}
