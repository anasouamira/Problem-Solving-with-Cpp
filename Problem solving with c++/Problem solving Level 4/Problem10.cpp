/*
Problem 10 |=============================================================================================

Write a program to print total days
from the beginning of year.

Please enter a Day? 20

Please enter a Month? 9

Please enter a year? 2022
Number Of Days from beginning of the Year is : 263

==========================================================================================================
*/

#include <iostream> // for input/output operations
using namespace std;

// Function to check if a given year is a leap year
bool isLeapYear(short Year)
{
    // A leap year is divisible by 4 and not divisible by 100
    // or divisible by 400
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the day of the week for a specific date
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    // Adjust month and year for Zeller's Congruence
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // Return day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
// Function to get the number of days in a month, considering leap years
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0; // Invalid month

    // Number of days in each month for a normal year
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If it's February, check for leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short GetNumOfDaysFromBeginningOfTheYear(short Day, short Month, short Year)
{

    short NumDays = 0;

    for (short i = 1; i <= 12; i++)
    {

        if (i == Month)
            break;
        NumDays += NumberOfDaysInAMonth(i, Year);
    }

    return NumDays += Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read year from user
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear(); // Get year from user

    cout << "Number Of Days from beginning of the Year is : " << GetNumOfDaysFromBeginningOfTheYear(Day, Month, Year);
    system("pause>0"); // Wait for user to press a key (Windows only)
    return 0;
}
