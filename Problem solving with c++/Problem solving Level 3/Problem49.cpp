/*
Problem 49 |=================================================

Write a program to find client by AccountNumber and print it
to the screen:

Please enter AccountNumber? A150

The Following are the client details:
Account Number: A150
Pin Code : 1234
Name : Mohammed Abu-Hadhoud
Phone : 093938838
Account Balance: 5000

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
 
const string ClientsFileName = "Clients.txt"; // File containing client records

// Define a struct to hold client information
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Function to split a string by a specific delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    // Keep splitting until the delimiter is not found
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Extract word before delimiter
        if (sWord != "")
        {
            vString.push_back(sWord); // Add word to the vector
        }
        S1.erase(0, pos + Delim.length()); // Remove the processed part
    }

    // Add the remaining part of the string
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Convert a line from file into a client object
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    // Map the parts to the client structure
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert string to double

    return Client;
}

// Load all clients from file and return them in a vector
vector<sClient> LoadCleintsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // Open file for reading

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        // Read each line and convert it to client object
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close(); // Close file after reading
    }

    return vClients;
}

// Display a single client's details nicely
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number   : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
}

// Search for a client by account number
bool FindClientByAccountNumber(string AccountNumber, sClient &Client)
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    // Loop through each client to check for match
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C; // Copy the found client
            return true; // Match found
        }
    }

    return false; // No match found
}

// Prompt the user to input an account number
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main()
{
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();

    // Try to find and display the client
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }

    system("pause>0"); // Pause for user to see the result
    return 0;
}
