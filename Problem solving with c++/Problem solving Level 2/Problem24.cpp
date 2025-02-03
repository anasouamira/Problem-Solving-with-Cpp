/*
Problem 24 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Max 

Input:
10

Output:

Array Elements: 65 91 54 42 75 32 53 57 57 30
Max Number is : 91
=============================================================

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

// Function to find the maximum number in the array
int MaxNumberInArray(int arr[100], int arrLength)
{
    int Max = 0;  // Initialize Max as 0 (assuming positive numbers in array)
    for (int i = 0; i < arrLength; i++)  // Loop through the array
    {
        if (arr[i] > Max)  // If the current element is greater than the current Max
        {
            Max = arr[i];  // Update Max with the new largest number
        }
    }
    return Max;  // Return the largest number found in the array
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nMax Number is : ";
    cout << MaxNumberInArray(arr, arrLength) << endl;
    return 0;
}
