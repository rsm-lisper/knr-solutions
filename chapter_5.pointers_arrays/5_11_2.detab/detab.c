# include <stdio.h>


void detab (unsigned char tabsize)
{
  int c, t;

  t = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      while (t < tabsize) {
	printf(" ");
	t++;
      }
      t = 0;
    }
    else {
      if (c == '\n')
	t = 0;
      else
	t = (t + 1) % tabsize;
      printf("%c", c);
    }
  }
}
