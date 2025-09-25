#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads the number of coins a person has:
// Pennies, Nickels, Dimes, Quarters, and Dollars.
// Then calculate and print the total value in pennies and in dollars.

struct strMoney {
    int Penny;    // Number of pennies
    int Nickel;   // Number of nickels (5 cents each)
    int Dime;     // Number of dimes (10 cents each)
    int Quater;   // Number of quarters (25 cents each)
    int Dolar;    // Number of dollars (100 cents each)
};

// Function to read the amount of each coin
strMoney RedMoney(strMoney& Money) {
    cout << "Enter number of Pennies: ";
    cin >> Money.Penny;

    cout << "Enter number of Nickels: ";
    cin >> Money.Nickel;

    cout << "Enter number of Dimes: ";
    cin >> Money.Dime;

    cout << "Enter number of Quarters: ";
    cin >> Money.Quater;

    cout << "Enter number of Dollars: ";
    cin >> Money.Dolar;

    return Money;
}

// Function to calculate total value in pennies
int TotalPenny(strMoney Money) { 
    return Money.Penny + (Money.Nickel * 5) + (Money.Dime * 10) + (Money.Quater * 25) + (Money.Dolar * 100);
}

// Function to calculate total value in dollars
int TotalDollars(strMoney Money) {
    return TotalPenny(Money) / 100;
}

int main() {
    strMoney Money;

    // Read coin amounts from user
    RedMoney(Money);

    // Print total in pennies
    cout << "Total in Pennies: " << TotalPenny(Money) << endl;

    // Print total in dollars
    cout << "Total in Dollars: " << TotalDollars(Money) << endl;
}
