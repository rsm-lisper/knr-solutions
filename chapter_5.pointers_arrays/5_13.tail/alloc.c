# include "alloc.h"

static char allocbuf[ALLOCSIZE]; /* memory for alloc */
static char *allocp = allocbuf; /* next free position */


/* alloc: return pointer to the memory n chars long */
char *alloc (int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* enough memory */
    allocp += n;
    return allocp - n; /* return old value of allocp */
  }
  else /* not enough memory */
    return 0;
}

/* afree: free the memory p */
void afree (char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
