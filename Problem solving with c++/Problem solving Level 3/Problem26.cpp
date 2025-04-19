/*
Problem 23 |=================================================

Write a program to read a string then upper all letters , then
lower all letters , and print them.

input : 

Please Enter Your String?
mohammed Abu-Hadhoud

Output :

String after Upper:
MOHAMMED. ABU-HADOUD

String after Lower:
mohammed abu-hadhoud

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
    getline(cin, S1); // Reads entire line, including spaces
    return S1;
}

// Function to convert all characters of the string to uppercase
string UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]); // Convert each character to uppercase
    }
    return S1;
}

// Function to convert all characters of the string to lowercase
string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]); // Convert each character to lowercase
    }
    return S1;
}

int main()
{
    string S1 = ReadString(); // Read input from user

    // Convert to uppercase and display
    cout << "\nString after Upper:\n";
    S1 = UpperAllString(S1);
    cout << S1 << endl;

    // Convert to lowercase and display
    cout << "\nString after Lower:\n";
    S1 = LowerAllString(S1);
    cout << S1 << endl;

    system("pause>0"); // Keeps the console window open
}
