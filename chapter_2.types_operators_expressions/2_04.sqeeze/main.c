
# include <stdio.h>
# include <stdbool.h>

# define MAXLEN 128

void readln (char t[MAXLEN]);
void squeeze (char s1[], char s2[]);


int main ()
{
  char txt[MAXLEN], filter[MAXLEN];

  readln(txt);
  readln(filter);
  squeeze(txt, filter);
  printf("%s\n", txt);
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


void squeeze (char s1[], char s2[])
{
  int i1, i2, j, match;
  
  for (i1 = j = 0; s1[i1] != '\0'; i1++) {
    for (match = false, i2 = 0; s2[i2] != '\0' && !match; i2++) {
      if (s1[i1] == s2[i2]) {
	match = true;
      }
    }
    if (!match) {
      s1[j++] = s1[i1];
    }
  }
  s1[j] = '\0';
}
