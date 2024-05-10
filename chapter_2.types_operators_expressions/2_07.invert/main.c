# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>

unsigned int invert (unsigned int x, unsigned int p, unsigned int n);
unsigned int readuint ();
void print_binary (unsigned int i);


int main ()
{
  unsigned int x, p, n, res;

  x = readuint();
  p = readuint();
  n = readuint();
  res = invert(x, p, n);
  printf("%u [", res);
  print_binary(res);
  printf("]\n");
  
  return 0;
}


unsigned int invert (unsigned int x, unsigned int p, unsigned int n)
{
  unsigned int invall_x, mask_x, inv_part, unchanged_x;

  invall_x = ~x;
  mask_x = (~(~0 << n) << (p - n + 1));
  inv_part = invall_x & mask_x;
  unchanged_x = x & (~mask_x);
  return unchanged_x | inv_part;
}


unsigned int readuint ()
{
  char* line;
  size_t len;
  unsigned int val;

  line = NULL;
  len = 0;
  getline(&line, &len, stdin);
  val = (unsigned int) atoi(line);
  free(line);

  return val;
}


void print_binary (unsigned int i)
{
  if (i >> 1) print_binary(i >> 1);
  putchar((i & 1) ? '1' : '0');
}
