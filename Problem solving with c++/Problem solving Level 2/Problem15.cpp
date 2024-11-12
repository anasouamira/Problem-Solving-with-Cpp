/*
Problem15 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
A
BB
CCC
DDDD
EEEEE
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

    int final_letter = 65 + (Number - 1);
    int counter = 1;

    for (int i = 65; i <= final_letter; i++)
    {
        for (int j = 1; j <= counter; j++)
            cout << char(i);
        counter++;
        if (counter > Number)
            break;
        cout << endl;
    }
}

int main()
{
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern : "));
}
