/*
Problem 01 |=================================================

Write a program to fill a 3x3 matrix with random numbers : 

Output : 

The following is a 3x3 random matrix:

16 43 6
13 51 3 
24 19 100 

=============================================================
*/
#include <iostream> // Required for input/output
#include <string>   // Required if using string (not used here though)
#include <iomanip>  // Required for setw (to format output spacing)
using namespace std;

// Function to generate a random number between From and To
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
            arr[i][j] = RandomNumber(1, 100); // Assign a random number to each element
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
            cout << setw(3) << arr[i][j] << "\t"; // setw(3) ensures proper spacing
        }
        cout << "\n"; // New line after each row
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    system("pause>0");
}
