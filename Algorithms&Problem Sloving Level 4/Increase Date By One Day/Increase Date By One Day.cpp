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
	cout << "Plase Enter a Day?\n";
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

short NumberDaysInMonth(short month, short year)
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
	return (date.day == NumberDaysInMonth(date.month, date.year));
}

bool IsLastMonthInYear(short month)
{
	return (month == 12);
}

stDate IncreaseDateByOneDay(stDate date)
{
	if (IsLastDayInMonth(date))
	{
		if (IsLastMonthInYear(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.month++;
			date.day = 1;
		}
	}
	else
	{
		date.day++;
	}
	return date;
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

	date = IncreaseDateByOneDay(date);

	cout << "\nDate After Adding One Day is: ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;

	return 0;
}
