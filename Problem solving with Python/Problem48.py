"""
Problem 48 |=================================================
Write a program to print floor of numbers , don't use built in
floor function 

Input: 
10.7

Output: 
My Round Result : 10 
C++ Round Result: 10

Input:
10.3

Output:
My Round Result : 10
C++ Round Result: 10

Input:
-10.3

Output:
My Round Result : -11
C++ Round Result: -11
=============================================================
"""
#include <iostream>
using namespace std;

// Function to find the floor of a floating-point number
// Floor of a number is the greatest integer less than or equal to the number
int MyFloor(float Number)
{
    // If the number is positive, the floor is simply the integer part
    if (Number > 0)
        return int(Number);
    else
        // If the number is negative and not an exact integer, subtract 1
        return int(Number) - 1;
}

// Function to read a floating-point number from the user
float ReadNumber()
{
    float Number;
    cout << "Please enter a number? ";
    cin >> Number;
    return Number;
}

int main()
{
    // Read the number from the user
    float Number = ReadNumber();

    // Display the result of custom floor calculation using MyFloor()
    cout << "My MyFloor Result : " << MyFloor(Number) << endl;

    // Display the result of standard C++ floor calculation using floor()
    cout << "C++ floor Result  : " << floor(Number) << endl;

    return 0;
}

