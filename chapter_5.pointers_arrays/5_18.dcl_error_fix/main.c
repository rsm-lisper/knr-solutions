# include <stdio.h>
# include <string.h>
# include "dcl.h"
# include "gettoken.h"

/* convert declaration to words */
int main ()
{
  while (gettoken() != EOF) { /* 1st token on line */
    strcpy(datatype, token);  /* is the datatype */
    out[0] = '\0';
    dcl(); /* parse rest of line */
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s:%s %s\n", name, out, datatype);
  }
  return 0;
}
