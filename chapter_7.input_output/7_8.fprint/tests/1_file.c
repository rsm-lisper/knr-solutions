# include <stdio.h>
# include <stdlib.h>

# define MAXLINE 1024
# define PAGE_LINES 25

/* print set of files, starting each new one on a new page,
   with a title and a running page count for each file. */
int main (int argc, char **argv)
{
  char line[MAXLINE], *prog = argv[0];
  FILE *fp;
  unsigned int n;
  
  while (--argc > 0) {
    if ((fp = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "%s: Can't open file %s.\n", prog, *argv);
      exit(1);
    }
    n = 0;
    while (fgets(line, MAXLINE, fp) != NULL) {
      if (n % PAGE_LINES == 0)
        printf("---[ File: %s, Page: %u ]---------------------------\n",
               *argv, n / PAGE_LINES + 1);
      if (fputs(line, stdout) == EOF) {
        fprintf(stderr, "%s: Error writing to stdout.\n", prog);
        exit(2);
      }
      n++;
    }
    fclose(fp);
  }
  return 0;
}
