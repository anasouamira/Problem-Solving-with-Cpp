/*
Problem 61 |=============================================================================================

Write a program to read a tow periods
then count overlap days?

Enter Period 1:
Enter Start Date:

Please enter a Day: 1
Please enter a Month: 1
Please enter a Year: 2022

Enter End Date:

Please enter a Day: 10
Please enter a Month: 1
Please enter a Year: 2022

Enter Period 2:
Enter Start Date:

Please enter a Day: 5
Please enter a Month: 1
Please enter a Year: 2022

Enter End Date:

Please enter a Day: 30
Please enter a Month: 12
Please enter a Year: 2050

Overlap Days Count is: 5

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

// Define a period structure (Start and End dates)
struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

// Check if Date1 is before Date2
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year == Date2.Year) {
        if (Date1.Month < Date2.Month) return true;
        if (Date1.Month == Date2.Month) {
            return Date1.Day < Date2.Day;
        }
    }
    return false;
}

// Check if Date1 equals Date2
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) &&
           (Date1.Month == Date2.Month) &&
           (Date1.Day == Date2.Day);
}

// Check if Date1 is after Date2
bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

// Check if year is leap
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Get number of days in month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (Month == 2)
        return isLeapYear(Year) ? 29 : 28;
    return days[Month - 1];
}

// Check if date is last day in month
bool IsLastDayInMonth(stDate Date) {
    return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

// Check if month is last month in year
bool IsLastMonthInYear(short Month) {
    return Month == 12;
}

// Add one day to date
stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
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

// Get difference in days between two dates
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

// Enum for date comparison result
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

// Compare two dates
enDateCompare CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2)) return Before;
    if (IsDate1EqualDate2(Date1, Date2)) return Equal;
    return After;
}

// Get period length in days
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false) {
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

// Check if periods overlap
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (CompareDates(Period2.EndDate, Period1.StartDate) == Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == After)
        return false;
    else
        return true;
}

// Check if date is in period
bool isDateInPeriod(stDate Date, stPeriod Period) {
    return !(CompareDates(Date, Period.StartDate) == Before ||
             CompareDates(Date, Period.EndDate) == After);
}

// Count overlapping days
int CountOverlapDays(stPeriod Period1, stPeriod Period2) {
    int OverlapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (PeriodLengthInDays(Period1, true) < PeriodLengthInDays(Period2, true)) {
        while (!IsDate1AfterDate2(Period1.StartDate, Period1.EndDate)) {
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    } else {
        while (!IsDate1AfterDate2(Period2.StartDate, Period2.EndDate)) {
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

// Input helpers
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

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

// Main
int main() {
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count is: " << CountOverlapDays(Period1, Period2) << endl;

    system("pause>0");
    return 0;
}

