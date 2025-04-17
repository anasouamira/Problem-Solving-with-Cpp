/*
Problem 11 |=================================================

Write a program to compare two matrices and check if they
are equal or not.

Output :

Matrix1:
 04  09  02
 04  10  08
 10  05  01

 Matrix2:
 04  09  02
 04  10  08
 10  05  09

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

// Function to fill a matrix with random numbers between 1 and 10
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10); // Assign a random number to each element
        }
    }
}

// Function to print the matrix in a formatted way
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each number as 2 digits (with leading 0 if needed)
            printf(" %0*d ", 2, arr[i][j]);
            // Alternative: cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // Move to the next line after each row
    }
}

// Function to compute the sum of all elements in a matrix
int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix1[i][j];
        }
    }
    return Sum;
}

// Function to check if two matrices are equal in terms of their total sum
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    // Compare the total sum of elements from both matrices
    return (SumOfMatrix(Matrix1, Rows, Cols) ==
            SumOfMatrix(Matrix2, Rows, Cols));
}

int main()
{
    // Seed the random number generator once at the beginning
    srand((unsigned)time(NULL));

    // Declare two 3x3 matrices
    int Matrix1[3][3], Matrix2[3][3];

    // Fill both matrices with random values
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    // Compare the matrices based on the sum of their elements
    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
        cout << "\nYES: both matrices are equal.";
    else
        cout << "\nNo: matrices are NOT equal.";

    // Wait for user input before closing (on Windows)
    system("pause>0");
}
