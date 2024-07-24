# include <stdio.h>
# include <stdarg.h>

/* minscanf: minimal scanf with variable argument list */
int minscanf (char *fmt, ...)
{
  va_list ap; /* points to each annamed arg in turn */
  char *p;
  int c, sr, r = 0;

  va_start(ap, fmt); /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      if ((c = getchar()) == EOF) {
        va_end(ap);
        return EOF;
      }
      else if (c != *p) {
        va_end(ap);
        return r;
      }
    }
    else {
      switch (*++p) {
      case 'o': sr = scanf("%o", va_arg(ap, int*)); break;
      case 'd': sr = scanf("%d", va_arg(ap, int*)); break;
      case 'u': sr = scanf("%u", va_arg(ap, unsigned int*)); break;
      case 'e':
      case 'f':
      case 'g': sr = scanf("%f", va_arg(ap, float*)); break;
      case 'c': sr = scanf("%c", va_arg(ap, char*)); break;
      case '%':
        if (c == EOF) {
          va_end(ap);
          return EOF;
        }
        else if (c != '%') {
          va_end(ap);
          return r;
        }
        break;
      default:
        printf("ERROR! Unsupported conversion %%%c.\n", *p);
        va_end(ap);
        return EOF;
      }
      if (sr == EOF) {
        va_end(ap);
        return EOF;
      }
      r++;
    }
  }
  va_end(ap); /* clean up when done */
  return r;
}
