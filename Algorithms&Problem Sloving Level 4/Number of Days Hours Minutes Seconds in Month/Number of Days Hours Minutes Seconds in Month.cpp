#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Please Enter a Year to Check?\n";
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

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(short month, short year)
{
    if (month < 1 || month>12)
    {
        return 0;
    }

    if (month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }

    short arr31days[7] = { 1,3,5,7,8,10,12 };

    for (short i = 0; i <= 7; i++)
    {
        if (arr31days[i] == month)
        {
            return 31;
        }
    }
    return 30;
}

short NumberOfHoursInMonth(short month, short year)
{
    return NumberOfDaysInMonth(month, year) * 24;
}

int NumberOfMinutesInMonth(short month, short year)
{
    return NumberOfHoursInMonth(month, year) * 60;
}

int NumberOfSecondsInMonth(short month, short year)
{
    return NumberOfMinutesInMonth(month, year) * 60;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    cout << "Number of Days    in Month [" << month << "] is: " << NumberOfDaysInMonth(month, year) << endl;
    cout << "Number of Hours   in Month [" << month << "] is: " << NumberOfHoursInMonth(month, year) << endl;
    cout << "Number of Minutes in Month [" << month << "] is: " << NumberOfMinutesInMonth(month, year) << endl;
    cout << "Number of Seconds in Month [" << month << "] is: " << NumberOfSecondsInMonth(month, year) << endl;

    return 0;
}
