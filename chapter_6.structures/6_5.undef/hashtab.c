# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct nlist {   /* table entry: */
  struct nlist *next; /* next entry in chain */
  char *name;         /* defined name */
  char *defn;         /* replacement text */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash (char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup (char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;  /* found */
  return NULL;    /* not found */
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

/* install: put (name, defn) in hashtab */
struct nlist *install (char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else       /* already there */
    free((void *) np->defn);  /*free previous defn */
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

/* free_node: free the memory taken by nlist, including internal strings */
void free_node (struct nlist *np)
{
  free(np->name);
  free(np->defn);
  free(np);
}

/* undef: remove name from hashtab */
int undef (char *name)
{
  struct nlist *np, *prev;

  if ((np = hashtab[hash(name)]) != NULL) {
    if (strcmp(np->name, name) == 0) {
      hashtab[hash(name)] = np->next;
      free_node(np);
      return 1;
    } else {
      for (prev = np, np = np->next; np != NULL; prev = np, np = np->next)
        if (strcmp(name, np->name) == 0) {
          prev->next = np->next;
          free_node(np);
          return 1;
        }
    }
  }

  return 0;
}

/* print_hashtab: print hash table content */
void print_hashtab (void)
{
  int i;
  struct nlist *np;

  for (i = 0; i < HASHSIZE; i++)
    for (np = hashtab[i]; np != NULL; np = np->next)
      printf("[%d] '%s': '%s'\n", i, np->name, np->defn);
}
