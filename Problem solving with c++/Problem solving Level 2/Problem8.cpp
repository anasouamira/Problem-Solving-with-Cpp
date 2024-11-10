
#include <iostream>
using namespace std;
struct strNumber_Digit
{
	int Number, Digit;
};

// Code 1, This is professional code :

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

// Code 2, This is my code :

strNumber_Digit RedNumber_And_Digit(strNumber_Digit &Red)
{

	do
	{
		cout << "Enter Number positive : ";
		cin >> Red.Number;
		cout << "Enter Digit : ";
		cin >> Red.Digit;

	} while (Red.Number < 0 || Red.Digit < 0);

	return Red;
}
int DegitFrequency(strNumber_Digit Red)
{

	int Remainder;
	int SumDigit = 0;
	do
	{
		Remainder = Red.Number % 10;
		Red.Number = Red.Number / 10;
		if (Remainder == Red.Digit)
			SumDigit++;

	} while (Red.Number > 0);

	return SumDigit;
}

int main()
{
	// For code 1 :
	strNumber_Digit Red;
	cout << "Digit " << Red.Digit << " Frequency is " << DegitFrequency(RedNumber_And_Digit(Red)) << " Time" << endl;

	// For code 2 :
	int Number = ReadPositiveNumber("Please enter the main number ? ");

	short DigitToCheck = ReadPositiveNumber("Please enter one digit to check ? ");
	cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";

	return 0;
}
