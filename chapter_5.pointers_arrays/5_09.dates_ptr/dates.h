# ifndef DATES_H
# define DATES_H

/* day_of_year: set day of year from month & day.
   on error return -1 for wrong month, and -2 for wrong day. */
int day_of_year (int year, int month, int day);

/* month_day: set month, day from day of year.
   on error return -1 for wrong day. */
int month_day (int year, int yearday, int *pmonth, int *pday);

# endif
