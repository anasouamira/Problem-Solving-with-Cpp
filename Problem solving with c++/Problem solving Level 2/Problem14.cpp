/*
Problem14 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
EEEEE
DDDD
CCC
BB
A
==========================================================
*/

// This is my code solution :

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

	int inverted_Letter = 65 + (Number - 1);

	for (int i = inverted_Letter; i  >= 65; i--) {

		for (int j = 1; j <= Number; j++) cout << char(i);
		Number--;
		cout << endl;
	}
}

int main()
{
	PrintInvertedPattern(RedNumberPsitive("Enter Number to print Inverted Pattern : "));

}

