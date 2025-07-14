/*
Problem 60 |=============================================================================================

Write a program to read a Period and
Date, then check if date is within this
period or not?


Enter Period:
Enter Start Date:

Please enter a Day: 1
Please enter a Month: 1
Please enter a Year: 2022

Enter End Date:

Please enter a Day: 10
Please enter a Month: 1
Please enter a Year: 2022

Enter Date to check:

Please enter a Day: 5
Please enter a Month: 1
Please enter a Year: 2022

Yes, the date is inside the period.

==========================================================================================================
*/
#include <iostream>
using namespace std;

// Define a date structure
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Define a period structure
struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

// Check if Date1 is before Date2
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
           ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
            (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
            : false);
}

// Check if Date1 equals Date2
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ?
           ((Date1.Month == Date2.Month) ?
            ((Date1.Day == Date2.Day) ? true : false)
            : false)
           : false;
}

// Check if Date1 is after Date2
bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

// Enum for compare result
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

// Function to compare two dates
enDateCompare CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    return enDateCompare::After; // Faster fallback
}

// Check if a date is inside a period
bool isDateInPeriod(stDate Date, stPeriod Period) {
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
          || CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

// Read day
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Read month
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Read year
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Read a full date
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Read a period (start and end date)
stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

int main() {
    cout << "\nEnter Period:";
    stPeriod Period = ReadPeriod();

    cout << "\nEnter Date to check:\n";
    stDate Date = ReadFullDate();

    if (isDateInPeriod(Date, Period))
        cout << "\nYes, the date is inside the period.\n";
    else
        cout << "\nNo, the date is NOT inside the period.\n";

    system("pause>0");
    return 0;
}
