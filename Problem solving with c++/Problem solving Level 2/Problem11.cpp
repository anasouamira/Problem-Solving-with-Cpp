/*
Problem11 |===============================================

Write a program to read a number and check if is Palindrome?

Input : 
1234
12321

Output : 
No, it is Not a Palindrome number.
Yes, it is a Palindrome number.
==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

int RedPositiveNumbers(string message)
{

    int Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
int ReversNumber(int Number)
{

    short Remainder = 0;
    int Revers = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Revers = Revers * 10 + Remainder;
    }
    return Revers;
}
string CheckPalindromeNumber(int Number, int ReversNumber)
{
    if (Number == ReversNumber)
        return "Yes, it is a Palindrome number.";
    return "No, it is a NOT Palindrome number.";
}

int main()
{
    int Number = RedPositiveNumbers("Enter Number to check it if a Palindrome Number : ");
    int Revers_Number = ReversNumber(Number);

    cout << CheckPalindromeNumber(Number, Revers_Number) << endl;
}
