
int str_cmp (char *s, char *t)
{
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}


int str_rev_cmp (char *s, char *t)
{
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return t[i] - s[i];
}
