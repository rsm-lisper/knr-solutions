# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>

unsigned int readushort ();
void print_binary (unsigned int i);

unsigned int rightrot (unsigned short x, unsigned short n);


int main ()
{
  unsigned short x, n, res;
  
  x = readushort();
  n = readushort();
  res = rightrot(x, n);
  printf("%u [", res);
  print_binary(res);
  printf("]\n");
  
  return 0;
}


unsigned int rightrot (unsigned short x, unsigned short n)
{
  unsigned short rot_mask = ~1, rot_part, rot_part_ready;

  /* cut part to move to the left */
  rot_mask = rot_mask >> (16 - n);
  rot_part = x & rot_mask;
  rot_part_ready = rot_part << (16 - n);
  /* rotate everything to the right by n */
  x = x >> n;
  /* paste part moved to the left */
  x = x | rot_part_ready;

  return x;
}


unsigned int readushort ()
{
  char* line;
  size_t len;
  unsigned short val;

  line = NULL;
  len = 0;
  getline(&line, &len, stdin);
  val = (unsigned short) atoi(line);
  free(line);

  return val;
}


void print_binary (unsigned int i)
{
  if (i >> 1) print_binary(i >> 1);
  putchar((i & 1) ? '1' : '0');
}
