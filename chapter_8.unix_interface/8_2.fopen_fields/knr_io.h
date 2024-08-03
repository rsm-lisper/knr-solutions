# ifndef KNR_IO_H
# define KNR_IO_H

# define KNR_PERMS 0666 /* RW for owner, group, others */

# define KNR_NULL     0
# define KNR_EOF      (-1)
# define KNR_BUFSIZ   1024
# define KNR_OPEN_MAX 20 /* max #files open at once */

typedef struct knr_iobuf {
  int   cnt;   /* characters left */
  char *ptr;   /* next character position */
  char *base;  /* location of buffer */
  int   fd;    /* file descriptor */
  /* mode of file access: */
  int   f_read;  /* file open for reading */   
  int   f_write; /* file open for writing */
  int   f_unbuf; /* file is unbuffered */
  int   f_eof;   /* EOF has occurred on this file */
  int   f_err;   /* error occurred on this file */
} KNR_FILE;
extern KNR_FILE knr_iob[KNR_OPEN_MAX];

# define knr_stdin   (&knr_iob[0])
# define knr_stdout  (&knr_iob[1])
# define knr_stderr  (&knr_iob[2])

/* knr_fopen:  open file, return KNR_FILE* on success, KNR_NULL on error */
KNR_FILE *knr_fopen (char *name, char *mode);
/* knr_fillbuf:  allocate and fill input buffer */
int knr_fillbuf (KNR_FILE *fp);
/* knr_flushbuf:  flush buffer */
int knr_flushbuf (int, KNR_FILE *);
/* knr_fclose:  close a stream, return 0 on success, KNR_EOF on error */
int knr_fclose (KNR_FILE *fp);

# define knr_feof(p)    ((p)->flag & KNR_EOF) != 0)
# define knr_ferror(p)  ((p)->flag & KNR_ERR) != 0)
# define knr_fileno(p)  ((p)->fd)

# define knr_getc(p)    (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : knr_fillbuf(p))
# define knr_putc(x,p)  (--(p)->cnt >= 0 ? *(p)->ptr++ = (x)           : knr_flushbuf((x),p))
# define knr_getchar()  knr_getc(knr_stdin)
# define knr_putchar(x) knr_putc((x), knr_stdout)

# endif
