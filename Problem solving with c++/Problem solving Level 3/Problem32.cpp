/*
Problem 27 |=================================================

Write a program to read a character the check if it is a vowel
or not (Vowels are: a, e ,i, o,u)

Input: 

Please Enter a Character? 
i 

Output : 

YES Letter 'a' is vowel 
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;

// Function to read a character from the user
char ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;
    return Ch1;
}

// Function to check if a character is a vowel (case-insensitive)
bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1); // Convert to lowercase to simplify comparison
    return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

int main()
{
    char Ch1 = ReadChar(); // Read character from user

    // Check if it's a vowel and print the result
    if (IsVowel(Ch1))
        cout << "\nYES Letter \'" << Ch1 << "\' is vowel";
    else
        cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";

    system("pause>0");
}
