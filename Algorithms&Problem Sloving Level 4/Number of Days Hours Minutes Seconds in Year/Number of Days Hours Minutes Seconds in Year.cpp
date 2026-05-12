#include <iostream>
#include <string>

using namespace std;

short ReadNumOfYear()
{
    short year;
    cout << "Enter Num a Year to Check?\n";
    cin >> year;

    return year;
}

bool LeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDays(short year)
{
    return LeapYear(year) ? 366 : 365;
}

short NumberOfHours(short year)
{
    return NumberOfDays(year) * 24;
}

int NumberOfMinutes(short year)
{
    return NumberOfHours(year) * 60;
}

int NumberOfSeconds(short year)
{
    return NumberOfMinutes(year) * 60;
}

int main()
{
    short year = ReadNumOfYear();

    cout << "Number Of Days    in Year [" << year << "] is " << NumberOfDays(year) << endl;
    cout << "Number Of Hours   in Year [" << year << "] is " << NumberOfHours(year) << endl;
    cout << "Number Of Minutes in Year [" << year << "] is " << NumberOfMinutes(year) << endl;
    cout << "Number Of Seconds in Year [" << year << "] is " << NumberOfSeconds(year) << endl;

    return 0;
}
