"""
Problem04 |===============================================

Write a program to print all perfect number From 1 to N 
order. 

Input : 
500

Output : 
6
28
496
==========================================================
"""



def read_positive_number(message):
    """
    Function to read a positive number from the user.
    Ensures the input is greater than or equal to zero.
    """
    number = -1  # Initialize with an invalid value
    while number < 0:
        try:
            number = int(input(message))  # Read and convert input to an integer
            if number < 0:
                print("Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter an integer.")
    return number

def is_perfect_number(number):
    """
    Function to check if a given number is a perfect number.
    A perfect number is a number whose proper divisors sum to itself.
    """
    m = number // 2  # Only check divisors up to half the number
    sum_divisors = sum(divisor for divisor in range(1, m + 1) if number % divisor == 0)

    return sum_divisors == number  # Returns True if it's a perfect number

def print_perfect_numbers(n):
    """
    Function to print all perfect numbers from 1 to the given number.
    """
    print(f"\nPerfect numbers from 1 to {n}:")
    
    for i in range(1, n + 1):
        if is_perfect_number(i):
            print(i, end=" ")  # Print perfect numbers in a single line

    print()  # Move to a new line after printing

# Main entry point
if __name__ == "__main__":
    num = read_positive_number("Enter a positive number to find all perfect numbers from 1 to N: ")
    print_perfect_numbers(num)

