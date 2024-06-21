# include <stdio.h>
# include <string.h>

# include "gettoken.h"

# define MAXOUT 1024

char out[MAXOUT];

/* undcl: convert word descriptions to declarations */
int main ()
{
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if (type == '*') {
        if (strlen(out)+1+3 > sizeof(temp))
          strcat(out, "internal error #0");
        else {
          strcpy(temp, "(*");
          strcat(temp, out);
          strcat(temp, ")");
          strcpy(out, temp);
        }
      }
      else if (type == NAME) {
        if (strlen(temp)+1 > sizeof(temp)) {
          strcat(out, "internal error #1");
        }
        else if (strlen(out) + strlen(token) + 1 > sizeof(temp)) {
          strcat(out, "internal error #2");
        }
        else {
          strcpy(temp, token);
          strcat(temp, " ");
          strcat(temp, out);
          strcpy(out, temp);
        }
      }
      else
        printf("invalid input at %s\n", token);
    printf("%s\n", out);
  }
  return 0;
}
