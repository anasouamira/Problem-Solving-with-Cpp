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

==========================================================================================================
*/
#include<iostream>usingnamespace std; structstDate{ short Year; short Month; short Day; }; bool isLeapYear(shortYear) { return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); } short NumberOfDaysInAMonth(shortMonth, shortYear) { if (Month < 1 || Month>12) return  0; int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1]; }
stDate DecreaseDateByOneDay(stDateDate) { if (Date.Day == 1)     { if (Date.Month == 1)         { Date.Month = 12; Date.Day = 31; Date.Year--;         } else        { Date.Month--; Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);         }     } else    { Date.Day--;     } returnDate; } stDate DecreaseDateByOneWeek(stDateDate) { for (int i = 1; i <= 7; i++)     { Date = DecreaseDateByOneDay(Date);     } returnDate; } stDate DecreaseDateByXWeeks(shortWeeks, stDateDate) { for (short i = 1; i <= Weeks; i++)     { Date = DecreaseDateByOneWeek(Date);     } returnDate; } 
stDate DecreaseDateByOneMonth(stDateDate) { if (Date.Month == 1)     { Date.Month = 12; Date.Year--;     } elseDate.Month--; //last check day in date should not exceed max days in the current month// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should// be 28/2/2022short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year); if (Date.Day > NumberOfDaysInCurrentMonth)     { Date.Day = NumberOfDaysInCurrentMonth;     } returnDate; } stDate DecreaseDateByXDays(shortDays, stDateDate) { for (short i = 1; i <= Days; i++)     { Date = DecreaseDateByOneDay(Date);     } returnDate; } stDate DecreaseDateByXMonths(shortMonths, stDateDate) { for (short i = 1; i <= Months; i++)     { Date = DecreaseDateByOneMonth(Date);     } returnDate; }
stDate DecreaseDateByOneYear(stDateDate) { Date.Year--; returnDate; } stDate DecreaseDateByXYears(shortYears, stDateDate) { for (short i = 1; i <= Years; i++)     { Date = DecreaseDateByOneYear(Date);     } returnDate; } stDate DecreaseDateByXYearsFaster(shortYears, stDateDate) { Date.Year -= Years; returnDate; } stDate DecreaseDateByOneDecade(stDateDate) { //Period of 10 yearsDate.Year -= 10; returnDate; } stDate DecreaseDateByXDecades(shortDecade, stDateDate) { for (short i = 1; i <= Decade * 10; i++)     { Date = DecreaseDateByOneYear(Date);     } returnDate; } stDate DecreaseDateByXDecadesFaster(shortDecade, stDateDate) { Date.Year -= Decade * 10; returnDate; } 
stDate DecreaseDateByOneCentury(stDateDate) { //Period of 100 yearsDate.Year -= 100; returnDate; } stDate DecreaseDateByOneMillennium(stDateDate) { //Period of 1000 yearsDate.Year -= 1000; returnDate; } short ReadDay() { short Day;     cout << "\nPlease enter a Day? ";     cin >> Day; return Day; } short ReadMonth() { short Month;     cout << "Please enter a Month? ";     cin >> Month; return Month; } short ReadYear() { short Year;     cout << "Please enter a Year? ";     cin >> Year; return Year; } stDate ReadFullDate() { stDate Date;     Date.Day = ReadDay();     Date.Month = ReadMonth();     Date.Year = ReadYear(); return Date; } 
int main() { stDate Date1 = ReadFullDate();     cout << "\nDate After: \n";     Date1 = DecreaseDateByOneDay(Date1);     cout << "\n01-Subtracting one day is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXDays(10, Date1);     cout << "\n02-Subtracting 10 days is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneWeek(Date1);     cout << "\n03-Subtracting one week is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXWeeks(10, Date1);     cout << "\n04-Subtracting 10 weeks is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneMonth(Date1);     cout << "\n05-Subtracting one month is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXMonths(5, Date1);     cout << "\n06-Subtracting 5 months is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneYear(Date1);     cout << "\n07-Subtracting one year is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXYears(10, Date1);     cout << "\n08-Subtracting 10 Years is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXYearsFaster(10, Date1);     cout << "\n09-Subtracting 10 Years (faster) is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneDecade(Date1);     cout << "\n10-Subtracting one Decade is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year; 
Date1 = DecreaseDateByXDecades(10, Date1);     cout << "\n11-Subtracting 10 Decades is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByXDecadesFaster(10, Date1);     cout << "\n12-Subtracting 10 Decade (faster) is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneCentury(Date1);     cout << "\n13-Subtracting One Century is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     Date1 = DecreaseDateByOneMillennium(Date1);     cout << "\n14-Subtracting One Millennium is: "        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;     system("pause>0"); return 0; } 


