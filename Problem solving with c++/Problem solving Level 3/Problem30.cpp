/*
Problem 30 |=================================================

a program to read a string and read a character then 
the character in that string

input : 

Please Enter Your String?
Mohammed Abu-Hadhoud 
Please Enter a Character?
m 

Output : 
Letter 'm' Count = 2
=============================================================
*/

#include <string>
#include <iostream>
using namespace std;

// Function to read a full string from the user
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1); // Reads the entire line (with spaces)
    return S1;
}

// Function to read a single character from the user
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

// Function to count how many times 'Letter' appears in 'S1'
short CountLetter(string S1, char Letter)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++; // Increment if it matches the target character
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();   // Ask user for string
    char Ch1 = ReadChar();      // Ask user for character

    // Print result
    cout << "\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1);

    system("pause>0"); // Pause the console (only needed on Windows)
}
