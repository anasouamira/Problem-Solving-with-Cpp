/*
Problem 01 |=============================================================================================

Werite a program calculate you age in days.


Please Enter Your Date of Birth:

Please enter a Day: 13
Please enter a Month: 6
Please enter a Year: 2004

Your Age is: 7677 Day(s).


==========================================================================================================
*/

#pragma warning(disable : 4996) // Disable warning for using localtime
#include <iostream>
#include <ctime> // Required for time and localtime
using namespace std;

// Structure to store date
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Function to check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to compare two dates
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

// Function to get the number of days in a month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0;

    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Check if it's the last day in the month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Check if it's the last month of the year
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Increase date by one day
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

// Calculate number of days between two dates
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
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

// Read full date from user
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Get the current system date
stDate GetSystemDate() {
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

// Main function
int main() {
    cout << "\nPlease Enter Your Date of Birth:\n";
    stDate BirthDate = ReadFullDate();   // Input: birth date
    stDate Today = GetSystemDate();      // Get today's date

    cout << "\nYour Age is: "
         << GetDifferenceInDays(BirthDate, Today, true)
         << " Day(s).\n";

    system("pause>0"); // Pause console (Windows only)
    return 0;
}
