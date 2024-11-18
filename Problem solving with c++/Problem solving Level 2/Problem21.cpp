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

// This is my code solution :=======================================================
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int RedHowManyKeys(string message)
{
    int Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string GetRandomLetter(int Number)
{

    string SumRandomLetter = "";

    for (int i = 1; i <= Number; i++)
    {
        SumRandomLetter = SumRandomLetter + char(RandomNumber(65, 90));
    }
    return SumRandomLetter;
}

void GetRandomKeys(int Number)
{

    string RandomKey = "";
    string Dash = "-";
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= 4; j++)
        {

            if (j == 4)
                Dash = "";
            RandomKey = RandomKey + GetRandomLetter(4) + Dash;
        }
        cout << "Key[" + to_string(i) + "] : " + RandomKey << endl;

        RandomKey = "";
        Dash = "-";
    }
}
//===================================================================================

// This is a Professional code :=====================================================

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    }

    while (Number <= 0);
    return Number;
}
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {
    }
    Word = Word + GetRandomCharacter(CharType);
    return Word;
}
string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}
void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}
//=====================================================================================
int main()
{

    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    // for code 1 : 
    int HowManyKeys = RedHowManyKeys("Enter How many Keys do you want : ");
    GetRandomKeys(HowManyKeys);

    // for code 2 : 
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate? \n "));

    return 0;
}
