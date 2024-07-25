# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* file_open: open a file, and handle errors */
FILE *file_open (char *name, char *mode, char *prog)
{
  FILE *fp;
  if ((fp = fopen(name, mode)) == NULL) {
    fprintf(stderr, "%s ERROR! Can't open %s.\n", prog, name);
    exit(1);
  }
  return fp;
}

/* fgetline: read a line from a file, return length */
int fgetline (FILE *fp, char *line, int max)
{
  return
    fgets(line, max, fp) == NULL ?
    0 : strlen(line);
}

# define MAXLINE 1024

int main (int argc, char **argv)
{
  FILE *fp0, *fp1;
  char line0[MAXLINE], line1[MAXLINE];
  int len0, len1, n;
  
  if (argc != 3) {
    printf("%s syntax: <file-a> <file-b>\n", argv[0]);
    return 0;
  }
  fp0 = file_open(argv[1], "r", argv[0]);
  fp1 = file_open(argv[2], "r", argv[0]);

  n = -1;
  do {
    n++;
    len0 = fgetline(fp0, line0, MAXLINE);
    len1 = fgetline(fp1, line1, MAXLINE);
  } while (len0 > 0 && len1 > 0 && len0 == len1 && strcmp(line0, line1) == 0);

  if (len0 != len1 || strcmp(line0, line1) != 0)
    printf("Files differ, line %d:\n"
           "%s: %s\n"
           "%s: %s\n",
           n,
           argv[1], len0 == 0 ? "[EOF]" : line0,
           argv[2], len1 == 0 ? "[EOF]" : line1);

  fclose(fp0);
  fclose(fp1);
  return 0;
}
