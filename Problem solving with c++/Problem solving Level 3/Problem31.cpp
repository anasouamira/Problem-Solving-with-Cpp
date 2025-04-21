/*
Problem 27 |=================================================

Write a program to read a string and read a character then |
count the character in that string (Match Case or Not)

input : 

Please Enter Your String?
Mohammed Abu-Hadhoud Programming Advices!

Please Enter a Character?
m 

Output : 

Letter 'm' Count = 4
Letter 'm" Or 'M' Count = 5
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Reads a full string from the user
string ReadString()
{
    string S1;
    cout << "\nPlease Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

// Reads a single character from the user
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

// Inverts the case of a character: 'A' -> 'a', 'z' -> 'Z'
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

// Counts how many times 'Letter' appears in 'S1'
// If MatchCase is false, it counts both upper and lower cases
short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }
    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nLetter \'" << Ch1 << "\' Count = "
         << CountLetter(S1, Ch1);

    cout << "\nLetter \'" << Ch1 << "\' or \'"
         << InvertLetterCase(Ch1) << "\' Count = "
         << CountLetter(S1, Ch1, false);

    system("pause>0");
}
