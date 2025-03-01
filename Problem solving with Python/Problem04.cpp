/*
Problem04 |===============================================

Write a program to print all perfect number From 1 to N 
order. 

Input : 
500

Output : 
6
28
496
==========================================================
*/



#include <iostream>
using namespace std;

// Enumeration to represent whether a number is Perfect or Not Perfect
enum enmPrefectNotPerfect
{
    Prefect = 1,
    NotPrefect = 2
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

// Function to check if a given number is a perfect number
enmPrefectNotPerfect CheckPrefectNumber(int Number)
{
    int M = round(Number / 2); // Only check divisors up to half the number
    int SumNubPrime = 0;       // Variable to store the sum of divisors

    // Iterate through potential divisors
    for (int Divisor = 1; Divisor <= M; Divisor++)
    {
        if (Number % Divisor == 0) // Check if Divisor divides Number
            SumNubPrime += Divisor; // Add Divisor to the sum
    }

    // Check if the sum of divisors equals the original number
    if (SumNubPrime == Number)
        return enmPrefectNotPerfect::Prefect; // It is a perfect number

    return enmPrefectNotPerfect::NotPrefect; // It is not a perfect number
}

// Function to print all perfect numbers from 1 to the given number
void PrintPrefectNumber(int Number)
{
    // Iterate through numbers from 1 to the given number
    for (int counter = 1; counter <= Number; counter++)
    {
        // Check if the current number is a perfect number
        if (CheckPrefectNumber(counter) == enmPrefectNotPerfect::Prefect)
            cout << counter << endl; // Print the perfect number
    }
}

int main()
{
    // Prompt the user for a number and print all perfect numbers from 1 to that number
    PrintPrefectNumber(RedPsitiveNumber("Enter a positive number to find all perfect numbers from 1 to N: "));
}
