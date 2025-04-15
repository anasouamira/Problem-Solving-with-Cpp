/*
Problem 01 |=================================================

Write a program to fill a 3x3 matrix with random numbers,
then print each Col sum:

Output :

The following is a 3x3 random matrix: |

5  1  87 
46 12 2 
87 2  68

The the following are the sum of each col in the matrix
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

// Function to fill a 3x3 matrix with random numbers from 1 to 100
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100); // Assign random number to each cell
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
            cout << setw(3) << arr[i][j] << " "; // setw(3) aligns columns
        }
        cout << "\n";
    }
}

// Function to calculate the sum of a given column
int ColSum(int arr[3][3], short Rows, short ColNumber)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColNumber]; // Add the value from each row at the same column
    }
    return Sum;
}

// Function to print the sum of each column in the matrix
void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following are the sums of each column in the matrix:\n";
    for (short j = 0; j < Cols; j++)
    {
        cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
    }
}

int main()
{
    // Seed the random number generator once using current time
    srand((unsigned)time(NULL));

    int arr[3][3]; // Declare a 3x3 matrix

    // Fill the matrix with random numbers
    FillMatrixWithRandomNumbers(arr, 3, 3);

    // Print the matrix
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    // Print the sum of each column
    PrintEachColSum(arr, 3, 3);

    // Pause the program (Windows only) to view output
    system("pause>0");

    return 0;
}