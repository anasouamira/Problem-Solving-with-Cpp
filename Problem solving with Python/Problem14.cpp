/*
Problem14 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
EEEEE
DDDD
CCC
BB
A
==========================================================
*/


#include <iostream>
using namespace std;

// Function to read a positive short number from the user
short RedNumberPsitive(string message){
    short Number;
    do
    {
        cout << message;  // Display the message prompt
        cin >> Number;    // Read user input
    } while (Number < 0);  // Ensure the input is positive
    return Number;
}

// Function to print an inverted pattern of letters
void PrintInvertedPattern(short Number) {
    // Calculate the starting letter for the pattern (from 'A' to the letter corresponding to the Number)
    int inverted_Letter = 65 + (Number - 1);  // ASCII value of 'A' is 65

    // Loop through the pattern, starting from the letter corresponding to the Number and going down
    for (int i = inverted_Letter; i >= 65; i--) {
        
        // Print the current letter 'i' for 'Number' times
        for (int j = 1; j <= Number; j++) 
            cout << char(i);
        
        Number--;  // Decrease the count for the next row
        cout << endl;  // Move to the next line after printing each row
    }
}

int main()
{
    // Read a positive number and print the inverted pattern of letters
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern: "));
}


