#include <iostream>

using namespace std;

struct stDate
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

bool IsDate1EqualDate2(stDate date1, stDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

stDate ReadFullDate()
{
	stDate date;
	
	date.day = ReadDay();
	date.month = ReadMonth();
	date.year = ReadYear();

	return date;
}

int main()
{
	stDate date1 = ReadFullDate();
	cout << endl;
	stDate date2 = ReadFullDate();

	if (IsDate1EqualDate2(date1, date2))
	{
		cout << "\nYes, Date 1 is Equal To Date 2\n";
	}
	else
	{
		cout << "\nNo, Date 1 is Not Equal To Date 2\n";
	}

	return 0;  
}
