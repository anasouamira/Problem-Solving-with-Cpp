/*
Problem 27 |=================================================

Write a program to read a string then count small/capital
letters in that string

input : 

Please Enter Your String?
Mohammed Abu-Hadhoud 

Output : 

String Length = 20 
Capital Letters Count= 3 
Small Letters Count= 15 
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a full string from the user
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

// Enumeration to define what type of letters to count
enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLetters = 1,
    All = 3
};

// General function to count letters based on specified type
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length(); // Return total length (includes spaces/punctuation)
    }

    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        // Count only capital letters
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;

        // Count only small letters
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
    }

    return Counter;
}

// Dedicated function to count only capital letters
short CountCapitalLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }

    return Counter;
}

// Dedicated function to count only small letters
short CountSmallLetters(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadString(); // Get user input

    // Method 1: Using dedicated functions
    cout << "\nString Length = " << S1.length();
    cout << "\nCapital Letters Count = " << CountCapitalLetters(S1);
    cout << "\nSmall Letters Count = " << CountSmallLetters(S1);

    // Method 2: Using the general function with enum
    cout << "\n\nMethod 2\n";
    cout << "\nString Length = " << CountLetters(S1);
    cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count = " << CountLetters(S1, enWhatToCount::SmallLetters);

    system("pause>0");
}
