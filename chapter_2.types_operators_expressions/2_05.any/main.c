
# include <stdio.h>

# define MAXLEN 128

void readln (char t[MAXLEN]);
int any (char s1[], char s2[]);


int main ()
{
  char txt[MAXLEN], filter[MAXLEN];

  readln(txt);
  readln(filter);
  printf("%d\n", any(txt, filter));
  return 0;
}


void readln (char t[MAXLEN])
{
  int i, c;
  
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
    t[i] = c;
  }
  t[i] = '\0';
}


int any (char s1[], char s2[])
{
  int i1, i2;
  
  for (i1 = 0; s1[i1] != '\0'; i1++) {
    for (i2 = 0; s2[i2] != '\0'; i2++) {
      if (s1[i1] == s2[i2]) {
	return i1;
      }
    }
  }
  return -1;
}
