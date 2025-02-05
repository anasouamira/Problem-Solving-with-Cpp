/*
Problem 31 |=================================================
Write a program to fill array with ordered numbers from 1 to N,
then print it, after that shuffle this array and print it after shuffle.

Input:
10

Output:

Array elements before shuffle:
1 2 3 4 5 6 7 8 9 10 

Array elements after shuffle:
2 4 6 3 10 1 7 8 5 9
=============================================================
*/
#include <iostream>
using namespace std;

// Function to read a positive number from the user
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

// Function to swap two integers by reference
void Swap(int &A, int &B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

// Function to fill an array with values from 1 to N
void FillArrayWith1toN(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

// Function to generate a random number within a given range
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function to shuffle an array randomly
void ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1],
            arr[RandomNumber(1, arrLength) - 1]);
    }
}

// Function to print an array
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
    
    int arr[100];
    int arrLength = ReadPositiveNumber("\nEnter number of elements : \n");
    
    FillArrayWith1toN(arr, arrLength);
    
    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr, arrLength);
    
    ShuffleArray(arr, arrLength);
    
    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr, arrLength);
    
    return 0;
}
