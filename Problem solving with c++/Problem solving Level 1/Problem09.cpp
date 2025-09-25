#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads a positive integer from the user and checks whether
// it is a prime number or not. Then print the result.

enum enmPrimeNotPrime { Prime = 1, NotPrime = 2 };

// Function to read a positive number from the user
float RedNumbers(string message) {
    int Nub = 0;
    do {
        cout << message;
        cin >> Nub;
        if (Nub < 0) {
            cout << "Invalid input! Please enter a positive number." << endl;
        }
    } while (Nub < 0); // Repeat until positive number is entered
    return Nub;
}

// Function to check if a number is prime
enmPrimeNotPrime ChekPrime(int Nub) {
    if (Nub < 2) {
        return enmPrimeNotPrime::NotPrime; // Numbers less than 2 are not prime
    }

    int M = round(Nub / 2); // Upper limit for checking divisibility
    for (int i = 2; i <= M; i++) {
        if (Nub % i == 0) {
            return enmPrimeNotPrime::NotPrime; // Divisible by i → Not Prime
        }
    }
    return enmPrimeNotPrime::Prime; // No divisors found → Prime
}

// Function to print whether the number is prime or not
void PrintNumberType(int Nub) {
    switch (ChekPrime(Nub)) {
    case enmPrimeNotPrime::Prime:
        cout << "This Number is Prime" << endl;
        break;
    case enmPrimeNotPrime::NotPrime:
        cout << "This Number is Not Prime" << endl;
        break;
    }
}

int main() {
    int number = RedNumbers("Please Enter a Positive Number: ");
    PrintNumberType(number);
    return 0;
}
