/*
Problem 09 |=============================================================================================

Write a program to print Year
Calendar.

Please enter a year? 2025

Output : 
 __________________________________

              2025

 __________________________________

 _______________Jan_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29   30   31
 _________________________________

 _______________Feb_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                                  1
    2    3    4    5    6    7    8
    9   10   11   12   13   14   15
   16   17   18   19   20   21   22
   23   24   25   26   27   28
 _________________________________

 _______________Mar_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                                  1
    2    3    4    5    6    7    8
    9   10   11   12   13   14   15
   16   17   18   19   20   21   22
   23   24   25   26   27   28   29
   30   31
 _________________________________

 _______________Apr_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
              1    2    3    4    5
    6    7    8    9   10   11   12
   13   14   15   16   17   18   19
   20   21   22   23   24   25   26
   27   28   29   30
 _________________________________

 _______________May_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                        1    2    3
    4    5    6    7    8    9   10
   11   12   13   14   15   16   17
   18   19   20   21   22   23   24
   25   26   27   28   29   30   31

 _________________________________

 _______________Jun_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
    1    2    3    4    5    6    7
    8    9   10   11   12   13   14
   15   16   17   18   19   20   21
   22   23   24   25   26   27   28
   29   30
 _________________________________

 _______________Jul_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
              1    2    3    4    5
    6    7    8    9   10   11   12
   13   14   15   16   17   18   19
   20   21   22   23   24   25   26
   27   28   29   30   31
 _________________________________

 _______________Aug_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                             1    2
    3    4    5    6    7    8    9
   10   11   12   13   14   15   16
   17   18   19   20   21   22   23
   24   25   26   27   28   29   30
   31
 _________________________________

 _______________Sep_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
         1    2    3    4    5    6
    7    8    9   10   11   12   13
   14   15   16   17   18   19   20
   21   22   23   24   25   26   27
   28   29   30
 _________________________________

 _______________Oct_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29   30   31
 _________________________________

 _______________Nov_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                                  1
    2    3    4    5    6    7    8
    9   10   11   12   13   14   15
   16   17   18   19   20   21   22
   23   24   25   26   27   28   29
   30
 _________________________________

 _______________Dec_______________

  Sun  Mon  Tue  Wed  Thu  Fri  Sat
         1    2    3    4    5    6
    7    8    9   10   11   12   13
   14   15   16   17   18   19   20
   21   22   23   24   25   26   27
   28   29   30   31
 _________________________________

==========================================================================================================
*/
#include <iostream> // for input/output operations
using namespace std;

// Function to check if a given year is a leap year
bool isLeapYear(short Year)
{
    // A leap year is divisible by 4 and not divisible by 100
    // or divisible by 400
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the day of the week for a specific date
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    // Adjust month and year for Zeller's Congruence
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // Return day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

// Function to get the short name of a day from its index
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    return arrDayNames[DayOfWeekOrder];
}

// Function to get the number of days in a month, considering leap years
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0; // Invalid month

    // Number of days in each month for a normal year
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // If it's February, check for leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to get the short name of a month from its number
string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar",
                          "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep",
                          "Oct", "Nov", "Dec" };

    return Months[MonthNumber - 1];
}

// Function to print the calendar of a specific month and year
void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;

    int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
        printf("     "); // 5 spaces to align dates properly

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j); // Print day with width 5
        if (++i == 7) // If end of week is reached
        {
            i = 0; // Reset counter for new line
            printf("\n");
        }
    }

    // Print footer line
    printf("\n _________________________________\n");
}



void PrintYearCalendar(short Year) {

    cout << "\n __________________________________\n";
    cout << "\n              " << Year << "\n";
    cout << "\n __________________________________\n";

    for (short Month = 1; Month <= 12; Month++ ) {
        PrintMonthCalendar(Month,Year);
    }


}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read year from user
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

// Main function: entry point of the program
int main()
{
    short Year = ReadYear();   // Get year from user

    PrintYearCalendar(Year);
    system("pause>0"); // Wait for user to press a key (Windows only)
    return 0;
}


