/*
Problem 26 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print sum of all number

Input:
10

Output:

Array Elements: 10 6 22 40 12 75 23 32 25 75
Sum of all numbers:320
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
    for (int i = 0; i < arrLength; i++)  // Loop through the array to assign random numbers
        arr[i] = RandomNumber(1, 100);  // Fill each array element with a random number in the range [1, 100]
}

// Function to print the array elements
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)  // Loop through the array
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << "\n";  // Print a newline after printing the entire array
}

// Function to calculate the sum of all elements in the array
int SumArray(int arr[100], int arrLength)
{
    int Sum = 0;  // Initialize Sum to 0
    for (int i = 0; i < arrLength; i++)  // Loop through the array
    {
        Sum += arr[i];  // Add each element's value to the sum
    }
    return Sum;  // Return the total sum of the array
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
    
    // Calculate and print the sum of the array elements
    cout << "\nSum of all numbers is : "; 
    cout << SumArray(arr, arrLength) << endl; 
    
    return 0;  // Exit the program
} 
