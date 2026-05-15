#include <iostream>

using namespace std;

struct sDate
{
    short day;
    short month;
    short year;
};

short ReadDay()
{
    short day;
    cout << "Please Enter a Day?\n";
    cin >> day;

    return day;
}

short ReadMonth()
{
    short month;
    cout << "Please Enter a Month?\n";
    cin >> month;

    return month;
}

short ReadYear()
{
    short year;
    cout << "Please Enter a Year?\n";
    cin >> year;

    return year;
}

short AddDays()
{
    short days;
    cout << "How Many Days To Add?\n";
    cin >> days;

    return days;
}

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

short NumberDaysInMonth(short month, short year)
{
    if (month < 1 || month>12)
    {
        return 0;
    }

    short arrdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrdays[month - 1];
}

short NumberOfDaysFromBeginningYear(short day, short month, short year)
{
    short days = 0;

    for (short i = 1; i < month; i++)
    {
        days += NumberDaysInMonth(i, year);
    }
    days += day;

    return days;
}

sDate AddingDaysToDate(short days, sDate date)
{
    short remainning = days + NumberOfDaysFromBeginningYear(date.day, date.month, date.year);
    short monthdays = 0;

    date.month = 1;

    while (true)
    {
        monthdays = NumberDaysInMonth(date.month, date.year);

        if (remainning > monthdays)
        {
            remainning -= monthdays;
            date.month++;

            if (date.month > 12)
            {
                date.month = 1;
                date.year++;
            }
        }
        else
        {
            date.day = remainning;
            break;
        }
    }
    return date;
}

sDate ReadFullDate()
{
    sDate date;

    date.day = ReadDay();
    date.month = ReadMonth();
    date.year = ReadYear();

    return date;
}

int main()
{
    sDate date = ReadFullDate();
    short addDays = AddDays();

    date = AddingDaysToDate(addDays, date);

    cout << "\nDate After Adding [" << addDays << "] Days is: ";
    cout << date.day << "/" << date.month << "/" << date.year << endl;

    return 0; 
}
