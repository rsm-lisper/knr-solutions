
# include <stdio.h>

# define INBLANK 1
# define NOTINBLANK 0

int main ()
{
  int c, status = NOTINBLANK;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (status == NOTINBLANK) {
	printf("%c", c);
	status = INBLANK;
      }
    }
    else {
      status = NOTINBLANK;
      printf("%c", c);
    }
  }
}
