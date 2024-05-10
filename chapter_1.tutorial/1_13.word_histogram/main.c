# include <stdio.h>

# define MAXLENGTH 16
# define INWORD 1
# define NOTINWORD 0


int main ()
{
  int i, j, c, counters[MAXLENGTH], wordlen = 0, maxwordlen = 0, status = NOTINWORD;

  for (i = 0; i < MAXLENGTH; i++) {
    counters[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (status == INWORD) {
	status = NOTINWORD;
	if (wordlen > maxwordlen) {
	  maxwordlen = wordlen;
	}
	if (wordlen < MAXLENGTH) {
	  counters[wordlen]++;
	}
	else {
	  counters[0]++;
	}
	wordlen = 0;
      }
    }
    else {
      if (status == NOTINWORD) {
	status = INWORD;
      }
      wordlen++;
    }
  }

  if (maxwordlen >= MAXLENGTH) {
    maxwordlen = MAXLENGTH - 1;
  }
  for (i = 1; i <= maxwordlen; i++) {
    printf("%3d: [%2d] ", i, counters[i]);
    for (j = 0; j < counters[i]; j++) {
      printf("#");
    }
    printf("\n");
  }
  if (counters[0] > 0) {
    printf(">%d: [%2d] ", MAXLENGTH - 1, counters[0]);
    for (j = 0; j < counters[0]; j++) {
      printf("#");
    }
    printf("\n");
  }

  return 0;
}
