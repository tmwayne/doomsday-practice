//
// -----------------------------------------------------------------------------
// doomsday.c
// -----------------------------------------------------------------------------
//
// Generate values for practicing the Day of the Week calculations
// Doomsday algorithm courtesy of John Conway.
//
// Tyler Wayne © 2021
//

#include <stdio.h>             // printf
#include <stdlib.h>            // rand, srand, RAND_MAX
#include <time.h>              // time, clock, CLOCKS_PER_SEC

#define YEAR_MIN 1700
#define YEAR_MAX 2100

static int anchor_day[4] = { 2, 0, 5, 3 };

int random_year() {

  int year = YEAR_MIN + rand() / (RAND_MAX / (YEAR_MAX-YEAR_MIN));
  return year;

}

int doomsday(int year) {

  int century = year / 100;
  year %= 100;

  int a = year / 12;
  int b = year % 12;
  int c = (year % 12) / 4;
  int d = anchor_day[century % 4];

  return (a + b + c + d) % 7;

}

int main() {

  srand(time(NULL)); // set random seed

  int year = random_year();

  time_t start = time(NULL);
  printf("What is the doomsday for year %d ?", year);

  while (getchar()) break;
  time_t elapsed = time(NULL) - start;

  printf("It's %d\nIt took you %ld second...\n", doomsday(year), elapsed);

}
