/*
Problem 32 |=================================================
Write a program to fill array with max size 100 with random numbers from
1t0 100, copy it to another array in reverse order and print it.

Input
10

Output:
Array 1 elements:
64 8 62 19 2 21 15 74 96 85

Array 2 elements after copying array 1 in reversed order: 
85 96 74 15 21 2 19 62 8 64
=============================================================
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength; // User inputs the array length

    // Fill the array with random numbers between 1 and 100
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function to print the elements of an array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to copy an array into another in reverse order
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i]; // Copying in reverse order
}

int main()
{
    // Seeds the random number generator using the current time
    srand((unsigned)time(NULL));

    // Declare an array and its length variable
    int arr[100], arrLength;

    // Fill the first array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Declare a second array for storing the reversed copy
    int arr2[100];

    // Copy elements of arr into arr2 in reverse order
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    // Display elements of the first array
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Display elements of the second array after copying in reverse
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength);

    return 0;
}
