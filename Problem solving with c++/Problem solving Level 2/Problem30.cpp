/*
Problem 30 |============================================================
Write a program to fill array two arrays with max size 100 with random
numbers from 1 to 100, sum their elements in a third array and print the
results.

Input:
10

Output:

Array 1 elements:
42 68 35 1 70 25 79 59 63 65

Array 2 elements:
6 46 82 28 62 92 96 43 28 37

Sum of array1 and array2 elements: 
48 114 117 29 132 117 175 102 91 102

=========================================================================

*/

#include <iostream>
using namespace std;
// Function to generate a random number between 'From' and 'To'
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
// Function to read a positive integer from the user
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
// Function to fill an array with random numbers between 1 and 100
void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
// Function to compute the sum of corresponding elements in two arrays
void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

// Function to print the elements of an array
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arrSum[100];
    int arrLength = ReadPositiveNumber("How many elements ?\n");
    FillArrayWithRandomNumbers(arr, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);
    SumOf2Arrays(arr, arr2, arrSum, arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements:\n";
    PrintArray(arr2, arrLength);
    cout << "\nSum of array1 and array2 elements:\n";
    PrintArray(arrSum, arrLength);
    return 0;
}
