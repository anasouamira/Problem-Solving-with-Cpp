/*
Problem08 |===============================================

Write a program to read a number and Digit, then print all 
digit frequency in that number

Input : 
1223222
2

Output :

Digit 2 Frequency is 5 Time(s).

==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

/**
 * Structure to hold a number and a specific digit to be searched within the number.
 */
struct strNumber_Digit {
    int Number, Digit;
};

/**
 * Function to read a positive number and a digit from the user.
 * Ensures that both the number and digit are non-negative before returning the struct.
 *
 * @param Red - Reference to a struct containing the number and digit.
 * @return The updated struct with user-input values.
 */
strNumber_Digit ReadNumber_And_Digit(strNumber_Digit &Red) {
    do {
        cout << "Enter a positive number: ";
        cin >> Red.Number;
        cout << "Enter a digit: ";
        cin >> Red.Digit;
    } while (Red.Number < 0 || Red.Digit < 0); // Ensure inputs are non-negative

    return Red;
}

/**
 * Function to count the occurrences of a specific digit within a given number.
 *
 * @param Red - Struct containing the number and the digit to be counted.
 * @return The frequency of the digit within the number.
 */
int DigitFrequency(strNumber_Digit Red) {
    int Remainder;
    int SumDigit = 0;
    do {
        Remainder = Red.Number % 10; // Extract the last digit
        Red.Number = Red.Number / 10; // Remove the last digit
        if (Remainder == Red.Digit)
            SumDigit++; // Increment count if digit matches
    } while (Red.Number > 0);

    return SumDigit;
}

/**
 * Main function - Entry point of the program.
 * It reads a number and a digit, then calculates how many times the digit appears in the number.
 */
int main() {
    strNumber_Digit Red;
    cout << "Digit " << Red.Digit << " Frequency is " << DigitFrequency(ReadNumber_And_Digit(Red)) << " times" << endl;

    return 0;
}

