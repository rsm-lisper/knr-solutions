
# include <stdio.h>

# define TSIZE 8

void despace (int spaces);


int main ()
{
  int c, t = 0, spaces = 0;
  
  while ((c = getchar()) != EOF) {
    if (spaces) {
      if (c == ' ') {
	spaces++;
	t++;
	if (t == TSIZE) {
	  t = spaces = 0;
	  printf("\t");
	}
      }
      else {
	if (c == '\n') {
	  t = 0;
	}
	else {
	  t = (t+1) % TSIZE;
	}
	despace(spaces);
	spaces = 0;
	printf("%c", c);
      }
    }
    else { /* spaces == 0 */
      if (c == ' ') {
	spaces++;
	t++;
	if (t == TSIZE) {
	  t = spaces = 0;
	  printf(" ");
	}
      }
      else {
	if (c == '\n') {
	  t = 0;
	}
	else {
	  t = (t+1) % TSIZE;
	}
	printf("%c", c);
      }
    }
  }
  
  return 0;
}


void despace (int spaces)
{
  while (spaces > 0) {
    spaces--;
    printf(" ");
  }
}
