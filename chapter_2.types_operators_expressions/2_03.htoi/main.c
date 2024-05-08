
# include <stdio.h>

int con1 (int c);


int main ()
{
  int c,
    d = 0,
    n = 0;

  if ((c = getchar()) == '0') {
    if ((c = getchar()) != 'X' && c != 'x') {
      d = con1(c);
    }
  }
  else {
    d = con1(c);
  }
  if (d != -1) {
    n = d;
  }
  
  while (d != -1 && (c = getchar()) != EOF) {
    if ((d = con1(c)) != -1) {
      n = n * 16 + d;
    }
  }
  printf("%d\n", n);

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
