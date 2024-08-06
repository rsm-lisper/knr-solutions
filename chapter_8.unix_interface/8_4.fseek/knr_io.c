# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "knr_io.h"

enum knr_flags {
  KNR_FREAD  = 01,  /* file open for reading */
  KNR_FWRITE = 02,  /* file open for writing */
  KNR_FUNBUF = 04,  /* file is unbuffered */
  KNR_FEOF   = 010, /* EOF has occurred on this file */
  KNR_FERR   = 020, /* error occurred on this file */
  KNR_FWL    = 030  /* wrote less then buffer size */
};

KNR_FILE knr_iob[KNR_OPEN_MAX] = {    /* stdin, stdout, stderr */
  { 0, (char *) 0, (char *) 0, KNR_FREAD, 0 },
  { 0, (char *) 0, (char *) 0, KNR_FWRITE, 1 },
  { 0, (char *) 0, (char *) 0, KNR_FWRITE | KNR_FUNBUF, 2 }
};

/* knr_fopen:  open file, return KNR_FILE* on success, KNR_NULL on error */
KNR_FILE *knr_fopen (char *name, char *mode)
{
  int fd;
  KNR_FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return KNR_NULL;
  for (fp = knr_iob; fp < knr_iob + KNR_OPEN_MAX; fp++)
    if ((fp->flag & (KNR_FREAD | KNR_FWRITE)) == 0)
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
  fp->flag = (*mode == 'r') ? KNR_FREAD : KNR_FWRITE;
  return fp;
}

/* knr_fillbuf:  allocate and fill input buffer */
int knr_fillbuf (KNR_FILE *fp)
{
  int bufsize;

  if ((fp->flag & (KNR_FREAD | KNR_FEOF | KNR_FERR)) != KNR_FREAD)
    return KNR_EOF;
  bufsize = (fp->flag & KNR_FUNBUF) ? 1 : KNR_BUFSIZ;
  if (fp->base == KNR_NULL)         /* no buffer yet */
    if ((fp->base = (char*) malloc(bufsize)) == NULL)
      return KNR_EOF;                   /* can't get buffer */
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag |= KNR_FEOF;
    else
      fp->flag |= KNR_FERR;
    fp->cnt = 0;
    return KNR_EOF;
  }
  return (unsigned char) *fp->ptr++;
}

/* knr_flushbuf:  flush output buffer, store c, return c on success, KNR_EOF on error */
int knr_flushbuf (int c, KNR_FILE *fp)
{
  int bufsize;
  
  if ((fp->flag & (KNR_FWRITE | KNR_FEOF | KNR_FERR)) != KNR_FWRITE)
    return KNR_EOF;
  bufsize = (fp->flag & KNR_FUNBUF) ? 1 : KNR_BUFSIZ;
  if (fp->base == KNR_NULL) {       /* no buffer yet */
    if ((fp->base = (char*) malloc(bufsize)) == NULL)
      return KNR_EOF;
  }
  else {
    fp->cnt = write(fp->fd, fp->base, fp->ptr - fp->base);
    if (fp->cnt < fp->ptr - fp->base) {
      if (fp->cnt == -1)
        fp->flag |= KNR_FWL;
      fp->flag |= KNR_FERR;
      return KNR_EOF;
    }
  }
  fp->ptr = fp->base;
  fp->cnt = bufsize - 1;
  return *fp->ptr++ = c;
}

/* knr_fflush:  flush stream, return 0 on success, KNR_EOF on error */
int knr_fflush (KNR_FILE *fp)
{
  int bufsize;

  if ((fp->flag & (KNR_FEOF | KNR_FERR)) != 0)
    return KNR_EOF;
  bufsize = (fp->flag & KNR_FUNBUF) ? 1 : KNR_BUFSIZ;
  if ((fp->flag & KNR_FWRITE) == KNR_FWRITE) { /* output stream */
    if (fp->base == KNR_NULL)        /* no buffer yet */
      return 0;
    else {
      fp->cnt = write(fp->fd, fp->base, fp->ptr - fp->base);
      if (fp->cnt < fp->ptr - fp->base) {
        if (fp->cnt == -1)
          fp->flag |= KNR_FWL;
        fp->flag |= KNR_FERR;
        return KNR_EOF;
      }
      fp->ptr = fp->base;
      fp->cnt = bufsize;
    }
  }
  else if ((fp->flag & KNR_FREAD) == KNR_FREAD) { /* input stream */
    if (fp->base == KNR_NULL)        /* no buffer yet */
      return 0;
    fp->ptr = fp->base;
    fp->cnt = 0;
  }
  else
    return KNR_EOF;

  return 0;
}

/* knr_fseek:  set the file position for the stream, return 0 on success, KNR_EOF on error */
int knr_fseek (KNR_FILE *fp, long offset, int origin)
{
  int whence;
  
  if (knr_fflush(fp) != 0)
    return KNR_EOF;
  switch (origin) {
  case KNR_SEEK_SET: whence = SEEK_SET; break;
  case KNR_SEEK_CUR: whence = SEEK_CUR; break;
  case KNR_SEEK_END: whence = SEEK_END; break;
  default: return KNR_EOF;
  }
  if (lseek(fp->fd, offset, whence) == -1) {
    fp->flag |= KNR_FERR;
    return KNR_EOF;
  }
  return 0;
}

/* knr_fclose:  close a stream, return 0 on success, KNR_EOF on error */
int knr_fclose (KNR_FILE *fp)
{
  if ((fp->flag & (KNR_FWRITE | KNR_FEOF | KNR_FERR)) == KNR_FWRITE)
    if (knr_fflush(fp) != 0)
      return KNR_EOF;
  if (close(fp->fd) == -1)
    return KNR_EOF;
  free(fp->base);
  fp->flag = 0;
  return 0;
}
