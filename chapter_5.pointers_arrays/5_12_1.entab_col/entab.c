# include <stdio.h>


static void despace (int spaces)
{
  while (spaces--)
    putchar(' ');
}


void entab (unsigned int tabsize, unsigned int tabstart)
{
  int c;
  unsigned int ts = 0, t = 0, spaces = 0;
  
  while ((c = getchar()) != EOF) {
    if (ts < tabstart) {
      if (c == '\n')
        ts = 0;
      else
        ts++;
      putchar(c);
    }
    else if (spaces) {
      if (c == ' ') {
	spaces++;
	t++;
	if (t == tabsize) {
	  t = spaces = 0;
	  putchar('\t');
	}
      }
      else {
	if (c == '\n')
	  t = ts = 0;
	else
	  t = (t+1) % tabsize;
	despace(spaces);
	spaces = 0;
	putchar(c);
      }
    }
    else { /* spaces == 0 */
      if (c == ' ') {
	spaces++;
	t++;
	if (t == tabsize) {
	  t = spaces = 0;
	  putchar(' ');
	}
      }
      else {
	if (c == '\n')
	  t = ts = 0;
	else
	  t = (t+1) % tabsize;
	putchar(c);
      }
    }
  }
}
