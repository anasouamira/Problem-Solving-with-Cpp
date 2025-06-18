/*
Problem 01 |=============================================================================================

Write a program to read a date and check:
. if it is last Day in Month
. If it is last Month In Year

Please enter a Day: 31
Please enter a Month: 12
Please enter a Year: 2022

Yes, the day is the last day in the month.
Yes, the month is the last month in the year.

==========================================================================================================
*/
#include <iostream>
using namespace std;

// Structure to store a date
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Function to check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the number of days in a month for a given year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // Adjust February if it's a leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to check if the given day is the last day of the month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Function to check if the given month is the last month of the year (December)
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Function to read a day from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Function to read a month from the user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Function to read a year from the user
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Function to read a full date (day/month/year)
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main function
int main() {
    // Read the date from the user
    stDate Date1 = ReadFullDate();

    // Check if the day is the last day of the month
    if (IsLastDayInMonth(Date1))
        cout << "\nYes, the day is the last day in the month.";
    else
        cout << "\nNo, the day is not the last day in the month.";

    // Check if the month is December
    if (IsLastMonthInYear(Date1.Month))
        cout << "\nYes, the month is the last month in the year.";
    else
        cout << "\nNo, the month is not the last month in the year.";

    system("pause>0"); // Pause the console window (Windows only)
    return 0;
}

