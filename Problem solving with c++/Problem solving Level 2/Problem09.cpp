#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int FreqCount = 0, Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    }
    return FreqCount;
}

void PrintDigitFrequency(int Number)
{

    for (int DigitToCheck = 1; DigitToCheck <= 9; DigitToCheck++)
    {

        short DigitFrequency = CountDigitFrequency(DigitToCheck, Number);

        if (DigitFrequency > 0)
        {

            cout << "\nDigit " << DigitToCheck << " Frequency is " << DigitFrequency << " Time(s).\n";
        }
    }
}
int main()
{
    PrintDigitFrequency(ReadPositiveNumber("Please enter the main number ? "));

    return 0;
}
