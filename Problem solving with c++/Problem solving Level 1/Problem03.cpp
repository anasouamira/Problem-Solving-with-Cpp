/*

Description:
Write a program to check whether a number is odd or even.

Example:

Input:
5

Output:
Odd

*/
#include <iostream>
using namespace std;

int main() {

    int number;

    // Ask the user to enter a number
    cout << "Enter a number: ";
    cin >> number;

    // Check if the number is divisible by 2
    if (number % 2 == 0)
        cout << "Even" << endl; // If remainder is 0 → even
    else
        cout << "Odd" << endl;  // Otherwise → odd

    return 0;
}