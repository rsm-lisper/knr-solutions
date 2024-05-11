# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>

unsigned int readuint ();
int bitcount (unsigned int x);


int main ()
{
  unsigned int x;
  int res;

  x = readuint();
  res = bitcount(x);
  printf("%d\n", res);
  
  return 0;
}


int bitcount (unsigned int x)
{
  int b = 0;
  while (x != 0) {
    b++;
    x &= x-1;
  }
  return b;
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
