#include <iostream>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Please Enter a Year To Check?\n";
    cin >> year;

    return year;
}

short ReadMonth()
{
    short month;
    cout << "Pleae Enter a Month?\n";
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

    short numdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 30) : numdays[month - 1];
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    cout << "Number of Days in Month [" << month << "] is: " << NumberOfDaysInMonth(month, year);
    cout << endl;

    return 0;
}
