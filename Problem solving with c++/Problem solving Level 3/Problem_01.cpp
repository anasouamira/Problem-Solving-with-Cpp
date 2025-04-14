/*
Problem 01 |=================================================

Write a program to fill a 3x3 matrix with random numbers : 

Output : 

The following is a 3x3 random matrix:

16 43 6
13 51 3 
24 19 100 

=============================================================
*/
#include <iostream>
#include <cmath> // Include cmath for sqrt and pow
using namespace std;

// Function to calculate the square root of a number
float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

// Function to read a number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

int main()
{
    float Number = ReadNumber();
    
    // Display results using custom and built-in sqrt functions
    cout << "My MySqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ sqrt Result: " << sqrt(Number) << endl;
    
    return 0;
}