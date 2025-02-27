/*
Problem 50 |=================================================
Write a program to print Sqrt of numbers , don't use built in
sqrt function

Input: 
25

Output:

My MySqrt Result : 5
C++ sqrt Result: 5
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

