/*
Problem 01 |=================================================

Write a program to fill two 3x3 matrix with random numbers
and them, then write a function to sum all numbers in this
matrix and print it.

Output :

Matrix1:
 04  09  02
 04  10  08
 10  05  01

Sum of Matrix1 is: 53

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
            arr[i][j] = RandomNumber(1, 10); // Assign a random number to each cell
        }
    }
}

// Function to print the matrix with two-digit formatting
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each number with leading zero if needed (2 digits wide)
            printf(" %0*d ", 2, arr[i][j]);
            // Alternatively: cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // Move to the next line after each row
    }
}

// Function to calculate the sum of all elements in the matrix
int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix1[i][j]; // Add each element to the total sum
        }
    }
    return Sum;
}

int main()
{
    // Seed the random number generator once
    srand((unsigned)time(NULL));

    // Declare the matrix
    int Matrix1[3][3];

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    // Display the matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Calculate and display the sum of all elements
    cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, 3, 3);

    // Pause the system (for Windows)
    system("pause>0");
}
