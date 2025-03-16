#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year)
{
    if ((year % 4 == 0 & year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int days_in_month(int year, int month)
{
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year))
    {
        return 29;
    }
    return days_per_month[month - 1];
}

int next_arrival(int year, int month, int day)
{
    int target_month = 12;
    int target_day = 6;

    if (month == target_month && day == target_day)
    {
        return 0;
    }

    int days_remaining = 0;

    if (month > target_month || (month == target_month & day > target_day))
    {
        year++;
    }

    days_remaining += days_in_month(year, month) - day;
    month++;

    while (month < target_month)
    {
        days_remaining += days_in_month(year, month);
        month++;
    }

    days_remaining += target_day;

    return days_remaining;
}

int main()
{
    int year, month, day;
    int next_arrival(int, int, int);
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        int res = next_arrival(year, month, day);
        printf("%d\n", res);
    }
    return EXIT_SUCCESS;
}