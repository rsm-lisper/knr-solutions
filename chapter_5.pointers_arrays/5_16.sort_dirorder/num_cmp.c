# include <stdlib.h>

int num_cmp (char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}


int num_rev_cmp (char *s1, char *s2)
{
  double v1 = atof(s1), v2 = atof(s2);
  if (v1 > v2)
    return -1;
  else if (v1 < v2)
    return 1;
  else
    return 0;
}
