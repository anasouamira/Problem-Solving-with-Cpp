/*
Problem 27 |=================================================

Write a program fo read a character then invert it's case 
and print it.

input : 

Please Enter a Character? 
a 
char after inverting case:
A 
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a single character from the user
char ReadChar()
{
    char Ch1;
    cout << "Please Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}
// Function to invert the case of the given character
char InvertLetterCase(char char1)
{
    // If uppercase, convert to lowercase; otherwise convert to uppercase
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

int main()
{
    char Ch1 = ReadChar(); // Read character from user

    cout << "\nChar after inverting case:\n";
    Ch1 = InvertLetterCase(Ch1); // Invert the case of the character
    cout << Ch1 << endl;         // Display the result

    system("pause>0"); // Keep the console window open (for Windows systems)
}
