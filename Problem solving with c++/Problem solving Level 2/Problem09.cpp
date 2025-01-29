/*
Problem09 |===============================================

Write a program to read a number, then print all digit
frequency in that number

Input : 
1223222

Output :

Digit 1 Frequency is 1 Time(s).
Digit 2 Frequency is 5 Time(s).
Digit 3 Frequency is 1 Time(s).

==========================================================
*/


#include <iostream>
using namespace std;

// Function to read a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

// Function to count the frequency of a specific digit in a given number
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int FreqCount = 0, Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10; // Extract the last digit
        Number = Number / 10;    // Remove the last digit
        if (DigitToCheck == Remainder)
        {
            FreqCount++; // Increment the frequency counter if digit matches
        }
    }
    return FreqCount;
}

// Function to print the frequency of each digit (1-9) in a given number
void PrintDigitFrequency(int Number)
{
    for (int DigitToCheck = 1; DigitToCheck <= 9; DigitToCheck++)
    {
        short DigitFrequency = CountDigitFrequency(DigitToCheck, Number);

        if (DigitFrequency > 0)
        {
            cout << "\nDigit " << DigitToCheck << " Frequency is " << DigitFrequency << " Time(s).\n";
        }
    }
}

int main()
{
    // Read a positive number from the user and print its digit frequency
    PrintDigitFrequency(ReadPositiveNumber("Please enter the main number ? "));
    return 0;
}

