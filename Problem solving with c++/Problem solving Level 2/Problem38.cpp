/*
Problem 38 |======================================================================
Write a program to fill array with max size 100 with random numbers from
110 100, copy only odd numbers to another array using AddArrayElement,and print it.

Input
10 

Output: 

Array 1 elements: 
59 14 84 36 6 51 48 91 96 67 

Array 2 Odd numbers: 
59 51 91 67 
=============================================================
*/
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to generate a random number in the given range
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100); // Generates a random number between 1 and 100
}

// Function to print the elements of an array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to add an element to the array
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // Increase the length of the array to accommodate the new element
    arrLength++;
    arr[arrLength - 1] = Number;
}

// Function to copy only odd numbers from one array to another
void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (arrSource[i] % 2 != 0) // Check if the number is odd
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
}

int main()
{
    // Seeds the random number generator with the current time
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength = 0, arr2Length = 0;
    FillArrayWithRandomNumbers(arr, arrLength);
    
    int arr2[100];
    CopyOddNumbers(arr, arr2, arrLength, arr2Length);
    
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 Odd numbers:\n";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
