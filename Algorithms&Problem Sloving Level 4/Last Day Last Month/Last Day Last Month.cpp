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

	short arrmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrmonth[month - 1];
}

bool IsLastDayInMonth(stDate date)
{
	return (date.day == NumberOfDaysInMonth(date.month, date.year));
}

bool IsLastMonthInYear(short month)
{
	return (month == 12);
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
	stDate date = ReadFullDate();

	if (IsLastDayInMonth(date))
	{
		cout << "\nYes, Day is Last Day in Month.\n";
	}
	else
	{
		cout << "\nNo,Day is Not Last Day in Month.\n";
	}

	if (IsLastMonthInYear(date.month))
	{
		cout << "\nYes, Month is Last Month in Year.\n";
	}
	else
	{
		cout << "\nNo, Month is Not Last Month in Year.\n";
	}

    return 0;
}