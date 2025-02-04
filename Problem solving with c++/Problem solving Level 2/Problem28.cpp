/*
Problem 28 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy it to another array and print it.

Input
10

Output:

Array 1 elements: 1 47 51 18 85 62 51 61 82 4

Array 2 elements after copy: 1 47 51 18 85 62 51 61 82 4
=============================================================

*/

#include <iostream>
#include <ctime> // For time() function
using namespace std;

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
    cin >> arrLength; // Read the number of elements from user
    
    // Populate the array with random numbers in the range [1, 100]
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

// Function to copy elements from source array to destination array
void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}

int main()
{
    // Seed the random number generator to produce different results on each run
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength); // Fill the first array with random numbers
    
    int arr2[100];
    CopyArray(arr, arr2, arrLength); // Copy elements from arr to arr2
    
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength); // Print the first array
    
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength); // Print the copied array
    
    return 0;
}

