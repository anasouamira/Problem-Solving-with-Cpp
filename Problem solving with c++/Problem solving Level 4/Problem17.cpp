/*
Problem 17 |=============================================================================================

Write a program to read a Datel, Date2
and make a function to calculate the
difference in days.

Note: Date 1 should be less than Date2

Enter the first date:

Please enter a Day: 1
Please enter a Month: 1
Please enter a Year: 2022

Enter the second date:

Please enter a Day: 25
Please enter a Month: 3
Please enter a Year: 2022

Difference is: 83 day(s).
Difference (Including End Day) is: 84 day(s).

==========================================================================================================
*/

#include <iostream>
using namespace std;

// Structure to represent a date
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Compare two dates to see if Date1 is before Date2
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.Year < Date2.Year)
        return true;

    if (Date1.Year == Date2.Year) {
        if (Date1.Month < Date2.Month)
            return true;

        if (Date1.Month == Date2.Month)
            return Date1.Day < Date2.Day;
    }

    return false;
}

// Return the number of days in a given month and year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Check if the given date is the last day of its month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Check if the month is December
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Increase a given date by one day
stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        } else {
            Date.Day = 1;
            Date.Month++;
        }
    } else {
        Date.Day++;
    }
    return Date;
}

// Calculate the difference in days between two dates
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;

    // Keep incrementing Date1 until it reaches Date2
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    // Include the end date if specified
    return IncludeEndDay ? ++Days : Days;
}

// Function to read day input from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Function to read month input from the user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Function to read year input from the user
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Function to read a full date from the user
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main function
int main() {
    cout << "Enter the first date:\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter the second date:\n";
    stDate Date2 = ReadFullDate();

    cout << "\nDifference is: " 
         << GetDifferenceInDays(Date1, Date2) << " day(s).";

    cout << "\nDifference (Including End Day) is: " 
         << GetDifferenceInDays(Date1, Date2, true) << " day(s).";

    system("pause>0"); // Pause console (for Windows)
    return 0;
}

