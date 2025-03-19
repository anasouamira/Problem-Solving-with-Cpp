"""
Problem 45 |=================================================
Write a program fo fill array with max size 100 with random
numbers from -100 to 100, then print the count of Positive 
numbers.
Input:
10

Output:
Array Elements: 17 -9 -9 -90 -72 -100 -4 60 -84 -15

Positive Numbers count is: 2 
=============================================================

"""#include <iostream>
using namespace std;

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To)
{
    // Calculate a random number in the specified range
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill the array with random numbers
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    // Prompt the user to enter the number of elements in the array
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    
    // Fill the array with random numbers between -100 and 100
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}

// Function to print the elements of the array
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // New line after printing all elements
}

// Function to count the number of positive numbers (including zero) in the array
int PositiveCount(int arr[100], int arrLength)
{
    // Initialize a counter for positive numbers
    int Counter = 0;
    
    // Loop through the array and check each element
    for (int i = 0; i < arrLength; i++)
    {
        // If the element is positive or zero, increment the counter
        if (arr[i] >= 0)
        {
            Counter++;
        }
    }
    // Return the total count of positive numbers
    return Counter;
}

int main()
{
    // Seed the random number generator to ensure different random numbers each run
    srand((unsigned)time(NULL));
    
    // Declare an array with a maximum size of 100 and a variable for its length
    int arr[100], arrLength;
    
    // Call the function to fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);
    
    // Display the array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    
    // Display the count of positive numbers in the array
    cout << "\nPositive Numbers count is: ";
    cout << PositiveCount(arr, arrLength) << endl;
    
    // Return 0 to indicate successful execution
    return 0;
}
