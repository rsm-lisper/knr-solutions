# include <string.h>

static void rev_rec (char s[], int b, int e)
{
  if (b < e) {
    char c = s[b];
    s[b] = s[e];
    s[e] = c;
    rev_rec(s, b+1, e-1);
  }
}


void reverse (char s[])
{
  rev_rec(s, 0, strlen(s) - 1);
}
