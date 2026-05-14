#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Please Enter a Year?\n";
    cin >> year;

    return year;
}

short ReadMonth()
{
    short month;
    cout << "Please Enter a Month?\n";
    cin >> month;

    return month;
}

short ReadDay()
{
    short day;
    cout << "Please Enter a Day?\n";
    cin >> day;

    return day;
}

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(short month,short year)
{
    if (month < 1 || month>12)
    {
        return 0;
    }

    short arrmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrmonth[month - 1];
}

short NumberOfDaysFromBeginningTheYear(short day, short month, short year)
{
    short days = 0;

    for (short i = 1; i < month; i++)
    {
        days += NumberOfDaysInMonth(i, year);
    }
    days += day;

    return days;
}

struct sDate
{
    short year;
    short month;
    short day;
};

sDate GetDateFromDayOrderInYear(short dateorder, short year)
{
    sDate date;

    short remaining = dateorder;
    short daysmonth = 0;

    date.year = year;
    date.month = 1;

    while (true)
    {
        daysmonth = NumberOfDaysInMonth(date.month, year);

        if (remaining > daysmonth)
        {
            remaining -= daysmonth;
            date.month++;
        }
        else
        {
            date.day = remaining;
            break;
        }
    }
    return date;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();
    short DaysYear = NumberOfDaysFromBeginningTheYear(day, month, year);

    cout << "Number of Days From Beginning The Year is: ";
    cout << DaysYear << endl;

    sDate date;

    date = GetDateFromDayOrderInYear(DaysYear, year);
    cout << "Date For [" << DaysYear << "] is: ";
    cout << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}
