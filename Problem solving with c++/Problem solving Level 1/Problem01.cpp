#include <iostream>
#include <string>
using namespace std;

// 🔹 Question / Task:
// Write a program that reads a person's age, whether they have a driver licence,
// and whether they have a recommendation. Then decide if the person is hired or rejected
// based on the following criteria:
// - The person is accepted if they are at least 21 years old OR have a driver licence,
//   AND they do NOT have a recommendation.
// - Keep asking until the person meets the criteria to be hired.

struct strInfo {
    int Age;                      // Person's age
    bool hasDriver_Licence;       // Does the person have a driver licence? (1 = yes, 0 = no)
    bool hasRecommendation;       // Does the person have a recommendation? (1 = yes, 0 = no)
};

// Function to read person's information from user input
strInfo RedInfo() {
    strInfo persone;  // Create a variable of type strInfo to store user input
    cout << "*****************************************" << endl;
    cout << "Enter your Age: ";
    cin >> persone.Age;

    cout << "Do you have Driver Licence? Enter number (yes = 1 / no = 0): ";
    cin >> persone.hasDriver_Licence;

    cout << "Do you have Recommendation? Enter number (yes = 1 / no = 0): ";
    cin >> persone.hasRecommendation;

    return persone; // Return the collected information
}

// Function to check if the person is accepted
bool isAccepted(strInfo persone) {
    // Accepted if age >= 21 OR has driver licence, AND does NOT have recommendation
    return (persone.Age >= 21 || persone.hasDriver_Licence) && !(persone.hasRecommendation);
}

// Function to print result based on acceptance
void PrintInfo(strInfo persone) {
    // Keep asking while the person is NOT accepted
    while (!isAccepted(persone)) {
        cout << "You are rejected" << endl;
        cout << "*****************************************" << endl;
        cout << "Enter again" << endl;
        persone = RedInfo();  // Re-read the person's info
    }

    cout << "*****************************************" << endl;
    cout << "You are hired" << endl;  // Person finally accepted
}

int main() {
    PrintInfo(RedInfo()); // Start the program by reading info and printing result
}
