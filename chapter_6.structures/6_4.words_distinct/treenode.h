# ifndef TREENODE_H
# define TREENODE_H

struct tnode {  /* the tree node: */
  char *word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

/* addtree: add a node with word at or below p */
struct tnode *addtree (struct tnode *p, char *word);
/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p);

/* addcntree: add a node with word at or below p, order by count */
struct tnode *addcntree (struct tnode *p, int count, char *word);
/* dict2count: change from dictionary order to count order, free old structures */
struct tnode *dict2count (struct tnode *dst, struct tnode *src);

# endif
