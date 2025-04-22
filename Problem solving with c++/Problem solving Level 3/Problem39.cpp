/*
Problem 39 |=================================================

Write a program to join vector of strings into a one string
with separators

Output : 
Vector after join: 
Mohammed Faid Ali Maher 
=============================================================
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Function to join all strings in a vector into one string with a delimiter between them
string JoinString(vector<string> vString, string Delim)
{
    string S1 = "";

    // Loop through each string in the vector
    for (string& s : vString)
    {
        // Append the string and delimiter to the result
        S1 = S1 + s + Delim;
    }

    // Remove the last added delimiter to avoid extra delimiter at the end
    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    // Create a vector of strings
    vector<string> vString = { "Mohammed", "Faid", "Ali", "Maher" };

    // Print the result of joining the vector with a space as delimiter
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ");

    system("pause>0"); // Pause the program before exiting (works on Windows)
}

