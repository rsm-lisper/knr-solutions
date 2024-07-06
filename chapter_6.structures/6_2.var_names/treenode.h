# ifndef TREENODE_H
# define TREENODE_H

struct tnode {  /* the tree node: */
  char *word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

/* addtree: add a node with w, at or below p */
struct tnode *addtree (struct tnode *p, char *w);
/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p, unsigned int group_by);

# endif
