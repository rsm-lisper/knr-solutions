# include <stdio.h>
# include <string.h>
# include "getline.h"
# include "hashtab.h"

# define BUFSIZE 1024

int main ()
{
  char line[BUFSIZE], name[BUFSIZE], defn[BUFSIZE];

  while (getline(line, BUFSIZE) != -1)
    if (line[0] == '+') {
      int li = 2, ni = 0, di = 0;
      while (line[li] != ' ' && line[li] != '\0')
        name[ni++] = line[li++];
      if (line[li] == '\0') {
        printf("ERROR! unexpected end of line while reading definition");
        return 0;
      }
      name[ni] = '\0';
      li++;
      while (line[li] != '\0')
        defn[di++] = line[li++];
      defn[di] = '\0';
      install(name, defn);
    }
    else if (line[0] == '-') {
      int li = 2, ni = 0;
      while (line[li] != '\0')
        name[ni++] = line[li++];
      name[ni] = '\0';
      undef(name);
    } else {
      printf("unrecognised operation '%c', should be '+' or '-'.\n", line[0]);
      return 0;
    }

  print_hashtab();
  
  return 0;
}
