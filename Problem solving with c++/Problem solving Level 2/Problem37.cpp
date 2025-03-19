/*
Problem 37 |=================================================
Write a program to fill array with max size 100 with random numbers from
1 to 100, copy it to another array using AddArrayElement, and print it.

Input
10 

Output:

Array 1 elements:

1 47 51 18 85 62 51 61 82 4

Array 2 elements after copy:

1 47 51 18 85 62 51 61 82 4
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

// Function to copy elements from one array to another using AddArrayElement function
void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
}

int main()
{
    // Seeds the random number generator with the current time
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength = 0, arr2Length = 0;
    FillArrayWithRandomNumbers(arr, arrLength);
    
    int arr2[100];
    CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);
    
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
