
"""
Problem 46 |====================================================
Write a program to print abs of numbers , don't use built in abs 
function 

Input:
-10

Output:

My abs Result : 10
C++ abs Result: 10
================================================================
"""
# Function to calculate the absolute value of a number
# Returns the positive value of the input number
def my_abs(number):
    if number > 0:
        return number
    else:
        return number * -1

# Function to prompt the user to enter a number
# Reads and returns a floating-point number from the user
def read_number():
    number = float(input("Please enter a number: "))
    return number

if __name__ == "__main__":
    # Read a number from the user
    number = read_number()

    # Display the result of the custom absolute value function
    print("My abs Result:", my_abs(number))

    # Display the result of the built-in Python abs function
    print("Python abs Result:", abs(number))

