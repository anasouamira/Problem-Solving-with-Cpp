
"""
Problem02 |===============================================

Write a program to print all prime number From 1 to N 
order. 

Input : 
10

Output : 
1
2
3
5
7
==========================================================
"""
include <iostream>
include <cmath> // For round function
using namespace std;

// Enumeration to represent whether a number is Prime or Not Prime
enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};

// Function to read a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl; // Prompt the user with the given message
        cin >> Number;           // Read the number from the user
    } while (Number <= 0);       // Ensure the number is positive
    return Number;
}

// Function to check if a number is prime
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2); // Only check divisors up to half the number
    for (int Counter = 2; Counter <= M; Counter++) // Iterate over potential divisors
    {
        if (Number % Counter == 0) // If divisible, the number is not prime
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime; // If no divisors found, the number is prime
}

// Function to print all prime numbers from 1 to a given number
void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    // Check each number from 1 to the given number
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrime::Prime) // Check if the number is prime
        {
            cout << i << endl; // Print the prime number
        }
    }
}

int main()
{
    // Read a positive number and print all prime numbers up to that number
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? "));
    return 0;
}


