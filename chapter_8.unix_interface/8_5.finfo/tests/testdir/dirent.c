# define _XOPEN_SOURCE

# include <error.h>
# include <errno.h>

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>     /* flags for read and write */
# include <sys/types.h> /* typedefs */
# include <sys/stat.h>  /* structure returned by stat */
# include <sys/dir.h>   /* local directory structure */
# include "dirent.h"


# ifndef DIRSIZ
# define DIRSIZ 14
# endif

/* opendir: open a directory for readdir calls */
KNR_DIR *knr_opendir (char *dirname)
{
  int fd;
  struct stat stbuf;
  KNR_DIR *dp;
  if ((fd = open(dirname, O_RDONLY, 0)) == -1
      || fstat(fd, &stbuf) == -1
      || (stbuf.st_mode & S_IFMT) != S_IFDIR
      || (dp = (KNR_DIR *) malloc(sizeof(KNR_DIR))) == NULL)
    return NULL;
  dp->fd = fd;
  return dp;
}

/* closedir: close directory opened by opendir */
void knr_closedir (KNR_DIR *dp)
{
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}

/* readdir: read directory entries in sequence */
KNR_Dirent *knr_readdir (KNR_DIR *dp)
{
  struct direct dirbuf; /* local directory structure */
  static KNR_Dirent d;      /* return: portable structure */

  ssize_t r;

  while ((r = read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0) /* slot not in use */
      continue;
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZ);
    d.name[DIRSIZ] = '\0'; /* ensure termination */
    return &d;
  }
  if (r == -1)
    error(-1, errno, "reading dir \"%s\"", dp->d.name);
  return NULL;
}

