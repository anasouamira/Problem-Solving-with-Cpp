/*
Problem 18 |=================================================

Write a program to check it the matrix is Palindrome or not.

Output :

Matrix1: 
1    2    1
8    7    8
5    4    5

Yes: Matrix is Palindrome.
=============================================================
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function to print the matrix with proper formatting
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Print each element with 3-character width
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n"; // Move to the next line after each row
    }
}

// Function to check if each row in the matrix is a palindrome
// A row is a palindrome if it reads the same forward and backward
int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            // Compare the j-th element from the start with the j-th from the end
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false; // Not a palindrome if mismatch found
            }
        }
    }
    return true; // All rows are palindromes
}

int main()
{
    // Define and initialize the matrix
    int Matrix1[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};

    // Print the matrix
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    // Check if the matrix is a row-wise palindrome
    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
    {
        cout << "\nNo: Matrix is NOT Palindrome\n";
    }

    // Pause system to view output
    system("pause>0");
}
