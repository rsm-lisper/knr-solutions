# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>

unsigned int setbits (unsigned int x, unsigned int p, unsigned int n, unsigned int y);
unsigned int readuint ();
void print_binary (unsigned int i);


int main ()
{
  unsigned int x, p, n, y, result;

  x = readuint();
  p = readuint();
  n = readuint();
  y = readuint();
  result = setbits(x, p, n, y);
  printf("%u [", result);
  print_binary(result);
  printf("]\n");
  return 0;
}


unsigned int setbits (unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
  unsigned int bits_y, bits_x, mask_x;
  
  bits_y = y & ~(~0 << n);
  mask_x = ~(~(~0 << n) << (p - n + 1));
  bits_x = bits_y << (p - n + 1);
  x = (x & mask_x) | bits_x;
  
  return x;
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
