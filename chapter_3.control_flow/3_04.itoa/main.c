# include <stdio.h>
# include <limits.h>
# include <string.h>

# define MAXLEN 128

void itoa (int n, char s[]);
void reverse (char s[]);
void test_itoa (int n);


int main()
{
  test_itoa(0);
  test_itoa(578678);
  test_itoa(-98173);
  test_itoa(INT_MAX);
  test_itoa(INT_MIN+1);
  test_itoa(INT_MIN);
  return 0;
}


void test_itoa (int n)
{
  char s[MAXLEN];

  itoa(n, s);
  printf("%d: %s\n", n, s);
}


void itoa (int n, char s[])
{
  int i, sign;
  unsigned int nn;

  if ((sign = n) < 0) { /* record sign */
    nn = -n;            /* make n positive */
  } else {
    nn = n;
  }
  i = 0;
  do { /* generate digits in reverse order */
    s[i++] = nn % 10 + '0'; /* get next digit */
  } while ((nn /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s); /* reverse digits order */
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
