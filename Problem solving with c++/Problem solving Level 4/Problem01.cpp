/*
Problem 01 |=============================================================================================

Write a program fo read a number and
print the text of that number : 

Input : 
Enter a Number? 5843 

Enter a Number? 8476362741 


Output :

Five Thousands Eight Hundreds Forty Three 

Eight billion four hundred seventy six million three hundred sixty two thousand seven hundred forty one.
==========================================================================================================
*/
#include <iostream>
#include <string>
using namespace std;

// Converts an integer number to its textual representation
string NumberToText(int Number)
{
    if (Number == 0)
    {
        return ""; // Base case: if the number is 0, return empty string
    }

    // Handle numbers from 1 to 19
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"",
                        "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }

    // Handle numbers from 20 to 99
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10); // Get tens and recursively process units
    }

    // Handle numbers from 100 to 199
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100); // "One Hundred" + remainder
    }

    // Handle numbers from 200 to 999
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100); // e.g., "Three Hundreds Forty Two"
    }

    // Handle numbers from 1000 to 1999
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000); // "One Thousand" + remainder
    }

    // Handle numbers from 2000 to 999999
    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000); // Thousands part + remainder
    }

    // Handle numbers from 1,000,000 to 1,999,999
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000); // "One Million" + remainder
    }

    // Handle numbers from 2,000,000 to 999,999,999
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000); // Millions part + remainder
    }

    // Handle numbers from 1,000,000,000 to 1,999,999,999
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000); // "One Billion" + remainder
    }

    // Handle numbers 2,000,000,000 and up (within int limit)
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000); // Billions part + remainder
    }
}

// Reads an integer from the user
int ReadNumber()
{
    int Number;
    cout << "\nEnter a Number? ";
    cin >> Number;
    return Number;
}

int main()
{
    int Number = ReadNumber(); // Get number input from the user
    cout << NumberToText(Number); // Output the textual representation
    system("pause>0"); // Pause the console (Windows only)
    return 0;
}

