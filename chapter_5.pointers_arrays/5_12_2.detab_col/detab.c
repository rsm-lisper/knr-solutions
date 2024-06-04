# include <stdio.h>

void detab (unsigned char tabsize, unsigned char tabstart)
{
  int c, t = 0, ts = 0;

  while ((c = getchar()) != EOF) {
    if (ts < tabstart) {
      if (c == '\n')
        ts = 0;
      else
        ts++;
      putchar(c);
    }
    else if (c == '\t') {
      while (t < tabsize) {
	putchar(' ');
	t++;
      }
      t = 0;
    }
    else {
      if (c == '\n')
	t = ts = 0;
      else
	t = (t + 1) % tabsize;
      putchar(c);
    }
  }
}
