# include <stdio.h>
# include <limits.h>
# include <string.h>

void itob (int n, char s[], unsigned char b);
void reverse (char s[]);
void test_itob (int n, unsigned char b);


int main ()
{
  unsigned char b[] = {2, 5, 8, 10, 16}, i;
  
  for (i = 0; i < 5; i++) {
    test_itob(0, b[i]);
    test_itob(1246283, b[i]);
    test_itob(-784632, b[i]);
    test_itob(INT_MAX, b[i]);
    test_itob(INT_MIN+1, b[i]);
    test_itob(INT_MIN, b[i]);
  }
  
  return 0;
}


void test_itob (int n, unsigned char b)
{
  char s[128];

  itob(n, s, b);
  printf("%d(%d): %s\n", n, b, s);
}


void itob (int n, char s[], unsigned char b)
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
    if ((nn % b) > 9) {
      s[i++] = nn % b - 10 + 'a';
    } else {
      s[i++] = nn % b + '0';
    }
  } while ((nn /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
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
