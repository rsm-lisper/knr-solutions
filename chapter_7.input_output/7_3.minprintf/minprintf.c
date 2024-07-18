# include <stdio.h>
# include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf (char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  char *p, *sval;
  
  va_start(ap, fmt); /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'i':
    case 'd': printf("%d", va_arg(ap, int)); break;
    case 'u': printf("%u", va_arg(ap, unsigned int)); break;
    case 'x': printf("%x", va_arg(ap, int)); break;
    case 'f': printf("%f", va_arg(ap, double)); break;
    case 'c': printf("%c", va_arg(ap, int)); break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
        putchar(*sval);
      break;
    default: putchar(*p); break;
    }
  }
  va_end(ap); /* clean up when done */
}
