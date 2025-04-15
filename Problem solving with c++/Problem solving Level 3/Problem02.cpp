/*
Problem 01 |=================================================

Write a program to fill a 3x3 matrix with random numbers,
then sum each row in separate array and print the results:

Output :

The following is a 3x3 random matrix:

16 43 6
13 51 3
24 19 100

The the following are the sum of each row in the matrix:
Row 1 Sum = 102

Row 2 Sum = 196

Row 3 Sum = 130

=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>  // for setw formatting
using namespace std;

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill a 3x3 matrix with random numbers from 1 to 100
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

// Function to print the matrix with formatted spacing
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " "; // setw(3) aligns output
        }
        cout << "\n";
    }
}

// Function to calculate the sum of a specific row in the matrix
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}

// Function to print the sum of each row in the matrix
void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following are the sums of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
    }
}

int main()
{
    // Seed the random number generator using current time
    srand((unsigned)time(NULL));

    // Declare a 3x3 matrix
    int arr[3][3];

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(arr, 3, 3);

    // Display the generated matrix
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Print the sum of each row in the matrix
    PrintEachRowSum(arr, 3, 3);

    // Pause the console to view the result before closing (Windows only)
    system("pause>0");

    return 0;
}

