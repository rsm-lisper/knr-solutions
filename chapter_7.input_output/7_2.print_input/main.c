# include <stdio.h>
# include <ctype.h>

# define LINESIZE 24
# define LINEBLOCK 4

int main ()
{
  int c, col = 0;
  char line[LINESIZE+1];

  while ((c = getchar()) != EOF) {
    if (col == LINESIZE) {
      line[col] = '\0';
      printf("| %s\n", line);
      col = 0;
    }
    line[col++] = isgraph(c) ? c : '.';
    printf(col % LINEBLOCK == 0 ? "%02x  " : "%02x ", c);
  }
  line[col] = '\0';
  while (col < LINESIZE)
    printf(++col % LINEBLOCK == 0 ? "    " : "   ");
  printf("| %s\n", line);
  
  return 0;
}
