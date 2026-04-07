/*

Description:
Modify the previous problem:

    -The person can be hired if:
    -Age > 21 AND has license
    -OR Age > 25 (even without license)

Example:

Input:
Age = 26
HasLicense = 0

Output:
Hired

*/
#include <iostream>
using namespace std;

void ReadInfo(int &Age, bool &HasLicense) {
    cout << "Enter your age: ";
    cin >> Age;

    cout << "Do you have a driving license? (1 = Yes, 0 = No): ";
    cin >> HasLicense;
}

bool IsHired(int Age, bool HasLicense) {

    // Condition 1: Age > 21 AND has license
    // Condition 2: Age > 25 (no need for license)
    if ((Age > 21 && HasLicense) || (Age > 25))
        return true;

    return false;
}

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