/*
Problem 18 |=================================================

Write a program fo print Fibonacci Series of 10.

Output :

1  1  2  3  5  8  13  21  34  55

=============================================================
*/
#include <iostream>
using namespace std;

// Function to print Fibonacci sequence up to 'Number' terms using a loop
void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;      // To store the current Fibonacci number
    int Prev2 = 0, Prev1 = 1; // Initialize the first two terms: 0 and 1

    // Print the first term manually (1)
    cout << "1 ";

    // Loop starts from the 2nd index up to 'Number'
    for (short i = 2; i <= Number; ++i)
    {
        // Calculate the next Fibonacci number
        FebNumber = Prev1 + Prev2;

        // Print the current Fibonacci number
        cout << FebNumber << " ";

        // Update previous two numbers for next iteration
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main()
{
    // Call the function to print first 10 Fibonacci numbers
    PrintFibonacciUsingLoop(10);

    // Pause the console screen to see output
    system("pause>0");
}
