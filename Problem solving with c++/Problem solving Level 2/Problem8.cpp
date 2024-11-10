
#include <iostream>
using namespace std;
struct strNumber_Digit {
	int Number, Digit;
};

// This is  

// This is my code : 

   strNumber_Digit RedNumber_And_Digit(strNumber_Digit& Red) {
	
	do
	{
		cout << "Enter Number positive : ";
		cin >> Red.Number;
		cout << "Enter Digit : ";
		cin >> Red.Digit;

	} while (Red.Number < 0 || Red.Digit < 0);

	return Red;
}

int DegitFrequency(strNumber_Digit Red){

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
	strNumber_Digit Red;

	cout << "Digit " << Red.Digit << " Frequency is " << DegitFrequency(RedNumber_And_Digit(Red)) << " Time" << endl;

	return 0;



}

