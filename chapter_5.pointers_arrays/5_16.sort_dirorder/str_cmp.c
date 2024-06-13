# include <ctype.h>

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


int str_ic_cmp (char *s, char *t)
{
  int i;
  for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
    if (s[i] == '\0')
      return 0;
  return toupper(s[i]) - toupper(t[i]);
}


int str_rev_ic_cmp (char *s, char *t)
{
  int i;
  for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
    if (s[i] == '\0')
      return 0;
  return toupper(t[i]) - toupper(s[i]);
}


static int isdict (char c) { return isalnum(c) || isspace(c); }


int str_dict_cmp (char *s, char *t)
{
  int s_was_dict = 0, t_was_dict = 0;
  while (*s != '\0' && *t != '\0') {
    if (!s_was_dict && *s == ' ')
      s++;
    else if (!(s_was_dict = isdict(*s)))
      s++;
    else if (!t_was_dict && *t == ' ')
      t++;
    else if (!(t_was_dict = isdict(*t)))
      t++;
    else if (*s == *t)
      s++, t++;
    else
      break;
  }
  return *s - *t;
}


int str_rev_dict_cmp (char *s, char *t)
{
  int s_was_dict = 0, t_was_dict = 0;
  while (*s != '\0' && *t != '\0') {
    if (!s_was_dict && *s == ' ')
      s++;
    else if (!(s_was_dict = isdict(*s)))
      s++;
    else if (!t_was_dict && *t == ' ')
      t++;
    else if (!(t_was_dict = isdict(*t)))
      t++;
    else if (*s == *t)
      s++, t++;
    else
      break;
  }
  return *t - *s;
}


int str_ic_dict_cmp (char *s, char *t)
{
  int s_was_dict = 0, t_was_dict = 0;
  while (*s != '\0' && *t != '\0') {
    if (!s_was_dict && *s == ' ')
      s++;
    else if (!(s_was_dict = isdict(*s)))
      s++;
    else if (!t_was_dict && *t == ' ')
      t++;
    else if (!(t_was_dict = isdict(*t)))
      t++;
    else if (toupper(*s) == toupper(*t))
      s++, t++;
    else
      break;
  }
  return toupper(*s) - toupper(*t);
}


int str_rev_ic_dict_cmp (char *s, char *t)
{
  int s_was_dict = 0, t_was_dict = 0;
  while (*s != '\0' && *t != '\0') {
    if (!s_was_dict && *s == ' ')
      s++;
    else if (!(s_was_dict = isdict(*s)))
      s++;
    else if (!t_was_dict && *t == ' ')
      t++;
    else if (!(t_was_dict = isdict(*t)))
      t++;
    else if (toupper(*s) == toupper(*t))
      s++, t++;
    else
      break;
  }
  return toupper(*t) - toupper(*s);
}
