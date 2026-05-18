#include <iostream>
#include "Date Library.h";

using namespace std;

int main()
{
    Date::stDate date1 = Date::ReadFullDate();
    Date::stDate date2 = Date::ReadFullDate();

    cout << "\n\nDifference is: ";
    cout << Date::DiffInDay(date1, date2) << " Day(s).\n";

    cout << "Difference Including End Day is: ";
    cout << Date::DiffInDay(date1, date2, true) << " Day(s).\n";

    return 0;
}
