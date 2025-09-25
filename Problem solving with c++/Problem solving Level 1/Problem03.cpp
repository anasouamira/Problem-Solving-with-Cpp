#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads an integer number from the user
// and prints its square (power 2), cube (power 3), and fourth power (power 4).

// Function to read a number from the user
int RedNumbers() {
    int Nub;
    cout << "Enter a number: ";
    cin >> Nub; // Read input from user
    return Nub; // Return the number
}

// Function to calculate the power of a number
int PowerOf_2_3_4(int Nub, int Power_Nub) {
    int Powr = 1;
    // Multiply Nub by itself Power_Nub times
    for (int i = 1; i <= Power_Nub; i++) {
        Powr = Powr * Nub;
    }
    return Powr; // Return the calculated power
}

// Function to print powers 2, 3, and 4 of a given number
void PrintPowerOf_2_3_4(int Nub) {
    // Loop through powers 2, 3, and 4
    for (int i = 2; i <= 4; i++) {
        cout << "Number^" << i << " = " << PowerOf_2_3_4(Nub, i) << endl;
    }
}

int main() {
    // Read number from user and print its powers
    PrintPowerOf_2_3_4(RedNumbers());
}
