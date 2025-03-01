/*
Problem11 |===============================================

Write a program to read a number and check if is Palindrome?

Input : 
1234
12321

Output : 
No, it is Not a Palindrome number.
Yes, it is a Palindrome number.
==========================================================
*/

#include <iostream>
using namespace std;

// Function to read a positive number from the user
int RedPositiveNumbers(string message)
{
    int Number;
    do
    {
        cout << message;  // Display the message prompt
        cin >> Number;    // Read user input
    } while (Number < 0);  // Ensure the input is positive
    return Number;
}

// Function to reverse the digits of a given number
int ReversNumber(int Number)
{
    short Remainder = 0;
    int Revers = 0;

    // Reverse the number by extracting and appending digits
    while (Number > 0)
    {
        Remainder = Number % 10;    // Extract the last digit
        Number = Number / 10;       // Remove the last digit from the number
        Revers = Revers * 10 + Remainder;  // Build the reversed number
    }
    return Revers;
}

// Function to check if a number is a palindrome
string CheckPalindromeNumber(int Number, int ReversNumber)
{
    // Compare the original number with its reversed version
    if (Number == ReversNumber)
        return "Yes, it is a Palindrome number.";  // It is a palindrome
    return "No, it is a NOT Palindrome number.";   // It is not a palindrome
}

int main()
{
    // Read a positive number and check if it is a palindrome
    int Number = RedPositiveNumbers("Enter Number to check if it is a Palindrome Number: ");
    int Revers_Number = ReversNumber(Number);

    // Output the result
    cout << CheckPalindromeNumber(Number, Revers_Number) << endl;
}
