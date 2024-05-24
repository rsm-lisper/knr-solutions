# include <stdio.h>
# include <ctype.h>

double atof_sci (char s[]);
double powerd (double n, int pow);
int get_line (char s[], int lim);

# define MAXLINE 1024


int main()
{
  char line[MAXLINE];

  if (get_line(line, MAXLINE) > 0) {
    printf("%lf\n", atof_sci(line));
  }
  
  return 0;
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


int get_line (char s[], int lim)
{
  int c, i;
  
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  
  return i;
}
