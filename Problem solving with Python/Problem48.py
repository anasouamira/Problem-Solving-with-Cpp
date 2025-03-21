"""
Problem 48 |=================================================
Write a program to print floor of numbers , don't use built in
floor function 

Input: 
10.7

Output: 
My Round Result : 10 
C++ Round Result: 10

Input:
10.3

Output:
My Round Result : 10
C++ Round Result: 10

Input:
-10.3

Output:
My Round Result : -11
C++ Round Result: -11
=============================================================
"""
import math

# Function to find the floor of a floating-point number
# Floor of a number is the greatest integer less than or equal to the number
def my_floor(number):
    # If the number is positive, the floor is simply the integer part
    if number > 0:
        return int(number)
    else:
        # If the number is negative and not an exact integer, subtract 1
        return int(number) - 1

# Function to read a floating-point number from the user
def read_number():
    number = float(input("Please enter a number: "))
    return number

if __name__ == "__main__":
    # Read the number from the user
    number = read_number()

    # Display the result of custom floor calculation using my_floor()
    print("My MyFloor Result:", my_floor(number))

    # Display the result of standard Python floor calculation using math.floor()
    print("Python floor Result:", math.floor(number))


