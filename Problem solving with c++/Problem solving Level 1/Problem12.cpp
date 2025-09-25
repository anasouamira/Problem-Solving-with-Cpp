#include <iostream>
#include <string>
using namespace std;

// 🔹 Question / Task:
// Write a simple ATM simulation program that:
// 1. Prompts the user to enter their ATM PIN.
// 2. Allows a maximum of 3 attempts.
// 3. If the correct PIN is entered, display the account balance.
// 4. If the PIN is incorrect after 3 attempts, lock the card.

enum enmATM_PIN { ATM_PIN = 1234, Balance = 7500, Card_Is_Locked = 0 };

// Function to read a non-negative ATM PIN from the user
int Red_ATM_PIN(string message) {
    int Pin;
    do {
        cout << message;
        cin >> Pin;
        if (Pin < 0) {
            cout << "Invalid input! PIN cannot be negative." << endl;
        }
    } while (Pin < 0);

    return Pin;
}

// Function to check the ATM PIN with up to 3 attempts
enmATM_PIN Check_ATM_PIN(int Pin) {
    int i = 1;

    while (i <= 3 && Pin != enmATM_PIN::ATM_PIN) {
        Pin = Red_ATM_PIN("Error! Enter ATM PIN again: ");
        i++;
        if (i > 3) {  // After 3 failed attempts, lock the card
            return enmATM_PIN::Card_Is_Locked;
        }
    }
    return enmATM_PIN::Balance; // Correct PIN → return balance
}

// Function to check and return the balance message
string Check_Balance(int ATM_PIN) {
    ATM_PIN = Check_ATM_PIN(ATM_PIN);

    if (ATM_PIN == enmATM_PIN::Card_Is_Locked) {
        return "Card is locked!";
    } else {
        return "Your balance is: " + to_string(ATM_PIN);
    }
}

int main() {
    int ATM_PIN = Red_ATM_PIN("Enter ATM PIN: ");
    cout << Check_Balance(ATM_PIN) << endl;
}
