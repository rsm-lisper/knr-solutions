# ifndef ALLOC_H
# define ALLOC_H

# define ALLOCSIZE 1000000 /* size of the memory */

/* alloc: return pointer to the memory n chars long */
char *alloc (int n) ;

/* afree: free the memory p */
void afree (char *p) ;

# endif
