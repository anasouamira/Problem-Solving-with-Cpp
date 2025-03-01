/*
Problem17 |===============================================

Write a program to guess a 3-Letter Password (all capital)?

Input :

AAD

Output : 

Trial[1] : AAA
Trial[2] : AAB
Trial[3] : AAC
Trial[4] : AAD

Password is AAD
Found After 4 Trial(s)

==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

// Function to read a 3-letter password from the user
string ReadPassword()
{
    string Password;
    cout << "Please enter a 3-Letter Password (all capital)?\n";  // Prompt user to enter password
    cin >> Password;  // Read password input
    return Password;  // Return the password
}

// Function to guess the password by trying all possible 3-letter combinations
bool GuessPassword(string OriginalPassword)
{
    string word = "";  // Initialize an empty string to store the current guess
    int Counter = 0;  // Initialize the trial counter

    cout << "\n";
    // Loop through all possible combinations of 3 uppercase letters (A-Z)
    for (int i = 65; i <= 90; i++)  // First character (A-Z)
    {
        for (int j = 65; j <= 90; j++)  // Second character (A-Z)
        {
            for (int k = 65; k <= 90; k++)  // Third character (A-Z)
            {
                word = word + char(i);  // Append the first character
                word = word + char(j);  // Append the second character
                word = word + char(k);  // Append the third character
                Counter++;  // Increment the trial counter

                cout << "Trial [" << Counter << "] : ";  // Display the current trial number
                cout << word << endl;  // Display the current word being guessed

                // Check if the current guess matches the original password
                if (word == OriginalPassword)
                {
                    cout << "\nPassword is " << word << "\n";  // Display the correct password
                    cout << "Found after ";
                    cout << Counter << " Trial(s)\n";  // Display the number of trials taken
                    return true;  // Return true if the password is found
                }

                word = "";  // Reset the word for the next trial
            }
        }
    }
    return false;  // Return false if the password is not found after all trials
}

int main()
{
    GuessPassword(ReadPassword());  // Read the password and try to guess it
    return 0;
}
