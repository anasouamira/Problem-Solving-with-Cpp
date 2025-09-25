#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads a positive number of hours from the user
// and converts it into equivalent number of days and weeks.


// Function to read a positive number from the user
int RedNumberPositive(string message) {
    int Nub = 0;
    do {
        cout << message;
        cin >> Nub;
        if (Nub < 0) {
            cout << "Invalid input! Please enter a positive number." << endl;
        }
    } while (Nub < 0); // Repeat until a positive number is entered
    return Nub;
}

// Function to convert hours to days
float NumberOfHoursOfDay(float Nub) {
    return Nub / 24.0; // 1 day = 24 hours
}

// Function to convert hours to weeks
float NumberOfHoursOfWeek(float Nub) {
    return Nub / 168.0; // 1 week = 7 days = 168 hours
}

int main() {
    int Hours = RedNumberPositive("Enter Number of Hours: ");

    // Print equivalent days and weeks
    cout << NumberOfHoursOfDay(Hours) << " Day(s)" << endl;
    cout << NumberOfHoursOfWeek(Hours) << " Week(s)" << endl;

    return 0;
}
