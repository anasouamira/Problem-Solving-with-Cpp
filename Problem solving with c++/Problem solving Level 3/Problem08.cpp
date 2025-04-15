/*
Problem 01 |=================================================

Write a program to fill two 3x3 matrix with random numbers
and them, then multiply them into a 3rd matrix and print it.
Output :

Matrix1:
 06  01  07
 06  01  02
 09  06  01

Matrix2:
 10  09  06
 05  04  04
 07  09  01

Results:
 60  09  42
 30  04  08
 63  54  01

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

// Function to fill a 3x3 matrix with random numbers from 1 to 10
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10); // Fill each cell with a random number
        }
    }
}

// Function to print the matrix with formatted output
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each number with leading zero if needed (2 digits wide)
            printf(" %0*d ", 2, arr[i][j]);
            // Alternative: cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to multiply two matrices element-by-element
void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3],int MatrixResults[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Multiply corresponding elements and store in result matrix
            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

int main()
{
    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Declare matrices
    int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

    // Fill and print Matrix1
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Fill and print Matrix2
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    // Multiply matrices element by element
    MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);

    // Print the result of the multiplication
    cout << "\nResults:\n";
    PrintMatrix(MatrixResults, 3, 3);

    // Pause the console (for Windows)
    system("pause>0");

    return 0;
}
