#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a simple calculator program that reads two integers and an operation type (+, -, *, /)
// from the user. Then perform the operation and print the result.

struct strNub_Ope {
    int Number1;   // First number
    int Number2;   // Second number
    char Ope;      // Operation: +, -, *, /
};

// Function to read two numbers and an operation from the user
strNub_Ope RedNub_Ope(strNub_Ope& Nub_Ope) {
    cout << "Enter Number1: ";
    cin >> Nub_Ope.Number1;

    cout << "Enter Number2: ";
    cin >> Nub_Ope.Number2;

    // Loop until a valid operation is entered
    do {
        cout << "Enter Operation type (+, -, *, /): ";
        cin >> Nub_Ope.Ope;
    } while (!(Nub_Ope.Ope == '+' || Nub_Ope.Ope == '-' || Nub_Ope.Ope == '*' || Nub_Ope.Ope == '/'));

    return Nub_Ope;
}

// Function to perform the chosen operation
int CheckOperationType(strNub_Ope Nub_Ope) {
    if (Nub_Ope.Ope == '+') {
        return Nub_Ope.Number1 + Nub_Ope.Number2;
    }
    else if (Nub_Ope.Ope == '-') {
        return Nub_Ope.Number1 - Nub_Ope.Number2;
    }
    else if (Nub_Ope.Ope == '*') {
        return Nub_Ope.Number1 * Nub_Ope.Number2;
    }
    else if (Nub_Ope.Ope == '/') {
        if (Nub_Ope.Number2 != 0)
            return Nub_Ope.Number1 / Nub_Ope.Number2;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0; // Return 0 or handle error
        }
    }
    return 0; // Default return if operation not matched
}

int main() {
    strNub_Ope Nub_Ope;

    // Read numbers and operation, then print result
    cout << "Result: " << CheckOperationType(RedNub_Ope(Nub_Ope)) << endl;
}
