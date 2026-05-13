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

short DayWeekOrder(short day, short month, short year)
{
	short a, m, y;

	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;

	//Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string NameDay(short day)
{	
	string arrdays[] = { "Sum","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrdays[day];
}

int main()
{
	short year = ReadYear();
	short month = ReadMonth();
	short day = ReadDay();

	cout << "\nDate: " << day << "/" << month << "/" << year << endl;
	cout << "Day Order: " << DayWeekOrder(day, month, year) << endl;
	cout << "Name Day: " << NameDay(DayWeekOrder(day,month,year)) << endl;

	return 0;
}
