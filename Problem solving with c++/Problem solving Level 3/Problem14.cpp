/*
Problem 14 |=================================================

Write a program to check if the matrix is Scalar or not.

Output :

Matrix1: 
1  0  0
0  1  0
0  0  1

YES: Matrix is Scalar.
=============================================================
*/
#include <iostream>
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

// Function to check if the matrix is a scalar matrix
bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    // Get the value of the first diagonal element to compare with others
    int diagonalValue = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j)
            {
                // Diagonal elements must all be equal to the first one
                if (Matrix1[i][j] != diagonalValue)
                    return false;
            }
            else
            {
                // Non-diagonal elements must be 0
                if (Matrix1[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int Matrix1[3][3] = {
        {9, 0, 0},
        {0, 9, 0},
        {0, 0, 9}
    };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsScalarMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is Scalar.";
    else
        cout << "\nNO: Matrix is NOT Scalar.";

    system("pause>0");
}
