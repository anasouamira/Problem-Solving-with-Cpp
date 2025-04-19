/*
Problem 24 |=================================================

Write a program to read a string then uppercase the first
letter of each word in that string


Output :
Please Enter Your String?
mohammed sager abu-Hadhoud

String after conversion:
Mohammed Sager Abu-Hadhoud

=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a line of text from the user
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1); // Reads full input including spaces
    return S1;
}

// Function to capitalize the first letter of each word in the string
string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true; // Flag to track start of a word

    for (short i = 0; i < S1.length(); i++)
    {
        // If current character is not a space and it's the start of a word
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]); // Convert to uppercase
        }

        // Set flag based on whether current char is a space
        isFirstLetter = (S1[i] == ' ');
    }

    return S1;
}

int main()
{
    string S1 = ReadString(); // Get input string from user

    // Convert first letter of each word to uppercase
    cout << "\nString after conversion:\n";
    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;

    system("pause>0"); // Wait for user before closing console
}
