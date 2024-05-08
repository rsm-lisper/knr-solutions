
# include <stdio.h>

int con1 (int c);


int main ()
{
  int c, d, number;

  if ((c = getchar()) == '0') {
    if ((c = getchar()) == 'X' || c == 'x') {
      c = getchar();
    }
  }

  d = number = 0;
  while (d != -1 && c != EOF) {
    if ((d = con1(c)) != -1) {
      number = number * 16 + d;
      c = getchar();
    }
  }
  printf("%d\n", number);

  return 0;
}


int con1 (int c)
{
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }
  else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  }
  else
    return -1;
}
