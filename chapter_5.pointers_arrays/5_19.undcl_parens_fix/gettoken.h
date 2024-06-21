# ifndef GETTOKEN_H
# define GETTOKEN_H

# define MAXTOKEN 1024

enum {NAME, PARENS, BRACKETS};

extern int tokentype; /* type of last token */
extern char token[MAXTOKEN]; /* last token string */

/* gettoken: return next token */
int gettoken (void);

# endif
