# include <stdio.h>
# include "str_cat.h"

void test (char *s, char *t)
{
  printf("\"%s\" + \"%s\" = ", s, t);
  str_cat(s, t);
  printf("\"%s\"\n", s);
}


int main ()
{
  char s[128] = "Write";
  test(s, " a pointer");
  test(s, " version of the function");
  test(s, " strcat that we showed in chapter 2.");
  return 0;
}
