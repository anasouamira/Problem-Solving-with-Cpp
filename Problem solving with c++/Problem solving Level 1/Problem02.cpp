#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads three floating-point numbers from the user
// and prints the maximum of the three numbers.


// Function to read three numbers from user input
void RedNumbers(float& Nub1, float& Nub2, float& Nub3) {
    // Using reference parameters to modify the original variables in main
    cout << "Enter Nub1 = ";
    cin >> Nub1;
    cout << "Enter Nub2 = ";
    cin >> Nub2;
    cout << "Enter Nub3 = ";
    cin >> Nub3;
}

// Function to find the maximum of three numbers
float ChekMaxOfNumbers(float Nub1, float Nub2, float Nub3) {
    // Compare Nub1 with Nub2 and Nub3
    if (Nub1 > Nub2) {
        if (Nub1 > Nub3) {
            return Nub1; // Nub1 is the largest
        } else {
            return Nub3; // Nub3 is larger than Nub1
        }
    }
    // If Nub1 is not the largest, compare Nub2 with Nub3
    if (Nub2 > Nub3) {
        return Nub2; // Nub2 is the largest
    } else {
        return Nub3; // Nub3 is the largest
    }
}

// Function to print the maximum number
void PrintNumbers(float max) {
    cout << "Max of Numbers is: " << max << endl;
}

int main() {
    float Nub1, Nub2, Nub3;

    // Read three numbers from user
    RedNumbers(Nub1, Nub2, Nub3);

    // Calculate maximum and print it
    PrintNumbers(ChekMaxOfNumbers(Nub1, Nub2, Nub3));

    return 0;
}
