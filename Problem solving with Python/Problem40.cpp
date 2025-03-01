/*
Problem 40 |=================================================
Write a program to fill array with numbers, then print distinct
numbers to another array.

Output:

Array 1 elements:

10 10 10 50 50 70 70 70 70 90

Array 2 distinct elements:
10 50 70 90
=============================================================
*/
#include <iostream>
using namespace std;

// Function to fill the array with predefined numbers
// Parameters: int arr[100] - the array to fill
//             int &arrLength - the length of the array, set to 10
void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10; // Set array length to 10
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

// Function to print the elements of the array
// Parameters: int arr[100] - the array to print
//             int arrLength - the number of elements in the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to find the position of a number in an array
// Parameters: int Number - the number to search for
//             int arr[100] - the array to search in
//             int arrLength - the length of the array
// Returns: short - the index of the number if found, -1 if not found
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // Return the index if the number is found
    }
    // If the number is not found, return -1
    return -1;
}

// Function to check if a number exists in an array
// Parameters: int Number - the number to check
//             int arr[100] - the array to check in
//             int arrLength - the length of the array
// Returns: bool - true if the number is found, false otherwise
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

// Function to add an element to the end of an array
// Parameters: int Number - the number to add
//             int arr[100] - the array to add to
//             int &arrLength - the current length of the array, updated after addition
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++; // Increase the length of the array
    arr[arrLength - 1] = Number; // Add the number at the end of the array
}

// Function to copy distinct numbers from one array to another
// Parameters: int arrSource[100] - source array to copy from
//             int arrDestination[100] - destination array to copy to
//             int SourceLength - length of the source array
//             int &DestinationLength - length of the destination array, updated after copying
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], 
                                int SourceLength, int& DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        // If the number is not already in the destination array, add it
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main()
{
    int arrSource[100], SourceLength = 0;
    int arrDestination[100], DestinationLength = 0;

    // Fill the source array with predefined numbers
    FillArray(arrSource, SourceLength);

    // Print the original array
    cout << "\nArray 1 elements:\n";
    PrintArray(arrSource, SourceLength);

    // Copy distinct numbers to the destination array
    CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);

    // Print the array with distinct elements
    cout << "\nArray 2 distinct elements:\n";
    PrintArray(arrDestination, DestinationLength);

    return 0;
}
