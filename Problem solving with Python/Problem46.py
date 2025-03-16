/*
Problem 46 |====================================================
Write a program to print abs of numbers , don't use built in abs 
function 

Input:
-10

Output:

My abs Result : 10
C++ abs Result: 10
================================================================
*/
#include <iostream>
using namespace std;

// Function to calculate the absolute value of a number
// Returns the positive value of the input number
float MyABS(float Number)
{
    // Check if the number is positive
    if (Number > 0)
        return Number;
    else
        // If negative, multiply by -1 to make it positive
        return Number * -1;
}

// Function to prompt the user to enter a number
// Reads and returns a floating-point number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a number?";
    cin >> Number;
    return Number;
}

int main()
{
    // Read a number from the user
    float Number = ReadNumber();

    // Display the result of custom absolute value function
    cout << "My abs Result : " << MyABS(Number) << endl;

    // Display the result of the built-in C++ abs function
    cout << "C++ abs Result: " << abs(Number) << endl;

    return 0;
}
