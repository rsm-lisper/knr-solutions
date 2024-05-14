# include <stdio.h>
# include <time.h>

int binsearch (int x, int v[], int n);
int binsearch_1test (int x, int v[], int n);

# define VSIZE 2000000


int main()
{
  int v[VSIZE], q;
  clock_t t0, t1, t2, t3, t4, t5, t6;

  for (q = 0; q < VSIZE; q++) {
    v[q] = q;
  }

  t0 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch(q, v, VSIZE);
  }
  t1 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch_1test(q, v, VSIZE);
  }
  t2 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch(q, v, VSIZE);
  }
  t3 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch_1test(q, v, VSIZE);
  }
  t4 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch(q, v, VSIZE);
  }
  t5 = clock();
  for (q = 0; q < VSIZE; q++) {
    binsearch_1test(q, v, VSIZE);
  }
  t6 = clock();

  printf("binsearch oryginal\n0: %ld\n1: %ld\n2: %ld\nbinsearch 1-test\n0: %ld\n1: %ld\n2: %ld\n", t1-t0, t3-t2, t5-t4, t2-t1, t4-t3, t6-t5);
  
  return 0;
}


int binsearch (int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid - 1;
    else if(x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}


int binsearch_1test (int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n-1;
  mid = (low+high) / 2;
  while ((low <= high) && (x != v[mid])) {
    if (x < v[mid])
      high = mid-1;
    else
      low = mid+1;
    mid = (low+high) / 2;
  }
  if (x == v[mid]) {
    return mid; /* found match */
  }
  return -1; /* no match */
}
