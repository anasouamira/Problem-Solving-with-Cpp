/*
Problem18 |===============================================

Write a program to read a text and encrypt it, decrypt it.

Input :
Anas

Output :

Text Before Encryption : Anas
Text After Encryption : Bobt
Text Before Decryption : Anas

==========================================================
*/

#include <iostream>
#include <string>
using namespace std;

// Function to read text input from the user
string ReadText()
{
    string Text;
    cout << "Please enter Text?\n";
    getline(cin, Text); // Read entire line of text including spaces
    return Text;
}

// Function to encrypt the given text using a simple shift cipher
string EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++) // Loop through each character
    {
        Text[i] = char((int)Text[i] + EncryptionKey); // Shift character by EncryptionKey
    }
    return Text;
}

// Function to decrypt the text by reversing the shift cipher
string DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++) // Loop through each character
    {
        Text[i] = char((int)Text[i] - EncryptionKey); // Reverse shift by EncryptionKey
    }
    return Text;
}

int main()
{
    const short EncryptionKey = 2; // Encryption key value
    string TextAfterEncryption, TextAfterDecryption;
    
    string Text = ReadText(); // Read input text from user
    
    TextAfterEncryption = EncryptText(Text, EncryptionKey); // Encrypt the input text
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey); // Decrypt the encrypted text
    
    // Display results
    cout << "\nText Before Encryption : " << Text << endl;
    cout << "Text After Encryption  : " << TextAfterEncryption << endl;
    cout << "Text After Decryption  : " << TextAfterDecryption << endl;
    
    return 0;
}

