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

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfWeekOrder(short day, short month, short year)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)/ 12)) % 7;       
}

short NumberOfDaysInMonth(short month,short year)
{
    if (month < 1 || month>12)
    {
        return 0;
    }

    short arrmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrmonth[month - 1];
}

string MonthName(short monthnum)
{
    string arrmonth[12] = { "Jan", "Feb", "Mar","Apr", "May", 
        "Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec" };

    return (arrmonth[monthnum - 1]);
}

void PrintMonthCalendar(short month, short year)
{
    short current = DayOfWeekOrder(1, month, year);
    short numdays = NumberOfDaysInMonth(month, year);

    printf("\n _______________%s_______________\n\n", MonthName(month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;

    for ( i = 0; i < current; i++)
    {
        printf("     ");
    }

    for (short j = 1; j <= numdays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n _________________________________\n");
}

void PrintYearCalendar(short year)
{
    printf("\n _________________________________\n\n");
    printf("         Calendar - %d\n", year);
    printf(" _________________________________\n");

    for (short i = 1; i < 12; i++)
    {
        PrintMonthCalendar(i, year);
    }
    return;
}

int main()
{
    short year = ReadYear();

    PrintYearCalendar(year);

    return 0;
}
