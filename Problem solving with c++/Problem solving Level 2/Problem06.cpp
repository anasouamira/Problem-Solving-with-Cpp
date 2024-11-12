/*
Problem06 |===============================================

Write a program to read a number and print all the sum of
its digits

Input : 
1234

Output :

sum of Digit = 10

==========================================================
*/

// This is my code solution :

#include <iostream>
using namespace std;

int RedNumberPositive(string message) {
	int Number;
	do
	{
		cout << message;
		cin >> Number;

	} while (Number < 0);
	return Number;
}


void CheckSumRemainder(int Number) {
	int Remainder;
	int SumRemainder = 0;
	do
	{
		Remainder = Number % 10;
		SumRemainder += Remainder;
		Number = Number / 10;

	} while (Number > 0);
	cout << SumRemainder << endl;

}

int main()
{
	CheckSumRemainder(RedNumberPositive("Enter Number to Print it in a reversed order : "));

	return 0;

}
