/*
Problem 38 |=================================================

Write a program fo read a string then Trim Left, Right , All

Input : 
String =       Mohammed Abu-Hahdoud

Output : 
Trim Left  = Mohammed Abu-Hahdoud 
Trim Right =       Mohammed Abu-Hahdoud
Trim       = Mohammed Abu-Hahdoud
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to trim leading (left) spaces from the string
string TrimLeft(string S1)
{
    // Loop through each character in the string
    for (short i = 0; i < S1.length(); i++)
    {
        // Find the first non-space character
        if (S1[i] != ' ')
        {
            // Return the substring starting from the first non-space character to the end
            return S1.substr(i, S1.length() - i);
        }
    }
    // If the string only contains spaces, return an empty string
    return "";
}

// Function to trim trailing (right) spaces from the string
string TrimRight(string S1)
{
    // Loop backward from the end of the string
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        // Find the last non-space character
        if (S1[i] != ' ')
        {
            // Return the substring from the beginning to that last non-space character
            return S1.substr(0, i + 1);
        }
    }
    // If the string only contains spaces, return an empty string
    return "";
}

// Function to trim both leading and trailing spaces
string Trim(string S1)
{
    // First trim the right side, then trim the left side of the result
    return (TrimLeft(TrimRight(S1)));
}

int main()
{
    string S1 = " Mohammed Abu-Hahdoud ";

    // Print original string
    cout << "\nString = " << S1;

    // Trim left and display result
    cout << "\n\nTrim Left = " << TrimLeft(S1);

    // Trim right and display result
    cout << "\nTrim Right = " << TrimRight(S1);

    // Trim both sides and display result
    cout << "\nTrim = " << Trim(S1);

    system("pause>0"); // Pause the program before it exits (Windows only)
}
