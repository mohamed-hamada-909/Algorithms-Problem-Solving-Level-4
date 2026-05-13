#include <iostream>
#include <string>
#include <cstdio>

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

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfWeekOrder(short day,short month, short year)
{
    int a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)/ 12)) % 7;       
}

short NumberofDaysInMonth(short month, short year)
{
    if (month < 1 || month>12)
    {
        return 0;
    }

    short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}

string MonthName(short numofmonth)
{
    string arrmonth[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

    return (arrmonth[numofmonth - 1]);
}

void PrintMonthCalendar(short month, short year)
{
    int current = DayOfWeekOrder(1,month, year);

    int numberdays = NumberofDaysInMonth(month, year);

    printf("\n ----------------------%s-------------------- \n\n",MonthName(month).c_str());
    
    printf("   Sun  Mon Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
    {
        printf("     ");
    }

    for (int j = 1; j <= numberdays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n----------------------------------------------\n");
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    PrintMonthCalendar(month, year);

    return 0;
}
