
int itoa (int n, char *str)
{
  int r = 0, sign = 0;
  
  if (n < 0) {
    sign = 1;
    str[0] = '-';
    n = -n;
  }
  
  if (n / 10) {
    r = itoa(n / 10, str + sign);
  }
  str[r + sign] = n % 10 + '0';
  str[r + sign + 1] = '\0';
  return r + sign + 1;
}
