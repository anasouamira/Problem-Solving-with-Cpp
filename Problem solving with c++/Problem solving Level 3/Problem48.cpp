/*
Problem 48 |=================================================

Write a program to read clients file and show them on the
screen as follows: 

                                        Client List (3) Client(s).
________________________________________________________________________________________________

| Account Number | Pin Code  | Client Name                             | Phone       | Balance
________________________________________________________________________________________________

| 123            | 9887      | Anas                                    | 064567787   | 812387
| 123            | 9878      | sad                                     | 064567787   | 812387
| 123            | 9878      | Ouamira                                 | 064567787   | 812387

________________________________________________________________________________________________

===============================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt"; // File to store clients

// Struct to represent a client's data
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Function to split a string based on a delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    // Loop to extract words until no more delimiters are found
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Extract word before delimiter
        if (sWord != "")
        {
            vString.push_back(sWord); // Add word to vector
        }
        S1.erase(0, pos + Delim.length()); // Remove word and delimiter
    }

    // Add the last word (if any)
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Function to convert a line from the file into a client record
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    // Assign data to client struct fields
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert balance to double

    return Client;
}

// Function to read all clients from file and return a vector of clients
vector<sClient> LoadCleintsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // Open file in read mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        // Read each line and convert to client object
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client); // Add to vector
        }

        MyFile.close(); // Close file
    }

    return vClients;
}

// Function to print a single client record in a formatted way
void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

// Function to print all clients with headers and formatting
void PrintAllClientsData(vector<sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Print table headers
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Print all client records
    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main()
{
    // Load clients from file
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    // Print all loaded client data
    PrintAllClientsData(vClients);

    system("pause>0"); // Wait for user before exiting (Windows only)
    return 0;
}

