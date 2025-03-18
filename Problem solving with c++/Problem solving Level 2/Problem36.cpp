/*
Problem 36 |=================================================
Write a program to dynamically read numbers and save them in an array
Max size of array is 100, allocate simi-dynamic array length.

Output:

Please enter a number? 10

Do you want to add more numbers? [0] No,[1] yes? 1
Please enter a number? 20

Do you want to add more numbers? [0] No,[1] yes? 1
Please enter a number? 30

Do you want to add more numbers? [0] No [1] yes? 0

Array Length: 3
Array elements: 10 20 30 
=============================================================
*/
#include <iostream>
using namespace std;

// Function to read an integer number from the user
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number? ";
    cin >> Number;
    return Number;
}

// Function to add an element to the array and increase its length
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // It's a new element, so we need to increase the length by 1
    arrLength++;
    arr[arrLength - 1] = Number; // Add the number at the new position
}

// Function to allow the user to input multiple numbers into the array
void InputUserNumbersInArray(int arr[100], int &arrLength)
{
    bool AddMore = true; // Flag to control user input loop
    do
    {
        // Read a number from the user and add it to the array
        AddArrayElement(ReadNumber(), arr, arrLength);
        
        // Ask the user if they want to add more numbers
        cout << "\nDo you want to add more numbers? [0]:No,[1]:Yes? ";
        cin >> AddMore;
    } while (AddMore); // Continue if the user chooses to add more numbers
}

// Function to print all elements of the array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " "; // Print each element separated by a space
    cout << "\n";
}

int main()
{
    int arr[100], arrLength = 0; // Declare array and initialize its length
    
    // Get user input to fill the array
    InputUserNumbersInArray(arr, arrLength);
    
    // Display the array length and elements
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);
    
    return 0; // Return success code
}
