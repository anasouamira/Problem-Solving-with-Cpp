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

// This is my code solution :

#include <iostream>
using namespace std;


void Print_All_Words_From_AAA_To_ZZZ()
{

    for (int i = 65; i <= 90; i++)
    {

        for (int j = 65; j <= 90; j++)
        {

            for (int k = 65; k <= 90; k++)
            {

                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}

int main()
{
    Print_All_Words_From_AAA_To_ZZZ();

    return 0;
}
