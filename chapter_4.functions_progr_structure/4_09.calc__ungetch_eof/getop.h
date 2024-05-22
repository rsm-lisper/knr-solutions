# ifndef GETOP_H
# define GETOP_H

# define GETOP_NUMBER '0'   /* signal that a number was found */
# define GETOP_SYMBOL 'a'   /* signal that a symbol was found */

/* getop: get next character, numeric operand or function/command */
int getop (char s[]);

# endif
