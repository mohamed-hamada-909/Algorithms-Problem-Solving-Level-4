#include <iostream>
#include "Date Library.h";

using namespace std;

int main()
{
	cout << "Please Enter Your Date of Birth?\n\n";

	Date::stDate date1 = Date::ReadFullDate();
	Date::stDate date2 = Date::GetSystemDate();
	
	cout << "Your Age is: ";
	cout << Date::DiffInDay(date1, date2, true) << " Day(s).\n";

	return 0;
}