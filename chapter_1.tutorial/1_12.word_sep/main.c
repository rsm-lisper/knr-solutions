# include <stdio.h>

# define INWORD 1
# define NOTINWORD 0


int main ()
{
  int c, state = NOTINWORD;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == INWORD) {
	state = NOTINWORD;
	printf("\n");
      }
    }
    else {
      if (state == NOTINWORD) {
	state = INWORD;
      }
      printf("%c", c);
    }
  }

  return 0;
}
