/*
Problem 27 |=================================================

Write a program to read bank client data record and convert 
it to one line: 

Please Enter Client Data:
Enter Account Number? A150
Enter PinCode? 1234
Enter Name? Mohanmed Abu-Hadhoud
Enter Phone? 079939999
Enter AccountBalance? 5660

Client Record for Saving is:
A150#//#1234#//#ohammed Abu-Hadhoud#//#679939999#//#5600.000000
===============================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Define a structure to store client information
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Function to read new client data from the user
sClient ReadNewClient()
{
    sClient Client;

    // Read all fields from user input
    cout << "Enter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client; // Return the filled client structure
}

// Function to convert a client record to a formatted string line
string ConvertRecordToLine(sClient Client, string Separator = "#//#")
{
    string stClientRecord = "";

    // Concatenate all fields with the separator
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance); // Convert double to string

    return stClientRecord; // Return the full formatted string
}

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";

    sClient Client;
    Client = ReadNewClient(); // Read client data from user

    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client); // Display the formatted string

    system("pause>0"); // Pause program (Windows only)
    return 0;
}
