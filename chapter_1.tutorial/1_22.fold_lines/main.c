# include <stdio.h>

# define LINELIM 1024
# define BREAKPOS 20
# define TABSIZE 8
# define NOBREAK -1

int get_line (char s[], int lim);
int findbreak (char s[], int startp, int lim);


int main ()
{
  int l, last, startp, p, truep;
  char s[LINELIM];
  
  while ((l = get_line(s, LINELIM)) > 0) {
    startp = 0;
    while (startp < l) {
      if ((last = findbreak(s, startp, BREAKPOS)) == NOBREAK) {
	for (p=startp, truep=0; s[p]!='\0' && truep<BREAKPOS; p++, truep++) {
	  printf("%c", s[p]);
	  if (s[p]=='\t') {
	    truep += TABSIZE-1;
	  }
	}
	if (s[p]!='\0') {
	  printf("\n");
	}
      }
      else {
	for (p=startp; p<last; p++) {
	  printf("%c", s[p]);
	}
	printf("\n");
      }
      startp = p;
    }
  }
  return 0;
}


int get_line (char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++) {
    s[i] = c;
  }
  if (c=='\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}


int findbreak (char s[], int startp, int lim)
{
  int p, truep, last=NOBREAK;
  
  for (p=startp+1, truep=1; s[p]!='\0' && truep<lim; p++, truep++) {
    if ((s[p]==' ' || s[p]=='\t') && s[p-1]!=' ' && s[p-1]!='\t') {
      last = p;
    }
    if (s[p]=='\t') {
      truep += TABSIZE-1;
    }
  }
  return last;
}
