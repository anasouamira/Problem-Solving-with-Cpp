"""
Problem 49 |=================================================
Write a program to print Ceil of numbers , don't use built in Ceil
function

Input: 
10.7

Output: 
My Round Result : 11
C++ Round Result: 11

Input:
-10.7

Output:
My Round Result : -10
C++ Round Result: -10
=============================================================
"""

#include <iostream>
#include <cmath> // Include cmath for ceil()
using namespace std;

// Function to get the fractional part of a floating-point number
float GetFractionPart(float Number)
{
    return Number - int(Number);
}

// Custom implementation of ceil function
int MyCeil(float Number)
{
    int integerPart = int(Number); // Get integer part
    if (Number > 0 && GetFractionPart(Number) > 0) 
        return integerPart + 1;
    return integerPart;
}

// Function to read a number from user input
float ReadNumber()
{
    float Number;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

// Main function
int main()
{
    float Number = ReadNumber();
    cout << "My MyCeil Result: " << MyCeil(Number) << endl;
    cout << "C++ ceil Result: " << ceil(Number) << endl;
    return 0;
}

