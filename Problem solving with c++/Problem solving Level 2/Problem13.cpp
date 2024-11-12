/*
Problem13 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
1
22
333
4444
55555
==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

short RedNumberPsitive(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
void PrintInvertedPattern(short Number)
{

    for (short i = 1; i <= Number; i++)
    {
        for (short j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}

int main()
{
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern : "));
}
