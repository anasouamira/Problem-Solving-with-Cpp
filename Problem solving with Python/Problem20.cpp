/*
Problem20 |===============================================

Write a program to print random Small letter, Capital Letter
Special character, and Digit order

Output :
i
G
$
7
==========================================================
*/

#include <iostream> 
#include <cstdlib> 
#include <ctime> // Include ctime for time() function
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
        return char(RandomNumber(97, 122)); // Random lowercase letter
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90)); // Random uppercase letter
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47)); // Random special character
    case enCharType::Digit:
        return char(RandomNumber(48, 57)); // Random digit
    default:
        return ' '; // Return space if invalid type
    }
}

int main() {
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL)); 
    
    // Generate and print random characters of different types
    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;
    
    return 0; 
}

