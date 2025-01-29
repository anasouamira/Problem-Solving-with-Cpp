/*
Problem06 |===============================================

Write a program to read a number and print all the sum of
its digits

Input : 
1234

Output :

sum of Digit = 10

==========================================================
*/


#include <iostream>
using namespace std;

/**
 * Function to read a positive integer from the user.
 * It ensures that the number entered is non-negative.
 *
 * @param message - The prompt message displayed to the user.
 * @return The validated positive integer.
 */
int ReadNumberPositive(string message) {
    int Number;
    do {
        cout << message;
        cin >> Number;
    } while (Number < 0); // Loop until a non-negative number is entered
    return Number;
}

/**
 * Function to calculate and print the sum of the digits of a given number.
 *
 * @param Number - The number whose digits will be summed.
 */
void CheckSumRemainder(int Number) {
    int Remainder;
    int SumRemainder = 0;
    do {
        Remainder = Number % 10; // Extract the last digit
        SumRemainder += Remainder; // Add it to the sum
        Number = Number / 10; // Remove the last digit
    } while (Number > 0);

    cout << "Sum of digits: " << SumRemainder << endl;
}

/**
 * Main function - Entry point of the program.
 * It asks the user for input and calculates the sum of its digits.
 */
int main() {
    // Read a positive number and pass it to CheckSumRemainder function
    CheckSumRemainder(ReadNumberPositive("Enter a positive number to calculate the sum of its digits: "));

    return 0;
}

