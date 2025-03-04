"""
Problem06 |===============================================

Write a program to read a number and print all the sum of
its digits

Input : 
1234

Output :

sum of Digit = 10

==========================================================
"""


def read_positive_number(message):
    """
    Function to read a positive integer from the user.
    Ensures that the input is non-negative.
    
    :param message: The prompt message displayed to the user.
    :return: The validated positive integer.
    """
    number = -1  # Initialize with an invalid value
    while number < 0:
        try:
            number = int(input(message))  # Read and convert input to an integer
            if number < 0:
                print("Please enter a non-negative integer.")
        except ValueError:
            print("Invalid input. Please enter an integer.")
    return number

def calculate_sum_of_digits(number):
    """
    Function to calculate and print the sum of the digits of a given number.

    :param number: The number whose digits will be summed.
    """
    sum_digits = 0  # Variable to store the sum of digits
    
    while number > 0:
        remainder = number % 10  # Extract the last digit
        sum_digits += remainder  # Add it to the sum
        number //= 10  # Remove the last digit
    
    print(f"Sum of digits: {sum_digits}")

# Main entry point
if __name__ == "__main__":
    num = read_positive_number("Enter a positive number to calculate the sum of its digits: ")
    calculate_sum_of_digits(num)

