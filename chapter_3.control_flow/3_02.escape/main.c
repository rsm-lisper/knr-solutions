# include <stdio.h>
# include <stdbool.h>

int escape (char *s, char *t);
int unescape (char *s, char *t);

# define TEXTLEN 8192


int main ()
{
  int c, pos;
  char oryg[TEXTLEN], esc[TEXTLEN*2], unesc[TEXTLEN];

  pos = 0;
  while ((c = getchar()) != EOF && pos < TEXTLEN) {
    oryg[pos++] = c;
  }
  if (pos == TEXTLEN) { pos--; }
  oryg[pos] = '\0';
  
  escape(esc, oryg);
  unescape(unesc, esc);
  printf("---[ORYGINAL:]---\n%s\n---[ESCAPE:]---\n%s\n---[ESC/UNESCAPE:]---\n%s\n------", oryg, esc, unesc);
  
  return 0;
}


int escape (char *s, char *t)
{
  int is, it;

  for (is = 0, it = 0; t[it] != '\0'; is++, it++) {
    switch (t[it]) {
    case '\a': s[is] = '\\'; s[++is] = 'a'; break;
    case '\b': s[is] = '\\'; s[++is] = 'b'; break;
    case '\t': s[is] = '\\'; s[++is] = 't'; break;
    case '\n': s[is] = '\\'; s[++is] = 'n'; break;
    case '\r': s[is] = '\\'; s[++is] = 'r'; break;
    case '\\': s[is] = '\\'; s[++is] = '\\'; break;
    default: s[is] = t[it];
    }
  }
  return 0;
}


int unescape (char *s, char *t)
{
  int is, it, special;

  it = is = 0;
  special = false;
  while (t[it] != '\0') {
    if (special) {
      switch (t[it]) {
      case 'a': s[is] = '\a'; break;
      case 'b': s[is] = '\b'; break;
      case 't': s[is] = '\t'; break;
      case 'n': s[is] = '\n'; break;
      case 'r': s[is] = '\r'; break;
      case '\\': s[is] = '\\'; break;
      default: s[is++] = '\\'; s[is] = t[it];
      }
      special = false;
      is++;
      it++;
    } else {
      if (t[it] == '\\') {
	special = true;
	it++;
      } else {
	s[is] = t[it];
	is++;
	it++;
      }
    }
  }
  s[is] = '\0';
  
  return 0;
}
