# include "minprintf.h"

int main ()
{
  minprintf("int -100: %d\nuint 222: %u\nhex 1A: %x\ndouble -5.003: %f\nchar 'X': %c\n"
            "str \"KnR Solutions\": %s\n",
            (int) -100, (unsigned int) 222, (int) 26, (double) -5.003, (char) 'X',
            "KnR Solutions");
  return 0;
}
