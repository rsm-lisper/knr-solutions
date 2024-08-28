# define _DEFAULT_SOURCE

# include <stdio.h>
# include <string.h>
# include <sys/types.h> /* typedefs */
# include <sys/stat.h>  /* structure returned by stat */
# include <dirent.h>
# include <time.h>

/*
  you can't read a directory like a file in modern system. so no manual "dirent.h"
 */

# define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk (char *dir, void (*fcn)(char *))
{
  char name[MAX_PATH];
  struct dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
      continue;    /* skip self and parent */
    if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->d_name);
    else {
      sprintf(name, "%s/%s", dir, dp->d_name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}

/* finfo: print the name of file "name" */
void finfo (char *name)
{
  struct stat stbuf;
  char *ftype, fbits[4] = "---", fmode[10] = "---------";
# ifdef FULL_VER
  char mtime[64];
# endif

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "finfo: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, finfo);

  if      (S_ISREG (stbuf.st_mode)) ftype = "FILE";
  else if (S_ISDIR (stbuf.st_mode)) ftype = " DIR";
  else if (S_ISCHR (stbuf.st_mode)) ftype = "CDEV";
  else if (S_ISBLK (stbuf.st_mode)) ftype = "BDEV";
  else if (S_ISFIFO(stbuf.st_mode)) ftype = "PIPE";
  else if (S_ISLNK (stbuf.st_mode)) ftype = "LINK";
  else if (S_ISSOCK(stbuf.st_mode)) ftype = "SOCK";
  else                              ftype = "(\?\?)";

  if (stbuf.st_mode & S_ISUID) fbits[0] = 'u';
  if (stbuf.st_mode & S_ISGID) fbits[1] = 'g';
  if (stbuf.st_mode & S_ISVTX) fbits[2] = 's';

  if (stbuf.st_mode & S_IRUSR) fmode[0] = 'r';
  if (stbuf.st_mode & S_IWUSR) fmode[1] = 'w';
  if (stbuf.st_mode & S_IXUSR) fmode[2] = 'x';
  if (stbuf.st_mode & S_IRGRP) fmode[3] = 'r';
  if (stbuf.st_mode & S_IWGRP) fmode[4] = 'w';
  if (stbuf.st_mode & S_IXGRP) fmode[5] = 'x';
  if (stbuf.st_mode & S_IROTH) fmode[6] = 'r';
  if (stbuf.st_mode & S_IWOTH) fmode[7] = 'w';
  if (stbuf.st_mode & S_IXOTH) fmode[8] = 'x';

# ifdef FULL_VER
  strftime(mtime, sizeof(mtime), "%Y/%m/%d %H:%M:%S", localtime(&stbuf.st_mtim.tv_sec));
    
  printf("%4s %4d:%4d %3s %9s %s %8ld %2lu %s\n",
         ftype, stbuf.st_uid, stbuf.st_gid, fbits, fmode, mtime,
         stbuf.st_size, stbuf.st_nlink, name);
# else
  printf("%4s %3s %9s %8ld %2lu %s\n",
         ftype, fbits, fmode, stbuf.st_size, stbuf.st_nlink, name);
# endif
}

/* print file name */
int main (int argc, char **argv)
{
  if (argc == 1) /* default: current directory */
    finfo(".");
  else
    while (--argc > 0)
      finfo(*++argv);
  return 0;
}
