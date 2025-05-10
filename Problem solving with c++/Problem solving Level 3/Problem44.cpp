/*
Problem  44 |=================================================

Write a program to remove all punctuations from a string:

Original String:
Welcome to Jordan, Jordan is a nice country; it's amazing.

Punctuations Removed:
Welcome To Jordan Jordan is a nice country its amazing

=============================================================
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Function to remove all punctuation characters from a given string
string RemovePunctuationsFromString(string S1)
{
    string S2 = ""; // This will store the cleaned string
    for (short i = 0; i < S1.length(); i++)
    {
        // Check if the character is NOT a punctuation
        if (!ispunct(S1[i]))
        {
            // If it's not a punctuation, add it to the result string
            S2 += S1[i];
        }
    }
    return S2; // Return the string without punctuations
}

int main()
{
    // Define a test string with punctuation
    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

    // Print the original string
    cout << "Original String:\n" << S1;

    // Print the string after removing punctuation characters
    cout << "\n\nPunctuations Removed:\n" << RemovePunctuationsFromString(S1);

    // Pause the program before exiting (Windows only)
    system("pause>0");
}


