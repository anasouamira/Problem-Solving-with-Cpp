/*
Problem 27 |=================================================

Write a program to replace words in string using custom
function:

Original String:
Welcome to Jordan , Jordan is a nice country

Replace with match case: 
Welcome to Jordan , Jordan is a nice country 

Replace with dont match case: 
Welcome to USA , USA is a nice country 
=============================================================
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// This function splits a string into a vector of words using a delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // A temporary string to store each word

    // Loop while the delimiter exists in the string
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Extract the word before the delimiter
        if (sWord != "")
        {
            vString.push_back(sWord); // Add the word to the vector
        }
        // Erase the extracted word and the delimiter from the original string
        S1.erase(0, pos + Delim.length());
    }

    // After the loop, add the remaining part of the string (last word)
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString; // Return the vector of words
}

// This function joins a vector of strings into one string using a delimiter
string JoinString(vector<string> vString, string Delim)
{
    string S1;
    for (string &s : vString)
    {
        S1 = S1 + s + Delim; // Append each string followed by the delimiter
    }

    // Remove the last added delimiter
    return S1.substr(0, S1.length() - Delim.length());
}

// This function converts all characters in a string to lowercase
string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

// This function replaces words in a string using split and join methods
string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    // Split the string into words using space as a delimiter
    vector<string> vString = SplitString(S1, " ");

    // Loop through each word in the vector
    for (string &s : vString)
    {
        if (MatchCase)
        {
            // If case-sensitive, match the word exactly
            if (s == StringToReplace)
            {
                s = sRepalceTo;
            }
        }
        else
        {
            // If case-insensitive, convert both sides to lowercase before comparing
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sRepalceTo;
            }
        }
    }

    // Join the vector back into a string with spaces and return it
    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "jordan"; // lowercase on purpose
    string ReplaceTo = "USA";

    cout << "\nOriginal String:\n" << S1;

    // Case-sensitive replacement (won’t replace "Jordan" because of case mismatch)
    cout << "\n\nReplace with match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

    // Case-insensitive replacement (will replace "Jordan" regardless of case)
    cout << "\n\nReplace with don't match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);

    system("pause>0");
}

