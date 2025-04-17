/*
Problem 05 |=================================================

Write a program to fill a 3x3 matrix with random numbers,
then sum each Cols in separate array and print the results:

Output :

The following is a 3x3 random matrix: 

5  1  87 
46 12 2 
87 2  68

The the following are the sum of each col in the matrix :

Col 1 sum = 138
Col 2 Sum = 15 
Col 3 Sum = 157 

=============================================================
*/

#include <iostream>
#include <string>
#include <iomanip> // for setw to format matrix output
using namespace std;

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to fill a 3x3 matrix with random numbers between 1 and 100
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

// Function to print the matrix in a formatted grid
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " "; // setw aligns the numbers for better readability
        }
        cout << "\n";
    }
}

// Function to calculate the sum of a specific column
int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i <= Rows - 1; i++)
    {
        Sum += arr[i][ColNumber]; // Add each row's element in the specified column
    }
    return Sum;
}

// Function to calculate and store the sum of each column in a separate array
void SumMatixColsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        arrSum[i] = ColSum(arr, Rows, i); // Store column sum in arrSum
    }
}

// Function to print the column sums stored in an array
void PrintColsSumArray(int arr[3], short length)
{
    cout << "\nThe following are the sums of each column in the matrix:\n";
    for (short i = 0; i < length; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    // Seed the random number generator using current time
    srand((unsigned)time(NULL));

    int arr[3][3];     // 3x3 matrix
    int arrSum[3];     // Array to store the sum of each column

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(arr, 3, 3);

    // Print the generated matrix
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Calculate the sum of each column and store in arrSum
    SumMatixColsInArry(arr, arrSum, 3, 3);

    // Print the column sums
    PrintColsSumArray(arrSum, 3);

    // Pause the screen (Windows only) to view the output
    system("pause>0");

    return 0;
}
