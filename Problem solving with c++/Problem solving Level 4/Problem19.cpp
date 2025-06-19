/*
Problem 01 |=============================================================================================

Write a program to read a Datel, Date2
and make a function to calculate the
difference in days.

Note: if date? is less than datel print the
results in Minutes

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

// Function to check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to compare if Date1 is before Date2
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

// Returns number of days in a specific month of a specific year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Checks if the given date is the last day in the month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Checks if the month is December
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Increases the given date by one day
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

// Swaps two dates
void SwapDates(stDate& Date1, stDate& Date2) {
    stDate TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

// Calculates the difference in days between two dates
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    short SwapFlagValue = 1;

    // Swap if Date1 is after Date2
    if (!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    // Count how many days between the two dates
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

// Functions to read a single part of the date
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Reads a complete date from the user
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main function
int main() {
    cout << "Enter first date:\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter second date:\n";
    stDate Date2 = ReadFullDate();

    cout << "\nDifference is: " 
         << GetDifferenceInDays(Date1, Date2) 
         << " Day(s).";

    cout << "\nDifference (Including End Day) is: " 
         << GetDifferenceInDays(Date1, Date2, true) 
         << " Day(s).";

    system("pause>0"); // Windows-only: pauses the console
    return 0;
}


