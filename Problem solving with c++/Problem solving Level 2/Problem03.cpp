/*
Problem03 |===============================================

Write a program to check if the number is perfect or not?

Input : 
28
12

Output : 
28 is perfect. 
496 perfect.
==========================================================
*/

#include <iostream>
using namespace std;

// Enumeration to represent whether a number is a divisor or not
enum enmDivisorNotDivisor 
{ 
    Divisor = 1, 
    NotDivisor = 2 
};

// Function to read a positive number from the user
int RedPsitiveNumber(string message)
{
    int Number;
    do
    {
        cout << message; // Prompt the user with the given message
        cin >> Number;   // Read the input
    } while (Number < 0); // Ensure the number is positive
    return Number;
}

// Function to check if a number is a divisor of another
enmDivisorNotDivisor ChekDivisors(int Number, int Divisor)
{
    if (Number % Divisor == 0) // If divisible, return Divisor
        return enmDivisorNotDivisor::Divisor;

    return enmDivisorNotDivisor::NotDivisor; // Otherwise, return NotDivisor
}

// Function to check and print whether a number is a perfect number
void PrintPrefectNumber(int Number)
{
    int M = round(Number / 2); // Only check divisors up to half the number
    int SumNubPrime = 0; // Variable to store the sum of divisors

    // Iterate through potential divisors
    for (int Divisor = 1; Divisor <= M; Divisor++)
    {
        if (ChekDivisors(Number, Divisor) == enmDivisorNotDivisor::Divisor)
            SumNubPrime += Divisor; // Add the divisor to the sum
    }

    // Check if the sum of divisors equals the original number
    if (SumNubPrime == Number)
        cout << Number << " is Perfect." << endl; // It is a perfect number
    else
        cout << Number << " is not Perfect." << endl; // It is not a perfect number
}

int main()
{
    // Prompt the user for a number and check if it is a perfect number
    PrintPrefectNumber(RedPsitiveNumber("Enter a positive number to check if it is perfect or not: "));
}


