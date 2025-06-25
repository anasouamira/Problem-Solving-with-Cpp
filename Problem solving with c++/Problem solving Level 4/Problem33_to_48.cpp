/*
Problem 21 |=============================================================================================

Write a program to read a date and make a functions to
Decrease date as follows:

+ DecreaseDateByOneDay

+ DecreaseDateByXDays

+ DecreaseDateByOneWeek

+ DecreaseDateByXWeeks

+ DecreaseDateByOneMonth

+ DecreaseDateByXMonths

+ DecreaseDateByOneYear

+ DecreaseDateByXYears

+ DecreaseDateByXYearsFaster 

+ DecreaseDateByOneDecade 

+ DecreaseDateByXDecades

+ DecreaseDateByXDecadesFaster

+ DecreaseDateByOneCentury

+ DecreaseDateByOneMillennium

Please enter a Day? 31
Please enter a Month? 12
Please enter a Year? 2022

Date After:

01-Subtracting one day is: 30/12/2022
02-Subtracting 10 days is: 20/12/2022
03-Subtracting one week is: 13/12/2022
04-Subtracting 10 weeks is: 4/10/2022
05-Subtracting one month is: 4/9/2022
06-Subtracting 5 months is: 4/4/2022
07-Subtracting one year is: 4/4/2021
08-Subtracting 10 Years is: 4/4/2011
09-Subtracting 10 Years (faster) is: 4/4/2001
10-Subtracting one Decade is: 4/4/1991
11-Subtracting 10 Decades is: 4/4/1891
12-Subtracting 10 Decades (faster) is: 4/4/1791
13-Subtracting One Century is: 4/4/1691
14-Subtracting One Millennium is: 4/4/691

==========================================================================================================
*/
#include <iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

stDate DecreaseDateByOneDay(stDate Date) {
    if (Date.Day == 1) {
        if (Date.Month == 1) {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        } else {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    } else {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {
    for (int i = 1; i <= 7; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date) {
    for (short i = 1; i <= Weeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    } else {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date) {
    for (short i = 1; i <= Days; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date) {
    for (short i = 1; i <= Months; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date) {
    for (short i = 1; i <= Years; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date) {
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(short Decade, stDate Date) {
    for (short i = 1; i <= Decade * 10; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date) {
    Date.Year -= Decade * 10;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date) {
    Date.Year -= 1000;
    return Date;
}

short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year? ";
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

int main() {
    stDate Date1 = ReadFullDate();
    cout << "\nDate After: \n";

    Date1 = DecreaseDateByOneDay(Date1);
    cout << "\n01-Subtracting one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDays(10, Date1);
    cout << "\n02-Subtracting 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneWeek(Date1);
    cout << "\n03-Subtracting one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXWeeks(10, Date1);
    cout << "\n04-Subtracting 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMonth(Date1);
    cout << "\n05-Subtracting one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXMonths(5, Date1);
    cout << "\n06-Subtracting 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneYear(Date1);
    cout << "\n07-Subtracting one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYears(10, Date1);
    cout << "\n08-Subtracting 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Subtracting 10 Years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneDecade(Date1);
    cout << "\n10-Subtracting one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecades(10, Date1);
    cout << "\n11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecadesFaster(10, Date1);
    cout << "\n12-Subtracting 10 Decades (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneCentury(Date1);
    cout << "\n13-Subtracting One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMillennium(Date1);
    cout << "\n14-Subtracting One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    system("pause>0");
    return 0;
}

