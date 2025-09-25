#include <iostream>
#include <string>
using namespace std;

// 🔹 Question / Task:
// Write a program that repeatedly reads numbers from the user and calculates their sum.
// The user can stop entering numbers by entering -99.


// Function to read a number from the user with a custom message
float RedNumbers(string message) {
    int Nub = 0;
    cout << message;
    cin >> Nub;
    return Nub;
}

// Function to calculate the sum of numbers entered by the user
int CalculateSum() {
    int sum = 0;       // Variable to store the sum
    int Nub = 0;       // Variable to store the current input number
    int Counter = 1;   // Counter for numbering inputs

    do {
        Nub = RedNumbers("Enter Number " + to_string(Counter) + " (Enter -99 to stop): ");
        if (Nub != -99) { // Add to sum only if the input is not the sentinel value
            sum += Nub;
        }
        Counter++;
    } while (Nub != -99); // Continue until user enters -99

    return sum; // Return the total sum
}

int main() {
    cout << "Result = " << CalculateSum() << endl; // Print the total sum
}
