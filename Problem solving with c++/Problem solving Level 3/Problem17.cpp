/*
Problem 17 |=================================================

Write a program to check if a given number exists in matrix
or not.

Output :

Matrix1: 
77  0   1
0   0   12
12  6   5

Please Enter the number to look for in matrix? 77
Yes it is there. 
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
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to count occurrences of a number in the matrix
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            };
        }
    }
    return NumberCount;
}

// Optimized function to check if a number exists in the matrix
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true; // Exit early if number found
            };
        }
    }
    return false;
}

int main()
{
    // Example matrix
    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    int Number;
    cout << "\nPlease Enter the number to look for in matrix? ";
    cin >> Number;

    // Using Count is a slower method
    if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0)
        cout << "\nYes, it is there (using Count).\n";
    else
        cout << "\nNo, It's NOT there (using Count).\n";

    // Faster method using early exit
    if (IsNumberInMatrix(Matrix1, Number, 3, 3))
        cout << "\nYes, it is there (using IsNumberInMatrix).\n";
    else
        cout << "\nNo, It's NOT there (using IsNumberInMatrix).\n";

    system("pause>0");
}
