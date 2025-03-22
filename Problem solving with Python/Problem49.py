"""
Problem 49 |=================================================
Write a program to print Ceil of numbers , don't use built in Ceil
function

Input: 
10.7

Output: 
My Round Result : 11
C++ Round Result: 11

Input:
-10.7

Output:
My Round Result : -10
C++ Round Result: -10
=============================================================
"""
import math

# Function to get the fractional part of a floating-point number
def get_fraction_part(number):
    return number - int(number)

# Custom implementation of ceil function
def my_ceil(number):
    integer_part = int(number)  # Get integer part
    if number > 0 and get_fraction_part(number) > 0:
        return integer_part + 1
    return integer_part

# Function to read a number from user input
def read_number():
    return float(input("Please enter a number: "))

# Main function
if __name__ == "__main__":
    number = read_number()
    
    # Displaying results
    print("My MyCeil Result:", my_ceil(number))
    print("Python ceil Result:", math.ceil(number))
