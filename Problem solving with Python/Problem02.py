
"""
Problem02 |===============================================

Write a program to print all prime number From 1 to N 
order. 

Input : 
10

Output : 
1
2
3
5
7
==========================================================
"""
import math

def read_positive_number(message):
    """
    Function to read a positive number from the user.
    Ensures the input is greater than zero.
    """
    number = 0
    while number <= 0:
        try:
            number = int(input(message))  # Read and convert input to an integer
        except ValueError:
            print("Invalid input. Please enter a positive integer.")
    return number

def is_prime(number):
    """
    Function to check if a number is prime.
    Returns True if prime, otherwise False.
    """
    if number < 2:
        return False  # 1 is not a prime number
    
    m = int(math.sqrt(number))  # Check divisibility up to sqrt(Number)
    
    for i in range(2, m + 1):
        if number % i == 0:
            return False  # Number is not prime
    
    return True  # Number is prime

def print_prime_numbers_from_1_to_n(n):
    """
    Function to print all prime numbers from 1 to a given number.
    """
    print(f"\nPrime Numbers from 1 to {n} are:")
    
    for i in range(1, n + 1):
        if is_prime(i):
            print(i, end=" ")  # Print primes in a single line
    
    print()  # Move to a new line after printing all primes

# Main entry point
if __name__ == "__main__":
    n = read_positive_number("Please enter a positive number: ")
    print_prime_numbers_from_1_to_n(n)



