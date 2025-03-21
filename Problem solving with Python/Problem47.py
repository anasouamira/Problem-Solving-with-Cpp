"""
Problem 47 |==================================================
Write a program to print round of numbers , don't use built in
round function

Input: 
10.7

Output: 
My Round Result : 11 
C++ Round Result: 11

Input:
10.3

Output:
My Round Result : 10
C++ Round Result: 10

Input:
-10.7

Output:
My Round Result : -11
C++ Round Result: -11
==============================================================
"""
# Function to get the fractional part of a floating-point number
# Example: If Number = 4.75, it returns 0.75
def get_fraction_part(number):
    return number - int(number)

# Function to round a floating-point number to the nearest integer
# It uses custom rounding logic similar to standard rounding rules
def my_round(number):
    # Get the integer part of the number
    int_part = int(number)

    # Get the fractional part of the number using get_fraction_part()
    fraction_part = get_fraction_part(number)

    # If the absolute value of the fractional part is greater than or equal to 0.5
    if abs(fraction_part) >= 0.5:
        # If the number is positive, round up
        if number > 0:
            return int_part + 1
        # If the number is negative, round down
        else:
            return int_part - 1
    else:
        # If the fractional part is less than 0.5, return the integer part
        return int_part

# Function to read a floating-point number from the user
def read_number():
    number = float(input("Please enter a float number: "))
    return number

if __name__ == "__main__":
    # Read the number from the user
    number = read_number()

    # Display the result of custom rounding using my_round()
    print("My Round Result:", my_round(number))

    # Display the result of standard Python rounding using round()
    print("Python Round Result:", round(number))

