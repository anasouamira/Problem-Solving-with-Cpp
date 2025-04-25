/*
Problem 42 |=================================================

Write a program fo replace words in string:

Input : 
Original String
EET to Jordan , Jordan is a nice country

Output : 
String After Replace: 
Welcome to USA , USA is a nice country 
=============================================================
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// This function replaces all occurrences of a word in a string using the built-in replace function
string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
    // Find the first occurrence of the word to replace
    short pos = S1.find(StringToReplace);

    // Keep replacing while the word still exists in the string
    while (pos != std::string::npos)
    {
        // Replace the word at the found position with the new word
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

        // Find the next occurrence of the word
        pos = S1.find(StringToReplace);
    }

    // Return the modified string
    return S1;
}

int main()
{
    // Original string
    string S1 = "Welcome to Jordan , Jordan is a nice country";

    // The word to be replaced
    string StringToReplace = "Jordan";

    // The word to replace with
    string ReplaceTo = "USA";

    // Print the original string
    cout << "\nOriginal String\n" << S1;

    // Print the modified string after replacement
    cout << "\n\nString After Replace:\n";
    cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);

    system("pause>0");
}

