#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads an integer number and another number representing the power.
// Then calculate and print the result of raising the first number to the given power using a loop.

struct strNubs {
    int Number;  // The base number
    int M;       // The power
};

// Function to read the number and the power from the user
strNubs RedNumbers() {
    strNubs Nub;
    cout << "Enter a number: ";
    cin >> Nub.Number;
    cout << "Enter the power: ";
    cin >> Nub.M;
    return Nub;  // Return the structure with both values
}

// Function to calculate and print the power
void Power(strNubs Nub) {
    int multi = 1; // Variable to store the result of the power
    // Multiply Nub.Number by itself Nub.M times
    for (int i = 1; i <= Nub.M; i++) {
        multi = multi * Nub.Number;
    }
    cout << "Power of " << Nub.Number << "^" << Nub.M << " is: " << multi << endl;
}

int main() {
    // Read number and power, then calculate and print the result
    Power(RedNumbers());
}
