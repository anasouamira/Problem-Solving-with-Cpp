#include <iostream>
using namespace std;

short RedNumberPsitive(string message){
	short Number;
	do
	{
		cout << message;
		cin >> Number;

	} while (Number < 0);

	return Number;
}
void PrintInvertedPattern(short Number) {

	int inverdted_Letter = 65 + (Number - 1);

	for (int i = inverdted_Letter; i  >= 65; i--) {

		for (int j = 1; j <= Number; j++) cout << char(i);
		Number--;
		cout << endl;
	}
}

int main()
{
	PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern : "));

}

