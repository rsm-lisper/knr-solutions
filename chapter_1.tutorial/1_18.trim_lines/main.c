# include <stdio.h>

# define BEGOFLINE 0
# define INSIDELINE 1


int main ()
{
  int c, state = BEGOFLINE;
  
  while ((c = getchar()) != EOF) {
    if (state == BEGOFLINE) {
      if (c != ' ' && c != '\t' && c != '\n') {
	state = INSIDELINE;
	printf("%c", c);
      }
    }
    else {
      if (c == '\n') {
	state = BEGOFLINE;
      }
      printf("%c", c);
    }
  }
  
  return 0;
}
