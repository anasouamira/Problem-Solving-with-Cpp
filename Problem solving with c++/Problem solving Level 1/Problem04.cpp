/*

Description:
Write a program to determine whether a person can be hired as a driver based on:
    -Age must be greater than 21
    -Has a driving license

Example:

Input:
Age = 25
HasLicense = 1

Output:
Hired

*/
#include <iostream>
using namespace std;

// Function to read user information
void ReadInfo(int &Age, bool &HasLicense) {
    cout << "Enter your age: ";
    cin >> Age;

    cout << "Do you have a driving license? (1 = Yes, 0 = No): ";
    cin >> HasLicense;
}

// Function to check hiring condition
bool IsHired(int Age, bool HasLicense) {

    // Must be older than 21 AND have a license
    if (Age > 21 && HasLicense)
        return true;

    return false;
}

// Function to print result
void PrintResult(bool Result) {

    if (Result)
        cout << "Hired" << endl;
    else
        cout << "Rejected" << endl;
}

int main() {

    int Age;
    bool HasLicense;

    ReadInfo(Age, HasLicense);

    PrintResult(IsHired(Age, HasLicense));

    return 0;
}