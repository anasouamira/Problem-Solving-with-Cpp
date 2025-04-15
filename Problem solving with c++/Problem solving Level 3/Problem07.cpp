/*
Problem 01 |=================================================

Write a program to fill a 3x3 matrix with ordered numbers
and print it, then transpose matrix and print it. 

Output :

The following is a 3x3 ordered matrix:
1  2  3
4  5  6
7  8  9

The following is the transposed matrix:
1  4  7 
2  5  8
3  6  9
=============================================================
*/
#include <iostream>
#include <string>
using namespace std;

// Function to fill a 3x3 matrix with ordered numbers starting from 1
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0; // Counter to hold increasing values
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;           // Increment counter
            arr[i][j] = Counter; // Assign value to matrix element
        }
    }
}

// Function to print the matrix in grid format
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << " " << arr[i][j] << " "; // Print each element with space
        }
        cout << "\n"; // Newline after each row
    }
}

// Function to transpose a matrix (swap rows with columns)
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i]; // Swap row and column indices
        }
    }
}

int main()
{
    int arr[3][3], arrTransposed[3][3]; // Declare original and transposed matrices

    // Fill the original matrix with ordered numbers
    FillMatrixWithOrderedNumbers(arr, 3, 3);

    // Print the original matrix
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Transpose the matrix
    TransposeMatrix(arr, arrTransposed, 3, 3);

    // Print the transposed matrix
    cout << "\n\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);

    // Pause the console (for Windows only)
    system("pause>0");

    return 0;
}
