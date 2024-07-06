# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include "getword.h"
# include "treenode.h"
# include "binsearch.h"

char *keytab[] = {
  "auto", "break", "case", "char", "const", "continue", "default", "do",
  "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
  "long", "register", "return", "short", "signed", "sizeof", "static",
  "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
  "while"
};

# define NKEYS (int)(sizeof keytab / sizeof(char *))
# define MAXWORD 128
# define DEFAULT_GROUP_BY 6

/* word frequency count */
int main (int argc, char *argv[])
{
  struct tnode *root = NULL;
  char word[MAXWORD];

  char *bin = argv[0];
  int group_by = DEFAULT_GROUP_BY;
  
  if (argc == 2) {
    if (atoi(argv[1]))
      group_by = atoi(argv[1]);
    else {
      printf("Wrong parameter 1: %s\n"
             "Syntax: %s <n>\n"
             "\tn:\tGroup by the first n characters (default %d).\n",
             argv[1], bin, DEFAULT_GROUP_BY);
      return 0;
    }
  }

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]) && binsearch(word, keytab, NKEYS) == -1)
      root = addtree(root, word);
  treeprint(root, group_by);
  putchar('\n');
  
  return 0;
}
