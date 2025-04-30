/*
Problem 47 |=================================================

Write a program fo ask you to enter clients and save them to
file:

Adding New Client:

Client Data:
Enter Account Number :  A150
Enter PinCode :  1234
Enter Name :  Mohanmed Abu-Hadhoud
Enter Phone :  079939999
Enter AccountBalance :  5660

Client Added Successfully, do you want to add more clients : 

===============================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Define a constant for the file name to store client data
const string ClientsFileName = "Clients.txt";

// Define the structure to represent a client's information
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Function to read new client details from the user
sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber); // 'ws' clears leading whitespaces

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

// Function to convert a client structure into a formatted string line
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    // Concatenate fields with a custom separator
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance); // Convert balance to string

    return stClientRecord;
}

// Function to append a line of client data to a file
void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app); // Open file in append mode

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl; // Write line to file
        MyFile.close(); // Close file
    }
}

// Function to read a client from the user and add to the file
void AddNewClient()
{
    sClient Client = ReadNewClient(); // Read client details
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client)); // Save to file
}

// Function to repeatedly add clients until the user stops
void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls"); // Clear screen
        cout << "Adding New Client:\n\n";
        AddNewClient(); // Add one client

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y'); // Repeat if user says yes
}

int main()
{
    AddClients(); // Start the client-adding process
    system("pause>0"); // Pause the program (Windows only)
    return 0;
}
