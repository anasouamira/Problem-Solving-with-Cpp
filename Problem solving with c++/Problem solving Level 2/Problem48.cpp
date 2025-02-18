/*
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
*/
#include <iostream>
using namespace std;
int MyFloor(float Number)
{
    if (Number > 0)
        return int(Number);
    else
        return int(Number) - 1;
}

float ReadNumber()
{
    float Number;
    cout << "Please enter a number?";
    cin >> Number;
    return Number;
}
int main()
{
    float Number = ReadNumber();
    cout << "My MyFloor Result : " << MyFloor(Number) << endl;
    cout << "C++ floor Result  : " << floor(Number) << endl;
    return 0;
}
