
# include <stdio.h>

float fahr2cels (int fahr);


int main ()
{
  float fahr;
  int lower = 0, upper = 300, step = 20;

  printf("Fahr.  Celsius\n");
  printf("-[F]-----[C]--\n");

  fahr = lower;
  while (fahr <= upper) {
    printf(" %3.0f  %6.1f\n", fahr, fahr2cels(fahr));
    fahr = fahr + step;
  }
}


float fahr2cels (int fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}
