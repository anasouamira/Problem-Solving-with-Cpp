#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads total sales from the user
// and calculates the commission based on the following rules:
// - Sales >= 1,000,000 → 1%
// - Sales >= 500,000 → 2%
// - Sales >= 100,000 → 3%
// - Sales >= 50,000 → 5%
// - Otherwise → 0%


// Function to read total sales (must be non-negative)
int RedTotalSales() {
    int Nub;
    do {
        cout << "Enter Total Sales: ";
        cin >> Nub;
        if (Nub < 0) {
            cout << "Invalid input! Sales must be non-negative." << endl;
        }
    } while (Nub < 0);
    return Nub;
}

// Function to determine commission rate based on sales
float Percentage(int Nub) {
    if (Nub >= 1000000) {
        return 0.01;   // 1%
    }
    else if (Nub >= 500000) {
        return 0.02;   // 2%
    }
    else if (Nub >= 100000) {
        return 0.03;   // 3%
    }
    else if (Nub >= 50000) {
        return 0.05;   // 5%
    }
    else {
        return 0;      // 0%
    }
}

// Function to calculate commission amount
float CheckCommission(int Nub) {
    return Nub * Percentage(Nub); // Multiply sales by rate
}

int main() {
    int totalSales = RedTotalSales();      // Read total sales
    float commission = CheckCommission(totalSales); // Calculate commission

    cout << "The commission is: " << commission << endl; // Print result
}
