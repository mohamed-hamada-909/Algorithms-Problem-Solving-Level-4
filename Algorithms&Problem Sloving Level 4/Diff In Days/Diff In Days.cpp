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
    cout << "Please Enter a Day? ";
    cin >> day;

    return day;
}

short ReadMonth()
{
    short month;
    cout << "Please Enter a Month? ";
    cin >> month;

    return month;
}

short ReadYear()
{
    short year;
    cout << "Please Enter a Year? ";
    cin >> year;

    return year;
}

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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

bool IsDate1BeforeDate2(stDate date1, stDate date2)
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

bool IsLastDayInMonth(stDate date)
{
    return (date.day == NumberOfDaysInMonth(date.month, date.year));
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

int GetDifferenceInDay(stDate date1, stDate date2, bool IncludeEndDay = false)
{
    if (!IsDate1BeforeDate2(date1, date2))
    {
        cout << "Error, Date1 Must Be Before Date2!....\n";
        return 0;
    }

    int days = 0;

    while (IsDate1BeforeDate2(date1, date2))
    {
        days++;
        date1 = IncreaseDateByOneDay(date1);
    }
    return IncludeEndDay ? ++days : days;
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

    cout << "\nDifference is: ";
    cout << GetDifferenceInDay(date1, date2) << " Day(s).\n";

    cout << "\nDifference (Including End Day) is: ";
    cout << GetDifferenceInDay(date1, date2, true) << " Day(s).\n";

    return 0;
}
