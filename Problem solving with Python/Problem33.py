"""
Problem 33 |=================================================
Write a program to read how many keys to generate and fill
them in array then print them on the screen.

Input:
5 

Output:
Array elements:

Array[0] : NRXC-DXRO-QEAM-WRWE
Array[1] : BJTR-KIKF-ATEW-WNTT
Array[2] : QOFX-KZEL-SSDP-AKST
Array[3] : GFOL-ELFX-ZCVE-PSTP
Array[4] : MATF-PRQA-PQEQ-TRIM
=============================================================

"""
import random
import string

class CharType:
    SMALL_LETTER = 1
    CAPITAL_LETTER = 2
    SPECIAL_CHARACTER = 3
    DIGIT = 4

def random_number(from_val: int, to_val: int) -> int:
    """
    Generates a random number between 'from_val' and 'to_val' (inclusive).
    """
    return random.randint(from_val, to_val)

def get_random_character(char_type: int) -> str:
    """
    Returns a random character based on the given character type.
    """
    if char_type == CharType.SMALL_LETTER:
        return random.choice(string.ascii_lowercase)
    elif char_type == CharType.CAPITAL_LETTER:
        return random.choice(string.ascii_uppercase)
    elif char_type == CharType.SPECIAL_CHARACTER:
        return random.choice(string.punctuation)
    elif char_type == CharType.DIGIT:
        return random.choice(string.digits)

def generate_word(char_type: int, length: int) -> str:
    """
    Generates a word consisting of characters of a given type.
    """
    return ''.join(get_random_character(char_type) for _ in range(length))

def generate_key() -> str:
    """
    Generates a random key in the format XXXX-XXXX-XXXX-XXXX (capital letters only).
    """
    return "-".join(generate_word(CharType.CAPITAL_LETTER, 4) for _ in range(4))

def fill_array_with_keys(arr_length: int) -> list:
    """
    Fills an array with randomly generated keys.
    """
    return [generate_key() for _ in range(arr_length)]

def print_string_array(arr: list):
    """
    Prints an array of strings.
    """
    print("\nArray elements:\n")
    for i, key in enumerate(arr):
        print(f"Array[{i}] : {key}")
    print("\n")

def read_positive_number(message: str) -> int:
    """
    Reads a positive number from the user.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                return number
        except ValueError:
            pass
        print("Please enter a positive integer.")

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr_length = read_positive_number("How many keys do you want to generate?\n")
    
    arr = fill_array_with_keys(arr_length)

    print_string_array(arr)
