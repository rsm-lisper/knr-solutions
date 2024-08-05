# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "knr_io.h"

KNR_FILE knr_iob[KNR_OPEN_MAX] = {    /* stdin, stdout, stderr */
  { 0, (char *) 0, (char *) 0, 0, 1, 0, 0, 0, 0 },
  { 0, (char *) 0, (char *) 0, 1, 0, 1, 0, 0, 0 },
  { 0, (char *) 0, (char *) 0, 2, 0, 1, 1, 0, 0 }
};

/* knr_fopen:  open file, return KNR_FILE* on success, KNR_NULL on error */
KNR_FILE *knr_fopen (char *name, char *mode)
{
  int fd;
  KNR_FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return KNR_NULL;
  for (fp = knr_iob; fp < knr_iob + KNR_OPEN_MAX; fp++)
    if (fp->f_read == 0 && fp->f_write == 0)
      break;              /* found free slot */
  if (fp >= knr_iob + KNR_OPEN_MAX)   /* no free slots */
    return KNR_NULL;

  if (*mode == 'w')
    fd = creat(name, KNR_PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, KNR_PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1)           /* couldn't access name */
    return KNR_NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = KNR_NULL;
  if (*mode == 'r')
    fp->f_read = 1;
  else
    fp->f_write = 1;
  return fp;
}

/* knr_fillbuf:  allocate and fill input buffer */
int knr_fillbuf (KNR_FILE *fp)
{
  int bufsize;

  if (fp->f_read == 0 || fp->f_eof == 1 || fp->f_err == 1)
    return KNR_EOF;
  bufsize = fp->f_unbuf==1 ? 1 : KNR_BUFSIZ;
  if (fp->base == KNR_NULL)         /* no buffer yet */
    if ((fp->base = (char*) malloc(bufsize)) == NULL)
      return KNR_EOF;                   /* can't get buffer */
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->f_eof = 1;
    else
      fp->f_err = 1;
    fp->cnt = 0;
    return KNR_EOF;
  }
  return (unsigned char) *fp->ptr++;
}

/* knr_flushbuf:  flush buffer (TODO LATER) */
int knr_flushbuf (int, KNR_FILE *)
{
  return 0;
}

/* knr_fclose:  close a stream, return 0 on success, KNR_EOF on error */
int knr_fclose (KNR_FILE *fp)
{
  int r;
  
  if ((r = close(fp->fd)) == -1)
    return KNR_EOF;
  fp->f_read = fp->f_write = fp->f_unbuf = fp->f_eof = fp->f_err = 0;
  return 0;
}
