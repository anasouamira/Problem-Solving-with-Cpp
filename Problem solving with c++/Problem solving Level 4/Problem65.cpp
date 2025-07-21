/*
Problem 65 |=============================================================================================

Write a Program fo read Date and write a
function to format that date.

Please Enter Date (dd/mm/yyyy): 13/06/2002

Default format: 13/6/2002

Year first:     2002/13/6

US format:      6/13/2002

US dash:        6-13-2002

EU dash:        13-6-2002

Verbose:        Day:13, Month:6, Year:2002

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

// Split a string by a delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); // Erase processed part
    }

    if (S1 != "") {
        vString.push_back(S1); // Add last part
    }

    return vString;
}

// Replace all occurrences of one word with another
string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo) {
    size_t pos = S1.find(StringToReplace);
    while (pos != string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

// Convert stDate to string "dd/mm/yyyy"
string DateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

// Convert "dd/mm/yyyy" to stDate
stDate StringToDate(string DateString) {
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");

    if (vDate.size() == 3) {
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
    } else {
        cout << "\nInvalid date format!\n";
    }

    return Date;
}

// Format a date with a custom format
string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = DateFormat;
    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}

// Read a date string from user
string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

// Main program
int main() {
    string DateString = ReadStringDate("\nPlease Enter Date (dd/mm/yyyy): ");
    stDate Date = StringToDate(DateString);

    cout << "\nDefault format: " << FormatDate(Date) << "\n";
    cout << "\nYear first:     " << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\nUS format:      " << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\nUS dash:        " << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\nEU dash:        " << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\nVerbose:        " << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}
