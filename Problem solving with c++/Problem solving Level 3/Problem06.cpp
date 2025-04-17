/*
Problem 06 |=================================================

Write a program to fill a 3x3 matrix with ordered numbers.

Output :

The following is a 3x3 ordered matrix:
1  2  3
4  5  6
7  8  9
=============================================================
*/
#include <iostream>
#include <string>
using namespace std;

// Function to fill a 3x3 matrix with ordered numbers starting from 1
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0; // Counter to store increasing numbers
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;           // Increment counter for each cell
            arr[i][j] = Counter; // Assign current counter to the matrix cell
        }
    }
}

// Function to print the contents of the matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << " "; // Print each element with space
        }
        cout << "\n"; // Newline after each row
    }
}

int main()
{
    int arr[3][3]; // Declare a 3x3 matrix

    // Fill matrix with ordered numbers from 1 to 9
    FillMatrixWithOrderedNumbers(arr, 3, 3);

    // Print the filled matrix
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Pause the console (for Windows only)
    system("pause>0");

    return 0;
}
