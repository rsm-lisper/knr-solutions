# ifndef GETCH_H
# define GETCH_H

/* getch: get a (possibly pushed-back) character */
int getch (void);
/* ungetch: push character back on input */
void ungetch (int c);

# endif
