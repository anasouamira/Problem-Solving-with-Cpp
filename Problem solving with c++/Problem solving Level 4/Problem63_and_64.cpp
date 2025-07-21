/*
Problem 54 |=============================================================================================

Write a program to :

+ Read Date String.

+ Convert it to date structure

+ Print Day, Mont, Year separately.

+ Then convert Date Structure to string and
print it on the screen.

Note: write the following functions: 

+ StringToDate. 

+ DateToString. 


Please Enter Date (dd/mm/yyyy): 13/06/2004

Day: 13
Month: 6
Year: 2004

You Entered: 13/6/2004
==========================================================================================================
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struct to represent a date
struct stDate {
    short Year;
    short Month;
    short Day;
};

// Split string by a delimiter and return a vector of parts
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0; // Note: size_t is better for positions
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "") {
        vString.push_back(S1); // Add last word
    }

    return vString;
}

// Convert stDate to string format "dd/mm/yyyy"
string DateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

// Convert string "dd/mm/yyyy" to stDate
stDate StringToDate(string DateString) {
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");

    if (vDate.size() == 3) {
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
    } else {
        cout << "Invalid date format!\n";
    }

    return Date;
}

// Read date string from user
string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString); // ws to ignore any leftover newline
    return DateString;
}

// Main program
int main() {
    string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy): ");
    stDate Date = StringToDate(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou Entered: " << DateToString(Date) << "\n";

    system("pause>0");
    return 0;
}
