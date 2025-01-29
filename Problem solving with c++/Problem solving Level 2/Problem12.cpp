/*
Problem12 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
55555
4444
333
22
1
==========================================================
*/


#include <iostream>
using namespace std;

// Function to read a positive short number from the user
short RedNumberPsitive(string message)
{
    short Number;
    do
    {
        cout << message;  // Display the message prompt
        cin >> Number;    // Read user input
    } while (Number < 0);  // Ensure the input is positive
    return Number;
}

// Function to print an inverted pattern of numbers
void PrintInvertedPattern(short Number)
{
    // Loop to print each row of the inverted pattern
    for (short i = Number; i > 0; i--)  // Start from 'Number' and decrement
    {
        // Print the number 'i' exactly 'i' times
        for (short j = 1; j <= i; j++)
            cout << i;
        cout << endl;  // Move to the next line after printing each row
    }
}

int main()
{
    // Read a positive number and print its inverted pattern
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern: "));
}

