/*
Problem 23 |=================================================

Write a program to read a string then print the first letter
of each word in that string.

Mohammed Sager Abu-Hahdoud @Programming Adivces


Output :
First letters of this string:
M

S

A

@

A

=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a string from user input
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1); // Read full line including spaces
    return S1;
}

// Function to print the first letter of each word in a string
void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true; // Flag to detect the start of a word
    cout << "\nFirst letters of this string: \n";

    for (short i = 0; i < S1.length(); i++)
    {
        // If current character is not a space and it's the start of a word
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl; // Print the first letter of the word
        }

        // Update the flag: true if current character is a space
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}

int main()
{
    // Read a string and print first letters of each word
    PrintFirstLetterOfEachWord(ReadString());
    system("pause>0"); // Wait for user before closing console
}
