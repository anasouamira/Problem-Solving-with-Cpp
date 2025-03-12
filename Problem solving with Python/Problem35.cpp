"""
Problem 35 |=================================================
Write a program to fill array with max size 100 with random numbers from
1 t0 100, read number and print if it's found or not (reuse code in prev
problem).

Input
10

Output:

Array 1 elements:
83 92 66 21 62 96 40 13 19 30

Please enter a number to search for?
66
19

Number you are looking for is: 66
Yes, The number is found :-)

Number you are looking for is: 19
No, The number is not found :-(


=============================================================

"""
#include <iostream>
using namespace std;
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for?\n";
    cin >> Number;
    return Number;
}
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // return the index
    }
    // if you reached here, this means the number is not found
    return -1;
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;
    if (!IsNumberInArray(Number, arr, arrLength))
        cout << "No, The number is not found :-(\n";
    else
    {
        cout << "Yes it is found :-)\n";
    }
    
    return 0;
}