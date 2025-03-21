"""
Problem 45 |=================================================
Write a program fo fill array with max size 100 with random
numbers from -100 to 100, then print the count of Negative
numbers.

Input:
10

Output:

Array Elements: -58 -16 -21 -4 -91 82 98 66 -8 -33

Negative Numbers count is: 7
=============================================================
"""
#include <iostream>
using namespace std;

// Function to generate a random number between 'From' and 'To' (inclusive)
int RandomNumber(int From, int To)
{
    // Calculate and return a random number within the specified range
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill an array with random numbers
// Prompts the user to enter the number of elements, then fills the array with random numbers between -100 and 100
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    // Loop to populate the array with random numbers
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}

// Function to print the elements of the array
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Function to count negative numbers in the array
int NegativeCount(int arr[100], int arrLength)
{
    int Counter = 0;
    // Loop through the array to count negative numbers
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Display the array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Count and display the number of negative numbers in the array
    cout << "\nNegative Numbers count is: ";
    cout << NegativeCount(arr, arrLength) << endl;

    return 0;
}
