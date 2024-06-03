# include <stdio.h>


static void despace (int spaces)
{
  while (spaces--)
    putchar(' ');
}


void entab (unsigned char tabsize)
{
  int c, t = 0, spaces = 0;
  
  while ((c = getchar()) != EOF) {
    if (spaces) {
      if (c == ' ') {
	spaces++;
	t++;
	if (t == tabsize) {
	  t = spaces = 0;
	  printf("\t");
	}
      }
      else {
	if (c == '\n')
	  t = 0;
	else
	  t = (t+1) % tabsize;
	despace(spaces);
	spaces = 0;
	printf("%c", c);
      }
    }
    else { /* spaces == 0 */
      if (c == ' ') {
	spaces++;
	t++;
	if (t == tabsize) {
	  t = spaces = 0;
	  printf(" ");
	}
      }
      else {
	if (c == '\n')
	  t = 0;
	else
	  t = (t+1) % tabsize;
	printf("%c", c);
      }
    }
  }
}
