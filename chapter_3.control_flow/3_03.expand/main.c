# include <stdio.h>
# include <ctype.h>

# define MAXLEN 2048

int expand (char *s1, char *s2);


int main ()
{
  char c, t1[MAXLEN], t2[MAXLEN];
  unsigned int i = 0;

  while ((c = getchar()) != EOF && i < MAXLEN) {
    t1[i++] = c;
  }
  if (i == MAXLEN) { i--; }
  t1[i] = '\0';

  expand(t1, t2);
  printf("%s\n", t2);
  
  return 0;
}


int expand (char *s1, char *s2)
{
  int p1, p2;
  char last_c, next_c;

  last_c = s2[0] = s1[0];
  if (s1[0] == '\0') {
    return 0;
  }

  p1 = p2 = 1;
  while (s1[p1] != '\0') {
    /* possible expansion */
    if (s1[p1] == '-' && isalnum(last_c) && isalnum(next_c = s1[p1+1])) {
      /* valid format (digit to digit or matching case letter to letter */
      if ((isdigit(last_c) && isdigit(next_c)) || /* digits */
          (isalpha(last_c) && isalpha(next_c) &&
           islower(last_c) == islower(next_c))) { /* matching case letters */
        if (last_c != next_c) {
          /* incr (ie 0-9, a-z, A-Z) */
          if (last_c < next_c) {
            for (last_c++; last_c <= next_c; p2++, last_c++) {
              s2[p2] = last_c;
            }
          }
          /* decr (ie 9-0, z-a, Z-A) */
          else {
            for (last_c--; last_c >= next_c; p2++, last_c--) {
              s2[p2] = last_c;
            }
          }
        }
	last_c = next_c;
	p1 += 2; /* move next */
      } else { /* format not valid, normal copy */
	last_c = s2[p2] = s1[p1];
	p1++, p2++; /* move next */
      }
    } else { /* normal copy */
      last_c = s2[p2] = s1[p1];
      p1++, p2++; /* move next */
    }
  }
  s2[p2] = '\0';
  return p2;
}
