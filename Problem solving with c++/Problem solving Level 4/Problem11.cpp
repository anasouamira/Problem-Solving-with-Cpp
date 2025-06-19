/*
Problem 11 |=============================================================================================

Write a program to print total days
from the beginning of year, then
Take the total days and convert them
back to date.

Please enter a Day? 20

Please enter a Month? 9

Please enter a Year? 2022

Number of Days from the beginning of the year is 263

Date for [263] is: 20/9/2022

==========================================================================================================
*/
#include <iostream> // For input/output
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get number of days in a month for a given year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // February adjustment if leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to calculate how many days passed from the beginning of the year
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;

    // Sum days in previous months
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    // Add days in current month
    TotalDays += Day;

    return TotalDays;
}

// Struct to represent a date (year, month, day)
struct sDate {
    short Year;
    short Month;
    short Day;
};

// Function to convert day order in the year to an actual date
sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    // Loop to find the corresponding month and day
    while (true) {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        } else {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

// Function to read a day from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

// Function to read a month from the user
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read a year from the user
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

// Main function
int main() {
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    // Calculate number of days from the start of the year
    short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
    cout << "\nNumber of Days from the beginning of the year is " << DaysOrderInYear << "\n\n";

    // Convert day order back to date
    sDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
    cout << "Date for [" << DaysOrderInYear << "] is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0"); // Pause the console (Windows only)
    return 0;
}
 