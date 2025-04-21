/*
Problem 27 |=================================================

Write a program fo read a string then count all vowels in that
string (Vowels are: a, e, i, o, u)

Input :
Please Enter Your String?
Mohammed Abu-Hadhoud Programming Advices

Output : 
Number of vowels is: 14 
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a string from user
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

// Function to check if a character is a vowel
bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1); // Convert to lowercase for consistency
    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

// Function to count vowels in the given string
short CountVowels(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();
    cout << "\nNumber of vowels is: " << CountVowels(S1);
    system("pause>0");
}
