"""
Problem 36 |=================================================
Write a program to dynamically read numbers and save them in an array
Max size of array is 100, allocate simi-dynamic array length.

Output:

Please enter a number? 10

Do you want to add more numbers? [0}No,[1 yes? 1
Please enter a number? 20

Do you want to add more numbers? [0}No,[1 yes? 1
Please enter a number? 30

Do you want to add more numbers? [0JNo [1}yes? 0

Array Length: 3
Array elements: 10 20 30
=============================================================
"""
def read_number() -> int:
    """
    Reads an integer number from the user.
    """
    return int(input("\nPlease enter a number? "))

def add_array_element(number: int, arr: list):
    """
    Adds an element to the array.
    """
    arr.append(number)

def input_user_numbers_in_array() -> list:
    """
    Allows the user to input multiple numbers into the array.
    """
    arr = []
    while True:
        add_array_element(read_number(), arr)
        
        # Ask the user if they want to add more numbers
        add_more = input("\nDo you want to add more numbers? [0]:No,[1]:Yes? ")
        if add_more != "1":
            break
    return arr

def print_array(arr: list):
    """
    Prints all elements of the array.
    """
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    # Get user input to fill the list
    arr = input_user_numbers_in_array()
    
    # Display the array length and elements
    print("\nArray Length:", len(arr))
    print("Array elements: ", end="")
    print_array(arr)
