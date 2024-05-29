
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day.
   on error return -1 for wrong month, and -2 for wrong day. */
int day_of_year (int year, int month, int day)
{
  int i, leap;

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  if (month < 1 || month > 12)
    return -1; /* wrong month */
  if (day < 1 || day > daytab[leap][month])
    return -2; /* wrong day */
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year.
   on error return -1 for wrong day. */
int month_day (int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  *pmonth = 0;
  *pday = 0;
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  if (yearday < 1 || (!leap && yearday>365) || (leap && yearday>366))
    return -1; /* wrong day */
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
  return 0;
}
