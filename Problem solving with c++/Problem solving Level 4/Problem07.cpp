/*
Problem 07 |=============================================================================================

Write a program fo read a date, and
print the day name of week.

Output : 

Please enter a year? 2022

Please enter a Month? 9

Please enter a Day? 1

Date :1/9/2022
Day Order : 4
Day Name : Thu

==========================================================================================================
*/
#include <iostream>
using namespace std;
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\nDate :" << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(Day, Month, Year));
    system("pause>0");
    return 0;
}
