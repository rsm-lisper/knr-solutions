
# include <stdio.h>

int main ()
{
  int c, nc[256], q, w;

  for (q = 0; q < 256; q++) {
    nc[q] = 0;
  }

  while ((c = getchar()) != EOF) {
    nc[c]++;
  }

  printf("  Char    Count\n---------------\n");
  for (q = 0; q < 256; q++) {
    if (nc[q] > 0) {
      if (q >= ' ' && q <= '~') {
        printf("%3d [%c]: %2d ", q, q, nc[q]);
      }
      else {
        printf("%3d ---: %2d ", q, nc[q]);
      }
      for (w = 0; w < nc[q]; w++) {
        printf("#");
      }
      printf("\n");
    }
  }

  return 0;
}
