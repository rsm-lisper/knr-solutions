# include <stdio.h>
# include <ctype.h>
# include <string.h>

# define TOUPPER "conv_upper"
# define TOLOWER "conv_lower"

int main (int argc, char **argv)
{
  int c, up;
  char *name;

  name = strchr(argv[0], '/');
  name = name==NULL ? argv[0] : name+1;
  
  if (argc > 1)
    printf("WARNING! %s does not support arguments.\n", name);

  if (strcmp(name, TOUPPER) == 0)
    up = 1;
  else if (strcmp(name, TOLOWER) == 0)
    up = 0;
  else {
    printf("ERROR! Unrecognized binary name '%s'. Should be '%s' or '%s'.\n",
           name, TOUPPER, TOLOWER);
    return 0;
  }
  
  while ((c = getchar()) != EOF) {
    if (isalpha(c))
      c = up ? toupper(c) : tolower(c);
    putchar(c);
  }
  
  return 0;
}
