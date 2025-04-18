/*
Problem 19 |=================================================

Write a program to print the Minimum and Maximum Numbers
in Matrix.

Output :

Matrix1: 
77  15   4
0   7    12
12  6    5

Minimum Number is: 0
Max Number is: 77
=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to print a 3x3 matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each element with proper spacing
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // Move to next row after printing all columns
    }
}

// Function to find and return the minimum number in the matrix
int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Min = Matrix1[0][0]; // Assume first element is minimum
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < Min)
            {
                Min = Matrix1[i][j]; // Update minimum if smaller element is found
            }
        }
    }
    return Min; // Return the smallest number found
}

// Function to find and return the maximum number in the matrix
int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Max = Matrix1[0][0]; // Assume first element is maximum
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > Max)
            {
                Max = Matrix1[i][j]; // Update maximum if larger element is found
            }
        }
    }
    return Max; // Return the largest number found
}

int main()
{
    // Declare and initialize the matrix
    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 6}, {14, 3, 9}};

    // Print the matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Display the minimum number in the matrix
    cout << "\nMinimum Number is: ";
    cout << MinNumberInMatrix(Matrix1, 3, 3);

    // Display the maximum number in the matrix
    cout << "\n\nMax Number is: ";
    cout << MaxNumberInMatrix(Matrix1, 3, 3);

    // Pause the system to view output
    system("pause>0");
}
