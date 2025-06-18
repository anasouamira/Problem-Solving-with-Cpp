/*
Problem 01 |=============================================================================================

Write a program to read date and read
how many days to add to it, print the
results on screen

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

// Function to get number of days in a given month and year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to check if the given date is the last day of the month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Function to check if the month is December (last month of the year)
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Function to increase a date by one day
stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            // If it's 31/12, move to 1/1 of next year
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        } else {
            // If it's the last day of the month, move to 1st of next month
            Date.Day = 1;
            Date.Month++;
        }
    } else {
        // If it's not the last day, just increment the day
        Date.Day++;
    }
    return Date;
}

// Function to read day from user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Function to read month from user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Function to read year from user
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Function to read a full date from user
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main function
int main() {
    // Read the date from user
    stDate Date1 = ReadFullDate();

    // Increase the date by one day
    Date1 = IncreaseDateByOneDay(Date1);

    // Display the result
    cout << "\nDate after adding one day is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    system("pause>0"); // Pause the console (Windows only)
    return 0;
}

