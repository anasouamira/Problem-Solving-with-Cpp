/*
Problem 01 |=================================================

Write a program to count given number in matrix.

Output :

Matrix1: 
1  12  1
0  1   0
0  5   1

Enter the number to count in matrix? 1
Number 9 count in matrix is 4
=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to print a matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";  // prints each element with padding
        }
        cout << "\n";
    }
}

// Function to count how many times a number appears in the matrix
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;  // increment count if the number matches
            }
        }
    }
    return NumberCount;
}

int main()
{
    // Sample matrix
    int Matrix1[3][3] = {
        {9, 1, 12},
        {0, 9, 1},
        {0, 9, 9}
    };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Ask user for a number to search
    int Number;
    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;

    // Output how many times the number appears
    cout << "\nNumber " << Number << " count in matrix is "
         << CountNumberInMatrix(Matrix1, Number, 3, 3);

    system("pause>0");
}
