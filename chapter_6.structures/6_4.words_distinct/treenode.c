# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include "treenode.h"

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

/* addtree: add a node with word at or below p */
struct tnode *addtree (struct tnode *p, char *word)
{
  int cond;

  if (p == NULL) {    /* a new word has arrived */
    p = talloc();     /* make a new node */
    p->word = strdup(word);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(word, p->word)) == 0)
    p->count++;       /* repeated word */
  else if (cond < 0)  /* less than into left subtree */
    p->left = addtree(p->left, word);
  else                /* greater than into right subtree */
    p->right = addtree(p->right, word);
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%d %s\n",p->count, p->word);
    treeprint(p->right);
  }
}

/* addcntree: add a node with word at or below p, order by count */
struct tnode *addcntree (struct tnode *p, int count, char *word)
{
  int cond;

  if (p == NULL) {    /* a new word has arrived */
    p = talloc();     /* make a new node */
    p->count = count;
    p->word = strdup(word);
    p->left = p->right = NULL;
  } else if ((cond = strcmp(word, p->word)) == 0 && count==p->count)
    p->count = -1;    /* repeated count and word? */
  else if (count > p->count || (count == p->count && cond < 0))  /* less than into left subtree */
    p->left = addcntree(p->left, count, word);
  else                /* greater than into right subtree */
    p->right = addcntree(p->right, count, word);
  return p;
}

/* dict2count: change from dictionary order to count order, free old structures */
struct tnode *dict2count (struct tnode *dst, struct tnode *src)
{
  if (src != NULL) {
    dst = dict2count(dst, src->left);
    dst = addcntree(dst, src->count, src->word);
    free(src->word);
    dst = dict2count(dst, src->right);
    free(src);
  }
  return dst;
}
