/*
Problem 13 |=================================================

Write a program to check if the matrix is identity or not.

Output :

Matrix1: 
1  0  0
0  1  0
0  0  1

YES: Matrix is identity.
=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to print a matrix with proper formatting
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each element with a width of 3 for alignment
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // New line after each row
    }
}

// Function to check if a matrix is an identity matrix
bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    // Check that diagonal elements are 1 and non-diagonal elements are 0
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix1[i][j] != 1) // Diagonal elements must be 1
                return false;
            else if (i != j && Matrix1[i][j] != 0) // Non-diagonals must be 0
                return false;
        }
    }
    return true; // All checks passed
}

int main()
{
    // Define a sample 3x3 identity matrix
    int Matrix1[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Check if it's an identity matrix
    if (IsIdentityMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNO: Matrix is NOT identity.";

    system("pause>0"); // Wait for user before closing (Windows-specific)
}
