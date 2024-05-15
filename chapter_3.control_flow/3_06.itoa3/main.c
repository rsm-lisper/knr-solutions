# include <stdio.h>
# include <limits.h>
# include <string.h>

void itoa3 (int n, char s[], int l);
void reverse (char s[]);
void test_itoa3 (int n, int l);

# define MAXLEN 128


int main ()
{
  unsigned char l[] = {3, 6, 10, 14}, i;
  
  for (i = 0; i < 4; i++) {
    test_itoa3(0, l[i]);
    test_itoa3(1246283, l[i]);
    test_itoa3(-784632, l[i]);
    test_itoa3(INT_MAX, l[i]);
    test_itoa3(INT_MIN+1, l[i]);
    test_itoa3(INT_MIN, l[i]);
  }
  
  return 0;
}


void test_itoa3 (int n, int l)
{
  char s[MAXLEN];

  itoa3(n, s, l);
  printf("%d(%d): \"%s\"\n", n, l, s);
}


void itoa3 (int n, char s[], int l)
{
  int i, sign;
  unsigned int nn;

  if ((sign = n) < 0) {
    nn = -n;
  } else {
    nn = n;
  }
  i = 0;
  do {
    s[i++] = nn % 10 + '0';
  } while ((nn /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  while (i < l) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}


void reverse (char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
