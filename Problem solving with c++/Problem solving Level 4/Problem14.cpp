/*
Problem 01 |=============================================================================================

Write a program to read datel, date2 and
check if Datel Equals to Date2

Enter the first date:

Please enter a Day: 20
Please enter a Month: 9
Please enter a Year: 2022

Enter the second date:

Please enter a Day: 23
Please enter a Month: 9
Please enter a Year: 2022

No, Date1 is NOT Equal To Date2.

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

// Function to check if two dates are equal
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) &&
           (Date1.Month == Date2.Month) &&
           (Date1.Day == Date2.Day);
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

// Function to read a complete date from the user
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Main function
int main() {
    // Ask user to enter the first and second date
    cout << "Enter the first date:\n";
    stDate Date1 = ReadFullDate();

    cout << "\nEnter the second date:\n";
    stDate Date2 = ReadFullDate();

    // Compare if both dates are equal
    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is Equal To Date2.\n";
    else
        cout << "\nNo, Date1 is NOT Equal To Date2.\n";

    system("pause>0"); // Pause the console (for Windows)
    return 0;
}
