#include <iostream>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads a student's grade (0-100) and prints the corresponding letter grade:
// A: 90-100, B: 80-89, C: 70-79, D: 60-69, E: 50-59, F: below 50

// Function to read a grade between 0 and 100
int RedNub() {
    int Nub;
    do {
        cout << "Enter the grade (0-100): ";
        cin >> Nub;
        if (Nub < 0 || Nub > 100) {
            cout << "Invalid grade! Please enter a value between 0 and 100." << endl;
        }
    } while (Nub < 0 || Nub > 100); // Repeat until valid input
    return Nub;
}

// Function to check and print the letter grade
void CheckAverage(int Nub) {
    if (Nub >= 90) { 
        cout << "Grade: A" << endl; 
    }
    else if (Nub >= 80) { 
        cout << "Grade: B" << endl; 
    }
    else if (Nub >= 70) { 
        cout << "Grade: C" << endl; 
    }
    else if (Nub >= 60) { 
        cout << "Grade: D" << endl; 
    }
    else if (Nub >= 50) { 
        cout << "Grade: E" << endl; 
    }
    else { 
        cout << "Grade: F" << endl; 
    }
}

int main() {
    int grade = RedNub();      // Read valid grade
    CheckAverage(grade);       // Print corresponding letter grade
}
