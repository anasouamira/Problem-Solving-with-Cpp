/*
Problem 18 |=================================================

Write a program to print the intersected numbers in two
given matrices.

Output :

Matrix1: 
77  15   4
0   7    12
12  6    5

Matrix2: 
77  56   1
0   2    12
12  6    5

Intersected Numbers are: 
77 12 0 6 5
=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to print a matrix in a formatted way
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

// Function to check if a given number exists in the matrix
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true; // Return early if number is found
            }
        }
    }
    return false; // Return false if number not found
}

// Function to print numbers that appear in both matrices (intersection)
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    int Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
            {
                cout << setw(3) << Number << " ";
            }
        }
    }
}

int main()
{
    // Define two 3x3 matrices
    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    int Matrix2[3][3] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};

    // Display Matrix1
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Display Matrix2
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    // Display intersection of Matrix1 and Matrix2
    cout << "\nIntersected Numbers are:\n\n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

    cout << "\n";
    system("pause>0");
}
