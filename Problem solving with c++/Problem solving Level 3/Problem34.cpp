/*
Problem 27 |=================================================

Write a program to read a string then print all vowels in that
string (Vowels are: a,e,i,o,u)

Input :
Please Enter Your String?
Mohammed Abu-Hadhoud Programming Advices

Output : 
Vowels in string are: O a e A u a o u o a i A i e
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a string from user input
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

// Function to check whether a character is a vowel
bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1); // Normalize to lowercase
    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

// Function to print all vowels found in the string
void PrintVowels(string S1)
{
    cout << "\nVowels in string are: ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << " ";
    }
    cout << endl;
}

int main()
{
    string S1 = ReadString();
    PrintVowels(S1);
    system("pause>0");
}
