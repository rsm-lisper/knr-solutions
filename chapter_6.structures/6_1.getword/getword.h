# ifndef GETWORD_H
# define GETWORD_H

/* getch: get a (possibly pushed-back) character */
int getch (void);
/* ungetch: push character back on input */
void ungetch (int c);

/* getword: get next word or character from input */
int getword (char *word, int lim);

# endif
