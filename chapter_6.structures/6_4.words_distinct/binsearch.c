# include <string.h>

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch (char *word, char *tab[], int n)
{
  int cond;
  int low, high, mid;
  
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if ((cond = strcmp(word, tab[mid])) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
