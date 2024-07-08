# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include "treenode.h"


/* lnalloc: make tlnumbernode */
struct tlnumbernode *lnalloc (void)
{
  return (struct tlnumbernode *) malloc(sizeof(struct tlnumbernode));
}

/* talloc: make a tnode */
struct tnode *talloc (void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

/* make a duplicate of s */
char *strdup (char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

struct tlnumbernode *addlnumer (struct tlnumbernode *next, unsigned int lnumber)
{
  struct tlnumbernode *node = lnalloc();
  node->lnumber = lnumber;
  node->next = next;
  return node;
}

void lnumbersprint (struct tlnumbernode *ln)
{
  struct tlnumbernode *l0 = ln;
  while (ln) {
    printf(ln == l0 ? " %d" : ", %d", ln->lnumber);
    ln = ln->next;
  }
}

/* addtree: add a node with word and line_number, at or below p */
struct tnode *addtree (struct tnode *p, char *word, unsigned int lnumber)
{
  int cond;

  if (p == NULL) {    /* a new word has arrived */
    p = talloc();     /* make a new node */
    p->word = strdup(word);
    p->lnumbers = addlnumer(NULL, lnumber);
    p->left = p->right = NULL;
  } else if ((cond = strcmp(word, p->word)) == 0) {
    struct tlnumbernode *ln = p->lnumbers;
    while (ln->next)
      ln = ln->next;
    if (ln->lnumber != lnumber)
      ln->next = addlnumer(NULL, lnumber);       /* repeated word */
  } else if (cond < 0)  /* less than into left subtree */
    p->left = addtree(p->left, word, lnumber);
  else                /* greater than into right subtree */
    p->right = addtree(p->right, word, lnumber);
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%s:", p->word);
    lnumbersprint(p->lnumbers);
    printf("\n");
    treeprint(p->right);
  }
}
