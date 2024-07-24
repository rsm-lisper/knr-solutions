# include <stdio.h>
# include "minscanf.h"

int main ()
{
  int r;
  char type;

  if ((r = minscanf("type: %c", &type)) == EOF || r != 1) {
    printf("Error reading type. Format:\ntype t v0 v1 ... vn\nt - d: decimal int, f: float\n");
    return 0;
  }
  if (type == 'f') {
    float v;
    double sum = 0;
    while ((r = minscanf("%f", &v)) != EOF && r == 1)
      printf("\t%.2f\n", sum += v);
  }
  else if (type == 'd') {
    int v;
    long int sum = 0;
    while ((r = minscanf("%d", &v)) != EOF && r == 1)
      printf("\t%ld\n", sum += v);
  }
  else
    printf("ERROR! Unrecognized type %c.\n", type);
  
  return 0;
}
