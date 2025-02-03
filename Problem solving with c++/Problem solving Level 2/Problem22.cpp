/*
Problem 22 |=============================================================================

Write a program to read N elements and store them in array then print all array elements
and ask for a number to check, then print how many number a certain element repeated in
that array.

Input:

5

Enter array elements:

Element [1]: 1

Element [2]: 1

Element [3]: 1

Element [4]: 2

Element [5]: 3

Enter the number you want to check: 1

Output: 

Original array: 11123 
1 is repeated 3 time(s)
==========================================================================================
*/

#include <iostream>
using namespace std;

// Function to read a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;  // Display the prompt message
        cin >> Number;            // Read the user's input
    } while (Number <= 0);         // Repeat until the number is positive

    return Number;  // Return the positive number
}

// Function to read an array of integers
void ReadArray(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements for the array
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)  // Loop to read each element
    {
        cout << "Element [" << i + 1 << "] : ";  // Display prompt for each element
        cin >> arr[i];  // Read each array element
    }
    cout << endl;
}

// Function to print the array elements
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)  // Loop through the array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << "\n";
}

// Function to count how many times a specific number appears in the array
int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)  // Loop through the array
    {
        if (Number == arr[i])  // If the element matches the number
        {
            count++;  // Increment the count
        }
    }
    return count;  // Return the count of occurrences
}

int main()
{
    int arr[100], arrLength, NumberToCheck;

    // Read the array from the user
    ReadArray(arr, arrLength);

    // Read the number to check for repetitions
    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    // Display the original array
    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);

    // Display how many times the number is repeated in the array
    cout << "\nNumber " << NumberToCheck;
    cout << " is repeated ";
    cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";

    return 0;  // Exit the program
}

