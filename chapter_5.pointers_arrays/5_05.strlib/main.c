# include <stdio.h>
# include <string.h>
# include "strlib.h"

# define MAXSTR 128


void testcpy (char *s, char *ct, size_t n)
{
  char *my_ret, *lib_ret;
  char my_s[MAXSTR], lib_s[MAXSTR];

  strcpy(my_s, s);
  strcpy(lib_s, s);
  my_ret = str_ncpy(my_s, ct, n);
  lib_ret = strncpy(lib_s, ct, n);

  printf("str_ncpy(\"%s\",\n\t \"%s\",\n\t %ld) =>\n\t\"%s\"\n",
         s, ct, n, my_s);

  if (strcmp(my_ret, lib_ret) != 0) {
    printf("ERROR! str_ncpy return value different:\n"
           "\tMY: \"%s\"\n\tLIB: \"%s\"\n", my_ret, lib_ret);
  }
  if (strcmp(my_s, lib_s) != 0) {
    printf("ERROR! str_ncpy s value different:\n"
           "\tMY: \"%s\"\n\tLIB: \"%s\"\n", my_s, lib_s);
  }
}


void testcat (char *s, char *ct, size_t n)
{
  char *my_ret, *lib_ret;
  char my_s[MAXSTR], lib_s[MAXSTR];

  strcpy(my_s, s);
  strcpy(lib_s, s);
  my_ret = str_ncat(my_s, ct, n);
  lib_ret = strncat(lib_s, ct, n);

  printf("str_ncat(\"%s\",\n\t \"%s\",\n\t %ld) =>\n\t\"%s\"\n",
         s, ct, n, my_s);
  
  if (strcmp(my_ret, lib_ret) != 0) {
    printf("ERROR! str_ncat return value different:\n"
           "\tMY: \"%s\"\n\tLIB: \"%s\"\n", my_ret, lib_ret);
  }
  if (strcmp(my_s, lib_s) != 0) {
    printf("ERROR! str_ncat s value different:\n"
           "\tMY: \"%s\"\n\tLIB: \"%s\"\n", my_s, lib_s);
  }
}


void testcmp (char *cs, char *ct, size_t n)
{
  int my_ret, lib_ret;

  my_ret = str_ncmp(cs, ct, n);
  lib_ret = strncmp(cs, ct, n);
  
  printf("str_ncmp(\"%s\",\n\t \"%s\",\n\t %ld) =>\n\t%d\n",
         cs, ct, n, my_ret);

  if (my_ret != lib_ret) {
    printf("ERROR! str_ncmp return value different:\n"
           "\tMY: %d\n\tLIB: %d\n", my_ret, lib_ret);
  }
}


int main ()
{
  char s[MAXSTR];
  
  testcpy(s, "versions of", 0);
  testcpy(s, "versions of", 1);
  testcpy(s, "versions of", 10);
  testcpy(s, "versions of", 11);
  testcpy(s, "versions of", 12);
  testcpy(s, "the library functions", 100);

  testcat("version of", " the library.", 5);
  testcat("version of", " the library.", 50);
  testcat("version of", " the library.", 0);
  testcat("version of", " the library.", 12);
  testcat("version of", " the library.", 13);
  testcat("version of", " the library.", 14);

  testcmp("some", "", 0);
  testcmp("some", "", 1);
  testcmp("some", "s", 1);
  testcmp("some", "s", 2);
  testcmp("some", "s", 5);
  testcmp("versions OF", "versions of", 12);
  testcmp("versions OF", "versions of", 11);
  testcmp("versions OF", "versions of", 10);
  testcmp("versions OF", "versions of", 9);

  return 0;
}
