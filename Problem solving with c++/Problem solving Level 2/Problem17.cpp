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
Found After 6 Trial(s)

==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

string Red_3_CapitalLetterPassword(string message)
{

    string Letter_Password;

    cout << message;
    cin >> Letter_Password;

    return Letter_Password;
}

void Guess_A_3_LetterPassword(string Letter_Password)
{

    string word = "";
    int Trial = 1;
    for (int i = 65; i <= 90; i++)
    {

        for (int j = 65; j <= 90; j++)
        {

            for (int k = 65; k <= 90; k++)
            {

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << " Trail[" << Trial << "] : " << word << endl;

                if (Letter_Password == word)
                {

                    cout << endl;
                    cout << "Password is : " << Letter_Password << endl;
                    cout << "Found After " << Trial << " Trial(s)" << endl;

                    i = 91;
                    j = 91;
                    break;
                }

                Trial++;
                word = "";
            }
        }
    }
}

// This is Professional code solution :

string ReadPassword()
{
    string Password;
    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> Password;
    return Password;
}
bool GuessPassword(string OriginalPassword)
{
    string word = "";
    int Counter = 0;
    cout << "\n";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                Counter++;

                cout << "Trial [" << Counter << "] : ";
                cout << word << endl;
                if (word == OriginalPassword)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found after ";
                    cout << Counter << " Trial(s)\n";
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}

int main()
{
    // code 1 :
    Guess_A_3_LetterPassword(Red_3_CapitalLetterPassword(" Enter 3 capital letter password : "));

    // code 2 :
    GuessPassword(ReadPassword());
    return 0;
}