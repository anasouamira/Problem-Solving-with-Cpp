"""
Problem 41 |=================================================
Write a program to fill array with numbers, then check if it is Palindrome
array or not, Note: Palindrome array can be read the same from right to
left and from left fo right.

Input
10 20 30 30 20 10

Output:

Array Elements:
10 20 30 30 20 10

Yes array is Palindrome 
=============================================================
"""
#include <iostream>
using namespace std;

// Function to fill the array with predefined elements and set the length
void FillArray(int arr[100], int &arrLength)
{
    // Manually filling the array with the elements: 10, 20, 30, 30, 20, 10
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

// Function to print the elements of the array
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // New line after printing all elements
}

// Function to check if the array is a palindrome
bool IsPalindromeArray(int arr[100], int Length)
{
    // Loop to compare elements from the start and end moving towards the center
    for (int i = 0; i < Length; i++)
    {
        // If elements are not equal, the array is not a palindrome
        if (arr[i] != arr[Length - i - 1])
        {
            return false;
        }
    }
    // If all compared elements are equal, the array is a palindrome
    return true;
}

int main()
{
    // Declare an array with a maximum size of 100 and initialize Length to 0
    int arr[100], Length = 0;
    
    // Call the function to fill the array and determine its length
    FillArray(arr, Length);
    
    // Display the array elements
    cout << "\nArray Elements:\n";
    PrintArray(arr, Length);
    
    // Check if the array is a palindrome and display the result
    if (IsPalindromeArray(arr, Length))
        cout << "\nYes, array is Palindrome\n";
    else
        cout << "\nNo, array is NOT Palindrome\n";
    
    // Return 0 to indicate successful execution
    return 0;
}
