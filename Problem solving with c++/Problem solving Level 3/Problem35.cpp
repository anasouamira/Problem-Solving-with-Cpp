/*
Problem 35 |=================================================

Write a program fo read a string then print each word in that
string.

Input :

Please Enter Your String?

Mohammed Abu-Hadhoud @ProgrammingAdvices
Your string wrords are:

Output : 

Mohammed

Abu-Hadhoud

@rogranmingAdvices
=============================================================
*/

#include <string>
#include <iostream>
using namespace std;

// Reads a line of text from the user
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

// Splits the string by spaces and prints each word on a new line
void PrintEachWordInString(string S1)
{
    string delim = " ";   // Delimiter is a space
    cout << "\nYour string words are:\n\n";
    
    short pos = 0;
    string sWord; // Variable to hold each word

    // Loop until no more delimiters are found
    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0, pos); // Get word before space

        if (sWord != "")
        {
            cout << sWord << endl;
        }

        // Erase the processed word and delimiter from the string
        S1.erase(0, pos + delim.length());
    }

    // Print the last word (or the only word if no space was found)
    if (S1 != "")
    {
        cout << S1 << endl;
    }
}

int main()
{
    PrintEachWordInString(ReadString());
    system("pause>0");
}
