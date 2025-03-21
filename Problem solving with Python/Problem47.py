"""
Problem 47 |==================================================
Write a program to print round of numbers , don't use built in
round function

Input: 
10.7

Output: 
My Round Result : 11 
C++ Round Result: 11

Input:
10.3

Output:
My Round Result : 10
C++ Round Result: 10

Input:
-10.7

Output:
My Round Result : -11
C++ Round Result: -11
==============================================================
"""

#include <iostream>
using namespace std;

// Function to get the fractional part of a floating-point number
// Example: If Number = 4.75, it returns 0.75
float GetFractionPart(float Number)
{
    return Number - int(Number);
}

// Function to round a floating-point number to the nearest integer
// It uses custom rounding logic similar to standard rounding rules
int MyRound(float Number)
{
    int IntPart;
    // Get the integer part of the number
    IntPart = int(Number);

    // Get the fractional part of the number using GetFractionPart()
    float FractionsPart = GetFractionPart(Number);

    // If the absolute value of the fractional part is greater than or equal to 0.5
    if (abs(FractionsPart) >= .5)
    {
        // If the number is positive, round up
        if (Number > 0)
            return ++IntPart;
        // If the number is negative, round down
        else
            return --IntPart;
    }
    else
    {
        // If the fractional part is less than 0.5, return the integer part
        return IntPart;
    }
}

// Function to read a floating-point number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a float number? ";
    cin >> Number;
    return Number;
}

int main()
{
    // Read the number from the user
    float Number = ReadNumber();

    // Display the result of custom rounding using MyRound()
    cout << "My Round Result : " << MyRound(Number) << endl;

    // Display the result of standard C++ rounding using round()
    cout << "C++ Round Result: " << round(Number) << endl;

    return 0;
}
