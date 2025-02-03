/*
Problem19 |===============================================

Write a program to print 3 random numbers from 1 to 10 

Output :
6
2
3
==========================================================
*/

// This is my code solution :

#include <iostream>
#include <cstdlib> 
using namespace std; 

int RandomNumber(int From, int To) 
{ 
//Function to generate a random number 
int randNum = rand() % (To - From + 1) + From; 
return randNum; 
} 
int main() { 
//Seeds the random number generator in C++, called only once 
    srand((unsigned)time(NULL)); 
    
    cout << RandomNumber(1, 10) << endl; 
    cout << RandomNumber(1, 10) << endl; 
    cout << RandomNumber(1, 10) << endl; 
return 0; 
} 