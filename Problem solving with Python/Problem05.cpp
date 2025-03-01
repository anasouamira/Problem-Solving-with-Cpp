
/*
Problem05 |===============================================

Write a program to read a number and print it in a reversed
order. 

Input : 
1234

Output : 
4
3
2
1
==========================================================
*/



#include <iostream>
using namespace std;

// Function to read a positive number from the user
int RedNumberPositive(string message) {
    int Number;
    do
    {
        cout << message; // Prompt the user with the given message
        cin >> Number;   // Read the input
    } while (Number < 0); // Ensure the number is positive
    return Number;
}

// Function to print the digits of a number in reverse order
void ChekRemainder(int Number) {
    int Remainder;
    do
    {
        Remainder = Number % 10; // Extract the last digit of the number
        Number = Number / 10;    // Remove the last digit from the number
        cout << Remainder;       // Print the extracted digit
    } while (Number > 0);        // Repeat until all digits are processed
}

int main()
{
    // Read a positive number and print its digits in reverse order
    ChekRemainder(RedNumberPositive("Enter a number to print it in reversed order: "));

    return 0;
}
