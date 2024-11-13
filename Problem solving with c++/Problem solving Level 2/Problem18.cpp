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

// This is my code solution :

#include <iostream>
#include <string>
using namespace std;

string RedText(string message)
{

    string Text;

    cout << message;
    cin >> Text;

    return Text;
}

string EncryptionText(string Text)
{

    string Text_Encryption = "";

    // for first capital tetter:

    for (int CaptalLetter = 65; CaptalLetter <= 90; CaptalLetter++)
    {

        if (Text[0] == char(CaptalLetter))
        {
            Text_Encryption = Text_Encryption + char(CaptalLetter + 1);
            break;
        }
    }

    // For small letters :
    for (int i = 1; i <= Text.length(); i++)
    {
        for (int smallLettersr = 97; smallLettersr <= 122; smallLettersr++)
        {
            if (Text[i] == char(smallLettersr))
            {
                Text_Encryption = Text_Encryption + char(smallLettersr + 1);
            }
        }
    }

    return Text_Encryption;
}

string DecryptionText(string Text)
{

    string Text_Decryption = "";

    // for first capital tetter:

    for (int CaptalLetter = 65; CaptalLetter <= 90; CaptalLetter++)
    {

        if (Text[0] == char(CaptalLetter))
        {
            Text_Decryption = Text_Decryption + char(CaptalLetter - 1);
            break;
        }
    }

    // For small letters :
    for (int i = 1; i <= Text.length(); i++)
    {
        for (int smallLettersr = 97; smallLettersr <= 122; smallLettersr++)
        {
            if (Text[i] == char(smallLettersr))
            {
                Text_Decryption = Text_Decryption + char(smallLettersr - 1);
            }
        }
    }

    return Text_Decryption;
}

// This is professional code solution :

string ReadText()
{
    string Text;
    cout << "Please enter Text?\n";
    getline(cin, Text);
    return Text;
}
string EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}
string DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int main()
{
    // code 1 :
    // Text Before Encryption :
    string Text = RedText("Enter text to encrypt it : ");
    cout << "Text Before Encryption : " << Text << endl;

    // Text After Encryption :
    string Encryption_Text = EncryptionText(Text);
    cout << "Text After Encryption : " << Encryption_Text << endl;

    // Text Before Decryption :
    string Decryption_Text = DecryptionText(Encryption_Text);
    cout << "Text After Decryption : " << Decryption_Text << endl;

    // code 2 :
    const short EncryptionKey = 2; // this is the key.
    string TextAfterEncryption, TextAfterDecryption;
    string Text = ReadText();
    TextAfterEncryption = EncryptText(Text, EncryptionKey);
    TextAfterDecryption = DecryptText(TextAfterEncryption,EncryptionKey);
    
    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;
    return 0;
}
