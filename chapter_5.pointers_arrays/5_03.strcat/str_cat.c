
/* str_cat: concatenate t to the end of s; s must be big enough */
void str_cat (char *s, char *t)
{
  while (*(s++) != '\0') { /* find end of s */
  }
  s--;
  while ((*(s++) = *(t++)) != '\0') {/* copy t */
  }
}
