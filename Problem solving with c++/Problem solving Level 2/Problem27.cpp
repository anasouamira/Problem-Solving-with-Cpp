/*
Problem 27 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print average of all number

Input:
10

Output:

Array Elements: 24 36 44 73 8 56 98 67 33 71

Average of all number is : 51
=============================================================

*/
#include <iostream>
using namespace std;

// Function to generate a random number between 'From' and 'To'
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    // Function to fill the array with random numbers
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements for the array
    for (int i = 0; i < arrLength; i++)  // Loop to assign random numbers to array elements
        arr[i] = RandomNumber(1, 100);  // Fill each element with a random number in the range [1, 100]
}

// Function to print the array elements
void PrintArray(int arr[100], int arrLength)
{
    // Function to print the array elements
    for (int i = 0; i < arrLength; i++)  // Loop through the array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << "\n";  // Print a newline after printing the entire array
}

// Function to calculate the sum of all elements in the array
int SumArray(int arr[100], int arrLength)
{
    // Function to calculate the sum of all elements in the array
    int Sum = 0;  // Initialize Sum to 0
    for (int i = 0; i < arrLength; i++)  // Loop through the array
    {
        Sum += arr[i];  // Add each element's value to the sum
    }
    return Sum;  // Return the total sum of the array
}

// Function to calculate the average of all elements in the array
float ArrayAverage(int arr[100], int arrLength)
{
    // Function to calculate the average of all elements in the array
    return (float)SumArray(arr, arrLength) / arrLength;  // Return the sum divided by the array length as a float
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    
    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);
    
    // Print the array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    
    // Calculate and print the average of the array elements
    cout << "\nAverage of all numbers is : ";
    cout << ArrayAverage(arr, arrLength) << endl;
    
    return 0;  // Exit the program
}
