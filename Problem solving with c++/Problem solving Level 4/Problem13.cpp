/*
Problem 01 |=============================================================================================

Write a program to read datel, date2 and
check if Datel is Less than Date2

Enter the first date:

Please enter a Day: 20
Please enter a Month: 9
Please enter a Year: 2022

Enter the second date:

Please enter a Day: 19
Please enter a Month: 9
Please enter a Year: 2022

No, Date1 is NOT less than Date2.

==========================================================================================================
*/
#include <iostream>
using namespace std;

// Define a structure to represent a date
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Function to check if Date1 is before Date2
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    // Compare years first
    if (Date1.Year < Date2.Year)
        return true;

    // If years are equal, compare months
    if (Date1.Year == Date2.Year) {
        if (Date1.Month < Date2.Month)
            return true;

        // If months are also equal, compare days
        if (Date1.Month == Date2.Month)
            return Date1.Day < Date2.Day;
    }

    // In all other cases, Date1 is not before Date2
    return false;
}

// Function to read the day from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Function to read the month from the user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Function to read the year from the user
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

// Main program
int main() {
    // Read two dates from the user
    cout << "Enter the first date:\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter the second date:\n";
    stDate Date2 = ReadFullDate();

    // Compare the two dates
    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is less than Date2.\n";
    else
        cout << "\nNo, Date1 is NOT less than Date2.\n";

    system("pause>0"); // Pause the console (only works in Windows)
    return 0;
}
