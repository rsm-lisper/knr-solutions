# ifndef TREENODE_H
# define TREENODE_H

struct tlnumbernode {
  unsigned int lnumber;
  struct tlnumbernode *next;
};
  
struct tnode {  /* the tree node: */
  char *word;          /* points to the text */
  struct tlnumbernode *lnumbers; /* */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

/* addtree: add a node with word and line_number, at or below p */
struct tnode *addtree (struct tnode *p, char *word, unsigned int line_nb);

/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p);

# endif
