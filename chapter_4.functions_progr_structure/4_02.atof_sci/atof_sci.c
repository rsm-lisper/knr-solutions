# include <ctype.h>


double powerd (double n, int pow)
{
  double ret = 1;

  if (pow > 0) {
    while (pow-- > 0) {
      ret *= n;
    }
  }
  else {
    while (pow++ < 0) {
      ret /= n;
    }
  }
  return ret;
}


double atof_sci (char s[])
{
  double val, power;
  int i, sign, esign, ev;

  for (i = 0; isspace(s[i]); i++) {
  }
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    esign = (s[i++] == '-') ? -1 : 1;
    for (ev = 0; isdigit(s[i]); i++) {
      ev = 10 * ev + (s[i] - '0');
    }
  } else {
    esign = 1;
    ev = 0;
  }
  return sign * val / power * powerd(10, esign * ev);
}
