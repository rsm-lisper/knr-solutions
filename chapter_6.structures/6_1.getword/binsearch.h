# ifndef BINSEARCH_H
# define BINSEARCH_H

struct key {
  char *word;
  int count;
};

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch (char *word, struct key tab[], int n);

# endif
