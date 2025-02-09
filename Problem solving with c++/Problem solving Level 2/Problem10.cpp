/*
Problem10 |===============================================

Write a program to read a number and print it in order from 
left to right.

Input : 
1234

Output : 
1
2
3
4
==========================================================
*/

#include <iostream>
#include <string>
using namespace std;

// Function to read a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl; // Display message prompt
        cin >> Number;           // Read user input
    } while (Number <= 0);       // Ensure input is positive
    return Number;
}

// Function to reverse the digits of a given number
int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;       // Extract last digit
        Number = Number / 10;          // Remove last digit from number
        Number2 = Number2 * 10 + Remainder; // Append digit to reversed number
    }
    return Number2;
}

// Function to print the digits of a number one by one
void PrintDigits(int Number)
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10; // Extract last digit
        Number = Number / 10;    // Remove last digit
        cout << Remainder << endl; // Print the digit
    }
}

int main()
{
    // Read a positive number, reverse it, and print its digits
    PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number ? ")));
    return 0;
}

