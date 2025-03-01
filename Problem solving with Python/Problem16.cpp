/*
Problem16 |===============================================

Write a program to print all words from AAA to ZZZ 

Output : 
AAA
AAB
AAC
.
.
==========================================================
*/

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

// Function to print all possible words from "AAA" to "ZZZ"
void Print_All_Words_From_AAA_To_ZZZ()
{
    // Loop through each character from 'A' (65) to 'Z' (90) for the first position
    for (int i = 65; i <= 90; i++)
    {
        // Loop through each character from 'A' to 'Z' for the second position
        for (int j = 65; j <= 90; j++)
        {
            // Loop through each character from 'A' to 'Z' for the third position
            for (int k = 65; k <= 90; k++)
            {
                // Print the combination of the three characters (e.g., "AAA", "AAB", ..., "ZZZ")
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}

int main()
{
    // Call the function to print all words from "AAA" to "ZZZ"
    Print_All_Words_From_AAA_To_ZZZ();

    return 0;
}

