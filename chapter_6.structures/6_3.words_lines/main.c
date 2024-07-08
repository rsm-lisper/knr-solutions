# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include "getword.h"
# include "treenode.h"
# include "binsearch.h"

char *noisewords[] = {
  "and",
  "the"
};

# define NWORDS (int)(sizeof noisewords / sizeof(char *))
# define MAXWORD 128

/* word frequency count */
int main ()
{
  struct tnode *root = NULL;
  int lnumber = 0;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    if (word[0] == '\n')
      lnumber++;
    if (isalpha(word[0]) && binsearch(word, noisewords, NWORDS) == -1)
      root = addtree(root, word, lnumber);
  }
  treeprint(root);

  return 0;
}
