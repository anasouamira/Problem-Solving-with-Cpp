"""
Problem 50 |=================================================
Write a program to print Sqrt of numbers , don't use built in
sqrt function

Input: 
25

Output:

My MySqrt Result : 5
C++ sqrt Result: 5
=============================================================
"""
import math

# Function to calculate the square root of a number
def my_sqrt(number):
    return number ** 0.5  # Equivalent to pow(number, 0.5)

# Function to read a number from the user
def read_number():
    return float(input("Please enter a number: "))

# Main function
if __name__ == "__main__":
    number = read_number()
    
    # Display results using custom and built-in sqrt functions
    print("My MySqrt Result:", my_sqrt(number))
    print("Python sqrt Result:", math.sqrt(number))
