"""
Problem17 |===============================================

Write a program to guess a 3-Letter Password (all capital)?

Input :

AAD

Output : 

Trial[1] : AAA
Trial[2] : AAB
Trial[3] : AAC
Trial[4] : AAD

Password is AAD
Found After 4 Trial(s)

==========================================================
"""
def read_password() -> str:
    """
    Reads a 3-letter password from the user.

    Returns:
    str: The user-entered password.
    """
    return input("Please enter a 3-letter password (all capital): ").strip().upper()

def guess_password(original_password: str) -> bool:
    """
    Tries to guess the given password by iterating through all possible 3-letter combinations.

    Args:
    original_password (str): The actual password to guess.

    Returns:
    bool: True if the password is found, otherwise False.
    """
    counter = 0  # Initialize the trial counter

    print("\n")
    # Loop through all possible combinations of 3 uppercase letters (A-Z)
    for i in range(ord('A'), ord('Z') + 1):  # First character (A-Z)
        for j in range(ord('A'), ord('Z') + 1):  # Second character (A-Z)
            for k in range(ord('A'), ord('Z') + 1):  # Third character (A-Z)
                word = f"{chr(i)}{chr(j)}{chr(k)}"  # Form the guessed word
                counter += 1  # Increment the trial counter

                print(f"Trial [{counter}] : {word}")  # Display current attempt

                if word == original_password:  # Check if guess matches the password
                    print(f"\nPassword is {word}")
                    print(f"Found after {counter} Trial(s)")
                    return True  # Return true when password is found

    return False  # Return false if the password is not found

if __name__ == "__main__":
    guess_password(read_password())  # Read password and attempt to guess it



