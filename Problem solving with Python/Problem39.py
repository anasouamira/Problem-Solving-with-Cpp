
Problem 39 |========================================================================
Write a program to fill array with max size 100 with random numbers from
110 100, copy only prime numbers fo another array using AddArrayElement,and print it.

Input
10

Output:

Array 1 elements:
61 100 32 75 81 95 50 98 13 70

Array 2 Prime numbers:
62 13
=============================================================


#include <iostream>
using namespace std;

// Enum to indicate if a number is Prime or Not Prime
enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};

// Function to check if a given number is prime
// Parameters: int Number - the number to be checked
// Returns: enPrimNotPrime - Prime if the number is prime, NotPrime otherwise
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2); // Check divisibility up to half of the number
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0) // If divisible by any number other than 1 and itself
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime; // Number is prime
}

// Function to generate a random number within a given range
// Parameters: int From - start of the range, int To - end of the range
// Returns: int - a random number within the range [From, To]
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill an array with random numbers
// Parameters: int arr[100] - the array to fill
//             int &arrLength - the number of elements to generate
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100); // Fill array with random numbers from 1 to 100
}

// Function to print elements of an array
// Parameters: int arr[100] - the array to print
//             int arrLength - the number of elements in the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to add an element to the end of an array
// Parameters: int Number - the number to add
//             int arr[100] - the array to add to
//             int &arrLength - the current length of the array, updated after addition
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arrLength++; // Increase the length of the array
    arr[arrLength - 1] = Number; // Add the number at the end of the array
}

// Function to copy prime numbers from one array to another
// Parameters: int arrSource[100] - source array to copy from
//             int arrDestination[100] - destination array to copy to
//             int arrLength - length of the source array
//             int &arrDestinationLength - length of the destination array, updated after copying
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100],
                        int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0, arr2Length = 0;
    int arr2[100]; // Array to store prime numbers

    // Fill the first array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Copy prime numbers from the first array to the second array
    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    // Display the original array
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Display the array containing prime numbers
    cout << "\nArray 2 Prime numbers:\n";
    PrintArray(arr2, arr2Length);

    return 0;
}
