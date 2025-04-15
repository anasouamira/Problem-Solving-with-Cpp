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
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short
Cols)
{
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
arr[i][j] = RandomNumber(1, 100);
}
}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
cout << setw(3) << arr[i][j] << " ";
}
cout << "\n";
}
}
int RowSum(int arr[3][3],short RowNumber, short Cols)
{
int Sum = 0;
for (short j = 0; j <= Cols - 1; j++)
{
Sum += arr[RowNumber][j];
}
return Sum;
}
void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short
Rows,short Cols)
{
for (short i = 0; i < Rows; i++)
{
arrSum[i] = RowSum(arr, i, Cols);
}
}
void PrintRowsSumArray(int arr[3], short Rows)
{
cout << "\nThe the following are the sum of each row in thematrix:\n";
for (short i = 0; i < Rows; i++)
{
cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
}
}
int main()
{
//Seeds the random number generator in C++, called only once
srand((unsigned)time(NULL));
int arr[3][3];
int arrSum[3];
FillMatrixWithRandomNumbers(arr, 3, 3);
cout << "\nThe following is a 3x3 random matrix:\n";
PrintMatrix(arr, 3, 3);
SumMatixRowsInArry(arr, arrSum, 3,3);
PrintRowsSumArray(arrSum, 3);
system("pause>0");
}