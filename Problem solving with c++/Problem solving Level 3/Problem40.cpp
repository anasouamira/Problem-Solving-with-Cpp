/*
Problem 27 |=================================================

Write a program to join vector of strings into a one string
with separators

Output : 

Vector after join: 
Mohammed Faid Ali Maher 

Array after join: 
Mohammed Faid Ali Maher 
=============================================================
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Function to join strings from a vector using a delimiter
string JoinString(vector<string> vString, string Delim)
{
    string S1 = "";
    
    // Loop through each string in the vector
    for (string &s : vString)
    {
        // Append the string and the delimiter to the result
        S1 = S1 + s + Delim;
    }

    // Remove the last delimiter and return the result
    return S1.substr(0, S1.length() - Delim.length());
}

// Overloaded function to join strings from an array using a delimiter
string JoinString(string arrString[], short Length, string Delim)
{
    string S1 = "";

    // Loop through each element in the array
    for (short i = 0; i < Length; i++)
    {
        // Append the string and the delimiter to the result
        S1 = S1 + arrString[i] + Delim;
    }

    // Remove the last delimiter and return the result
    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    // Create a vector of strings
    vector<string> vString = {"Mohammed", "Faid", "Ali", "Maher"};

    // Create an array of strings
    string arrString[] = {"Mohammed", "Faid", "Ali", "Maher"};

    // Print the joined vector
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ");

    // Print the joined array
    cout << "\n\nArray after join: \n";
    cout << JoinString(arrString, 4, " ");

    // Pause before exiting (for Windows)
    system("pause>0");
}
