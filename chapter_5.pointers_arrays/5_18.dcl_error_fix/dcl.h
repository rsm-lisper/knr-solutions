# ifndef DCL_H
# define DCL_H

# define MAXOUT 1024

extern char name[]; /* identifier name */
extern char datatype[]; /* data type = char, int, etc. */
extern char out[];

/* dcl: parse declarator */
void dcl (void);
/* dirdcl: parse a direct declarator */
void dirdcl (void);

# endif
