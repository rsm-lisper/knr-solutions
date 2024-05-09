# include <stdio.h>

int main ()
{
  int c;
  
  printf("(getchar() != EOF): ");
  if ((c = getchar()) != EOF) {
    printf("true [1]");
  }
  else {
    printf("false [0]");
  }
  printf(".\n");
  return 0;
}

/* NOTE: Use CTRL+D (unix) or CTRL+Z (win) to send 'End Of File' */
