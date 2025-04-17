/*
Problem 01 |=================================================

Write a program to check if the matrix is Sparse or not.

Output :

Matrix1: 
0  0   1
0  0   12
0  0   5

Yes: It is Sparse
=============================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> // Needed for ceil()
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
                NumberCount++;
            }
        }
    }
    return NumberCount;
}

// Function to check if a matrix is sparse
bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    short ZeroCount = CountNumberInMatrix(Matrix1, 0, Rows, Cols);
    return (ZeroCount >= ceil((float)MatrixSize / 2));
}

int main()
{
    int Matrix1[3][3] = { {0, 0, 12}, {9, 9, 1}, {0, 0, 9} };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: It is a Sparse Matrix.\n";
    else
        cout << "\nNo: It's NOT a Sparse Matrix.\n";

    system("pause>0");
}
