
# include <stdio.h>

# define TSIZE 8


int main ()
{
  int c, t;

  t = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      while (t < TSIZE) {
	printf(" ");
	t++;
      }
      t = 0;
    }
    else {
      if (c == '\n') {
	t = 0;
      }
      else {
	t = (t + 1) % TSIZE;
      }
      printf("%c", c);
    }
  }

  return 0;
}
