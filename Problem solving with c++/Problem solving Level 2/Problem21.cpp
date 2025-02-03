/*
Problem21 |===============================================

Write a program to read how many keys to generate and print
them on the screen.

Input:
5

Output:

Key [1]: ETAT-HJUV-PEIP-CFRX

Key [2]: UMCO-YSPQ-PHYK-STIL

Key [3] : QBSR-MZEC-BYNA-DSYK

Key [4]: MISQ-ULYB-ZRAZ-LMAG

Key [5] : NQCR-PPFJ-KZLF-ZHMT 
==========================================================
*/

#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <string> // Include string for string manipulation
using namespace std; 

// Function to generate a random number within a specified range
int RandomNumber(int From, int To) 
{ 
    int randNum = rand() % (To - From + 1) + From; // Generate random number in range [From, To]
    return randNum; 
} 

// Enumeration for character types
enum enCharType 
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

// Function to generate a random character based on the specified type
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122)); // Random lowercase letter (ASCII range 97-122)
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90)); // Random uppercase letter (ASCII range 65-90)
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47)); // Random special character (ASCII range 33-47)
    case enCharType::Digit:
        return char(RandomNumber(48, 57)); // Random digit (ASCII range 48-57)
    default:
        return ' '; // Return space if invalid type
    }
}

// Function to read a positive number from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    }
    while (Number <= 0); // Ensure input is positive
    return Number;
}

// Function to generate a random word of a specified length
string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int i = 0; i < Length; i++)
    {
        Word += GetRandomCharacter(CharType); // Append random character to word
    }
    return Word;
}

// Function to generate a formatted key consisting of four groups of random characters
string GenerateKey()
{
    string Key = "";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-"; // First group of 4 capital letters
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-"; // Second group
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-"; // Third group
    Key += GenerateWord(enCharType::CapitalLetter, 4);        // Fourth group (without trailing '-'
    return Key;
}

// Function to generate and display multiple keys based on user input
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey() << endl; // Print generated key
    }
}

int main() {
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 
    
    // Generate multiple keys based on user input
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate? \n"));
    
    return 0; 
}
