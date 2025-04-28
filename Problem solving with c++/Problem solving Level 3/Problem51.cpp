/*
Problem 50 |=================================================

Write a program to find client by AccountNumber and print it
to the screen:

Please enter AccountNumber? A150

The Following are the client details:
Account Number: A150
Pin Code : 1234
Name : Mohammed Abu-Hadhoud
Phone : 093938838
Account Balance: 5000

Are you sure you want delete this client? y/n ? y
Client Deleted Successfully.

Please enter AccountNumber? B33
Client with Account Number (B33) Not Found!

===============================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Define the file where clients' data is stored
const string ClientsFileName = "Clients.txt";

// Struct representing a client
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false; // Used to mark records for deletion
};

// Function to split a string by a specific delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); // Erase the word and delimiter
    }

    if (S1 != "")
    {
        vString.push_back(S1); // Add the last word
    }

    return vString;
}

// Function to convert a line from the file into a client record
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert string to double

    return Client;
}

// Function to convert a client record into a line to store in the file
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

// Function to load all clients from the file
vector<sClient> LoadCleintsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // Open file for reading

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

// Function to print the client information
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
}

// Function to find a client by their account number
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

// Function to read new client details from user input
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber; // Account number remains the same

    cout << "\n\nEnter PinCode: ";
    getline(cin >> ws, Client.PinCode); // ws to consume any leftover whitespace

    cout << "Enter Name: ";
    getline(cin, Client.Name);

    cout << "Enter Phone: ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

// Function to save all clients back into the file, excluding deleted ones
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // Overwrite file

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                // Only save clients not marked for deletion
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }

    return vClients;
}

// Function to update a client by account number
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client? (y/n): ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }
        else
        {
            cout << "\n\nUpdate Cancelled.";
            return false;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

// Function to ask user to input account number
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

// Main program entry
int main()
{
    // Load all clients from file
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    // Ask user for the account number they want to update
    string AccountNumber = ReadClientAccountNumber();

    // Attempt to update the client
    UpdateClientByAccountNumber(AccountNumber, vClients);

    system("pause>0"); // Pause console
    return 0;
}
