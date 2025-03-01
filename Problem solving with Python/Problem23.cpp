/*
Problem 23 |==================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100.

Input:
10 

Output:

Array Elements: 56 55 83 71 32 52 17 28 71 52
==============================================================

*/
#include <iostream>
using namespace std;

// Function to generate a random number between 'From' and 'To'
int RandomNumber(int From, int To)
{
    // Generate random number in the range [From, To]
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements for the array
    for (int i = 0; i < arrLength; i++)  // Loop through the array to assign random numbers
        arr[i] = RandomNumber(1, 100);  // Fill each array element with a random number in the range [1, 100]
}

// Function to print the array elements
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)  // Loop through the array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << "\n";
}

int main()
{
    // Seeds the random number generator in C++, called only once at the start
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    return 0;  // Exit the program
}
