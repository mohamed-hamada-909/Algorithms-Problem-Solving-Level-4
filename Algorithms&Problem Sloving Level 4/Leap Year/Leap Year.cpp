#include <iostream>
#include <string>

using namespace std;

short ReadYearNumber()
{
    short num;
    cout << "Please Enter a Year to Check?\n";
    cin >> num;

    return num;
}

bool LeapYear(short year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    short year = ReadYearNumber();

    if (LeapYear(year))
    {
        cout << "Yes, Year [" << year << "] is a Leap Year.\n";
    }
    else
    {
        cout << "No, Year [" << year << "] is Not a Leap Year.\n";
    }

    return 0;
}
