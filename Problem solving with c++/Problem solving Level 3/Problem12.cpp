/*
Problem 12 |=================================================

Write a program to compare two matrices and check if they
are typical or not.

Output :

Matrix1:
 04  09  02
 04  10  08
 10  05  01

 Matrix2:
 04  09  02
 04  10  08
 10  05  01

No: matrices are NOT equal.

=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to generate a random number between From and To
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill the matrix with random numbers from 1 to 10
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10); // Assign random number to each cell
        }
    }
}

// Function to print a matrix with formatting
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each element with width of 2 digits
            printf(" %0*d ", 2, arr[i][j]);
            // Alternatively: cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // Move to next row
    }
}

// Function to check if two matrices are exactly the same (element by element)
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j]) // Compare each element
            {
                return false; // If any element is different, return false
            }
        }
    }
    return true; // All elements matched
}

int main()
{
    // Seed the random number generator (do this only once)
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    // Fill both matrices with random numbers
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    // Check if matrices are exactly equal
    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
        cout << "\nYES: both matrices are equal.";
    else
        cout << "\nNO: matrices are NOT equal.";

    // Pause the screen (for Windows)
    system("pause>0");
}
