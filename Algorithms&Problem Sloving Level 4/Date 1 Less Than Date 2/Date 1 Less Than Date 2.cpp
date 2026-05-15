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

//Dr:Mohamed Solution
bool IfDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : ((date1.year ==
		date2.year) ? (date1.month < date2.month ? true : (date1.month ==
			date2.month ? date1.day < date2.day : false)) : false);
}

//Best Solution
bool Date1BeforeDate2(stDate date1, stDate date2)
{
	if (date1.year != date2.year)
	{
		return date1.year < date2.year;
	}

	if (date1.month != date2.month)
	{
		return date1.month < date2.month;
	}

	return date1.day < date2.day;
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
	stDate date2 = ReadFullDate();

	if (Date1BeforeDate2(date1, date2))
	{
		cout << "\nYes, Date 1 Less Than Date 2.\n";
	}
	else
	{
		cout << "\nNo, Date 1 is Not Less Than Date 2.\n";
	}

	return 0;
}