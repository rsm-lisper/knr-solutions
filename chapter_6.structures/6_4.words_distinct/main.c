# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include "getword.h"
# include "treenode.h"
# include "binsearch.h"

char *noisewords[] = {
  "Also",  "Am",    "An",      "And",   "Are",   "As",   "At",    "Be",   "But",  "By",
  "Did",   "Do",    "For",     "Had",   "Has",   "Have", "In",    "Is",   "Isn",  "It",
  "Its",   "Nor",   "Not",     "Of",    "Off",   "On",   "Or",    "Out",  "So",   "Than",
  "That",  "The",   "Then",    "There", "These", "This", "Those", "To",   "Up",   "Was",
  "Wasn",  "When",    "With",  "Without", "Yet",
  "also",  "am",    "an",      "and",   "are",   "as",   "at",    "be",   "but",  "by",
  "d",     "did",   "do",      "for",   "had",   "has",  "have",  "in",   "is",   "isn",
  "it",    "its",   "m",       "nor",   "not",   "o",    "of",    "off",  "on",   "or",
  "out",   "p",     "re",      "s",     "so",    "t",    "than",  "that", "the",  "then",
  "there", "these", "this",    "those", "to",    "too",  "up",    "was",  "wasn", "when",
  "with",  "without", "yet"
};

# define NWORDS (int)(sizeof noisewords / sizeof(char *))
# define MAXWORD 128

/* word frequency count */
int main ()
{
  struct tnode *root = NULL, *cnroot = NULL;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]) && binsearch(word, noisewords, NWORDS) == -1)
      root = addtree(root, word);
  treeprint(dict2count(cnroot, root));

  return 0;
}
