# ifndef HASHTAB_H
# define HASHTAB_H

/* lookup: look for s in hashtab */
struct nlist *lookup (char *s);
/* install: put (name, defn) in hashtab */
struct nlist *install (char *name, char *defn);
/* undef: remove name from hashtab */
int undef (char *name);
/* print_hashtab: print hash table content */
void print_hashtab (void);

# endif
