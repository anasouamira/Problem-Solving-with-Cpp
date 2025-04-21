/*
Problem 28 |=================================================

Write a program fo read a character then invert it's case 
and print it.

input : 

Please Enter Your String?
mohammed ABU-HADHOUD

Output : 
String after Inverting All Letters Case:
MOHAMMED abu-hadhoud
=============================================================
*/
#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InvertAllStringLettersCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after Inverting All Letters Case:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;
    system("pause>0");
}