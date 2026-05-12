#include <iostream>
#include <string>

using namespace std;

short ReadYear()
{
    short year;
    cout << "Please Enter Year to Check?\n";
    cin >> year;

    return year;
}

bool LeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int year = ReadYear();

    if (LeapYear(year))
    {
        cout << "Yes, Year [" << year << "] is a Leap Year\n";
    }
    else
    {
        cout << "No, Year [" << year << "] is Not Leap Year\n";
    }

    return 0;
}
