# include <stdio.h>
# include "dates.h"


void test_d (int year, int month, int day)
{
  int doy = day_of_year(year, month, day);
  printf("y/m/d %d/%d/%d => %d\n", year, month, day, doy);
}


void test_m (int year, int yearday)
{
  int month, day, r;
  r = month_day(year, yearday, &month, &day);
  printf("y:yd %d/%d => m/d %d/%d (%d)\n", year, yearday, month, day, r);
}


int main ()
{
  test_d(2020, 01, 01);
  test_d(2021, 03, 10);
  test_d(2022, 12, 31);
  test_d(2023, 12, 31);
  test_d(2024, 12, 31);
  test_d(2024, 13, 31);
  test_d(2024, 11, 31);
  test_d(2024, 12, 0);
  test_m(2020, 1);
  test_m(2021, 69);
  test_m(2022, 365);
  test_m(2023, 365);
  test_m(2023, 0);
  test_m(2024, 366);
  test_m(2025, 366);

  return 0;
}
