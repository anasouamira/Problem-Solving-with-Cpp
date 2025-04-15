/*
Problem 01 |=================================================

Write a program fo fill a 3x3 matrix with random numbers,
then print each row sum :

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
#include <iomanip> // For setw formatting
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
            arr[i][j] = RandomNumber(1, 100); // Assign random number to each element
        }
    }
}

// Function to print the matrix with formatting
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " "; // setw(3) aligns numbers in columns
        }
        cout << "\n";
    }
}

// Function to compute the sum of a specific row in the matrix
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j]; // Add each element in the row
    }
    return Sum;
}

// Function to fill an array with the sum of each row in the matrix
void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols); // Store each row's sum into arrSum
    }
}

// Function to print the row sums stored in a separate array
void PrintRowsSumArray(int arr[3], short Rows)
{
    cout << "\nThe following are the sums of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    // Seeds the random number generator based on current time
    srand((unsigned)time(NULL));

    int arr[3][3];    // 3x3 matrix
    int arrSum[3];    // Array to hold row sums

    // Fill and print matrix
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Compute and print row sums
    SumMatixRowsInArry(arr, arrSum, 3, 3);
    PrintRowsSumArray(arrSum, 3);

    // Pause console (Windows only)
    system("pause>0");

    return 0;
}
