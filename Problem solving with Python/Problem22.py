"""
Problem 22 |=============================================================================

Write a program to read N elements and store them in array then print all array elements
and ask for a number to check, then print how many number a certain element repeated in
that array.

Input:

5

Enter array elements:

Element [1]: 1

Element [2]: 1

Element [3]: 1

Element [4]: 2

Element [5]: 3

Enter the number you want to check: 1

Output: 

Original array: 11123 
1 is repeated 3 time(s)
==========================================================================================

"""

def read_positive_number(message: str) -> int:
    """
    Reads a positive integer from the user.
    """
    while True:
        try:
            number = int(input(message + "\n"))
            if number > 0:
                return number
        except ValueError:
            pass
        print("Please enter a valid positive number.")

def read_array() -> list:
    """
    Reads an array of integers from the user.
    """
    arr = []
    try:
        arr_length = int(input("\nEnter number of elements:\n"))
        print("\nEnter array elements: ")
        for i in range(arr_length):
            element = int(input(f"Element [{i + 1}] : "))
            arr.append(element)
    except ValueError:
        print("Invalid input. Please enter integers only.")
    
    print()
    return arr

def print_array(arr: list):
    """
    Prints the array elements.
    """
    print(" ".join(map(str, arr)))

def times_repeated(number: int, arr: list) -> int:
    """
    Counts how many times a specific number appears in the array.
    """
    return arr.count(number)

if __name__ == "__main__":
    # Read the array from the user
    arr = read_array()

    # Read the number to check for repetitions
    number_to_check = read_positive_number("Enter the number you want to check:")

    # Display the original array
    print("\nOriginal array: ", end="")
    print_array(arr)

    # Display how many times the number is repeated in the array
    print(f"\nNumber {number_to_check} is repeated {times_repeated(number_to_check, arr)} time(s)")



