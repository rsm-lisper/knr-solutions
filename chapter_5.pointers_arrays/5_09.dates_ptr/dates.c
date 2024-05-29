
# define MLEN 13

static int daytab[][MLEN] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day.
   on error return -1 for wrong month, and -2 for wrong day. */
int day_of_year (int year, int month, int day)
{
  int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  int *dt = *(daytab+leap);
  if (month < 1 || month > 12)
    return -1; /* wrong month */
  if (day < 1 || day > *(dt+month))
    return -2; /* wrong day */
  for (month-- ; month; month--)
    day += *(dt+month+1);
  return day;
}

/* month_day: set month, day from day of year.
   on error return -1 for wrong day. */
int month_day (int year, int yearday, int *pmonth, int *pday)
{
  *pmonth = 0;
  *pday = 0;
  int i, leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  int *dt = *(daytab+leap);
  if (yearday < 1 || (!leap && yearday>365) || (leap && yearday>366))
    return -1; /* wrong day */
  for (i = 1; yearday > *(dt+i); i++)
    yearday -= *(dt+i);
  *pmonth = i;
  *pday = yearday;
  return 0;
}
