# include <stdio.h>
# include <string.h>
# include "reverse.h"

void test(char s[])
{
  char srev[256];
  strcpy(srev, s);
  reverse(srev);
  printf("reverse(\"%s\") => \"%s\"\n", s, srev);
}

int main ()
{
  test("");
  test("a");
  test("ab");
  test("abc");
  test("abcd");
  test("12345");
  test("123456");
  test("1234567");
  test("12345678");
  test("a b c.");
  test("1 2 3 4 5 | 6 7 8 9 0");
  return 0;
}
