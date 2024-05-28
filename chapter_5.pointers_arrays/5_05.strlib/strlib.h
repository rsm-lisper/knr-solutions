# ifndef STRLIB_H
# define STRLIB_H

# include <stddef.h>

/* str_ncpy: copy at most n characters of string ct to s; return s.
   Pad with '\0's if ct has fewer than n characters. */
char *str_ncpy (char *s,char *ct, size_t n);
/* str_ncat: concatenate at most n characters of string ct to string s,
   terminate s with '\0'; return s. */
char *str_ncat (char *s, char *ct, size_t n);
/* str_ncmp: compare at most n characters of string cs to string ct;
   return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct. */
int str_ncmp (char *cs, char *ct, size_t n);

# endif
