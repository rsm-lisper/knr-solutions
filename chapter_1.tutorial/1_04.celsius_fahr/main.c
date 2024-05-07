
# include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = -20, -10, 0, ..., 150; floating-point version */
int main ()
{
  float celsius, fahr;
  int lower, upper, step;

  lower = -20;  /* lower limit of temperature scale */
  upper = 150;  /* upper limit */
  step = 10;    /* step size */

  printf("Celsius Fahr.\n");
  printf("--[C]----[F]--\n");
  
  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("  %3.0f    %3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
