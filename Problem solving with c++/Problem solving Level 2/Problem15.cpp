/*
Problem15 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
A
BB
CCC
DDDD
EEEEE
==========================================================
*/

#include <iostream>
using namespace std;

// Function to read a positive short number from the user
short RedNumberPsitive(string message)
{
    short Number;
    do
    {
        cout << message;  // Display the message prompt
        cin >> Number;    // Read user input
    } while (Number < 0);  // Ensure the input is positive
    return Number;
}

// Function to print an inverted pattern of letters
void PrintInvertedPattern(short Number)
{
    // Calculate the ASCII value for the final letter based on the input number
    int final_letter = 65 + (Number - 1);  // 'A' is 65, so this gives the correct final letter
    int counter = 1;  // Initialize the counter for the number of letters to print

    // Loop to print each row of the pattern
    for (int i = 65; i <= final_letter; i++)  // Loop from 'A' (65) to the final letter
    {
        // Print the current letter 'i' for 'counter' times
        for (int j = 1; j <= counter; j++)
            cout << char(i);
        
        counter++;  // Increase the counter for the next row
        if (counter > Number)  // Stop the loop once the counter exceeds the number entered
            break;

        cout << endl;  // Move to the next line after printing each row
    }
}

int main()
{
    // Read a positive number and print the inverted pattern of letters
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern: "));
}

