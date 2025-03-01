/*
Problem 29 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy only prime numbers to another
array and print it.

Input:

10

Output:

Array 1 elements:

42 68 35 1 70 25 79 59 63 65

Prime Numbers in Array2:
179
=============================================================

*/

#include <iostream>
#include <cmath> // For round() function
using namespace std;

// Enum to represent whether a number is prime or not
enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};

// Function to check if a number is prime
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}

// Function to generate a random number within a given range
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function to copy only prime numbers from one array to another
void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }
    arr2Length = Counter; // Corrected to ensure accurate length
}

// Function to print the elements of an array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // Seed the random number generator to produce different results on each run
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    
    int arr2[100], arr2Length = 0;
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);
    
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    
    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
