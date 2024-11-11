#include <iostream>
using namespace std;

short RedNumberPsitive(string message)
{
    short Number;
    do
    {
        cout << message;
        cin >> Number;

    } while (Number < 0);

    return Number;
}
void PrintInvertedPattern(short Number)
{

    for (short i = Number; i > 0; i--)
    {
        for (short j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}

int main()
{
    PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern : "));
}
