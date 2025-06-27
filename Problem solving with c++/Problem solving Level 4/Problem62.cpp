/*
Problem 54 |=============================================================================================

Write a program fo read Date and write a
function to validate this date.

Please enter a Day: 35
Please enter a Month: 1
Please enter a Year: 2022

No, the date is NOT valid.


Please enter a Day: 29
Please enter a Month: 2
Please enter a Year: 2022

No, the date is NOT valid

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

// Function to check if a year is leap
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get number of days in a given month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2) // Special case for February
        return isLeapYear(Year) ? 29 : 28;

    return days[Month - 1];
}

// Function to check if a given date is valid
bool IsValidDate(stDate Date) {
    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Day < 1 || Date.Day > 31)
        return false;

    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
        return false;

    return true; // Valid if all checks passed
}

// Read day from user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Read month from user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Read year from user
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Read full date
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main program
int main() {
    stDate Date1 = ReadFullDate();

    if (IsValidDate(Date1))
        cout << "\nYes, the date is valid.\n";
    else
        cout << "\nNo, the date is NOT valid.\n";

    system("pause>0");
    return 0;
}


