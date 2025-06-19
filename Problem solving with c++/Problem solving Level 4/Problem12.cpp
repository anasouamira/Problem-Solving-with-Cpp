/*
Problem 12 |=============================================================================================

Write a program to read date and read
how many days to add to it, print the
results on screen

Please enter a Day? 20

Please enter a Month? 9

Please enter a Year? 2022

How many days to add? 2500

Date after adding [2500] days is: 25/7/2029

==========================================================================================================
*/
#include <iostream> // for cout and cin
using namespace std;

// Define a struct to hold a date
struct sDate {
    short Year;
    short Month;
    short Day;
};

// Function to check whether a given year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to return number of days in a given month for a given year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // February adjustment if leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to calculate how many days passed from Jan 1st to given date
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;

    for (int i = 1; i < Month; i++) {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
}

// Function to add a number of days to a given date
sDate DateAddDays(short Days, sDate Date) {
    // Calculate total days from beginning of the year + added days
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

    short MonthDays = 0;
    Date.Month = 1; // Reset month to start from beginning of the year

    // Loop to find correct month and day after adding days
    while (true) {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.Month++;

            // If month > 12, move to next year
            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }
        } else {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

// Function to read day from user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

// Function to read month from user
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read year from user
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

// Function to read a complete date (day, month, year)
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Function to read number of days to add
short ReadDaysToAdd() {
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}

// Main function
int main() {
    sDate Date = ReadFullDate(); // Get initial date
    short Days = ReadDaysToAdd(); // Get days to add

    Date = DateAddDays(Days, Date); // Add days to the date

    // Display result
    cout << "\nDate after adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0"); // Pause console (Windows only)
    return 0;
}
