
/*
  strend:
    returns 1 if the string t occurs at the end of the string s,
    and zero otherwise
*/
int strend (char *s, char *t)
{
  char *ts = s, *tt = t;
  while (*ts++ != '\0')
    ;
  ts--;
  while (*tt++ != '\0')
    ;
  tt--;
  while (s <= ts && t <= tt && *ts == *tt) {
    ts--;
    tt--;
  }
  return tt < t;
}
