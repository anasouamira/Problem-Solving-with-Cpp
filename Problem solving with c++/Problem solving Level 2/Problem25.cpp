/*
Problem 25 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Minimum Number 

Input:
10 

Output:
Array Elements: 30 99 72 47 95 67 29 13 80 64 
Min Number is: 13 
=============================================================

*/
#include <iostream>
using namespace std;

// Function to generate a random number between 'From' and 'To'
int RandomNumber(int From, int To)
{
    // Generate a random number in the range [From, To]
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number
}

// Function to fill an array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements for the array
    for (int i = 0; i < arrLength; i++)  // Loop to fill the array with random numbers
        arr[i] = RandomNumber(1, 100);  // Assign each element a random number in the range [1, 100]
}

// Function to print the array elements
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)  // Loop through the array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << "\n";  // Print a newline after printing the entire array
}

// Function to find the minimum number in the array
int MinNumberInArray(int arr[100], int arrLength)
{
    int Min = arr[0];  // Initialize Min to the first element of the array
    for (int i = 1; i < arrLength; i++)  // Start from the second element
    {
        if (arr[i] < Min)  // If the current element is smaller than Min
        {
            Min = arr[i];  // Update Min with the new smaller element
        }
    }
    return Min;  // Return the smallest number found in the array
}

int main()
{
    // Seeds the random number generator in C++, called only once at the start
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nMin Number is : ";
    cout << MinNumberInArray(arr, arrLength) << endl;

    return 0; 
}

