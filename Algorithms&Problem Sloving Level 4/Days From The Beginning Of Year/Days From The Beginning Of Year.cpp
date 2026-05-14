#include <iostream>
#include <string>

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
    return (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(short month, short year)
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
        days += NumberOfDaysInMonth(i, year);
    }
    days += day;

    return days;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();
   
    cout << "Number of Days From The Beginning of Year: ";
    cout << NumberOfDaysFromBeginningYear(day, month, year) << endl;

    return 0;
}
