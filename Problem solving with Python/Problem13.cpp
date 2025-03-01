/*
Problem13 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
1
22
333
4444
55555
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

// Function to print a right-aligned pattern of numbers
void PrintInvertedPattern(short Number)
{
    // Loop to print each row of the pattern
    for (short i = 1; i <= Number; i++)  // Start from 1 and go up to the given number
    {
        // Print the number 'i' exactly 'i' times
        for (short j = 1; j <= i; j++)
            cout << i;
        cout << endl;  // Move to the next line after printing each row
    }
}

int main()
{
    // Read a positive number and print the pattern
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern: "));
}

