# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <error.h>

# define BUFSIZE 1024

/* filecopy:  copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
  int n;
  char buf[BUFSIZE];
  while ((n = read(ifd, buf, BUFSIZE)) > 0)
    if (write(ofd, buf, n) != n)
      error(3, 0, "Write error on file ....\n");
}

/*   concatenate files   */
int main (int argc, char *argv[])
{
  int fd;
  
  if (argc == 1 ) /* no args; copy standard input */
    filecopy(0, 1);
  else
    while (--argc > 0) {
      if ((fd = open(*++argv, O_RDONLY)) < 0)
        error(1, 0, "Can't open file %s.\n", *argv);
      filecopy(fd, 1);
      close(fd);
    }

  return 0;
}
