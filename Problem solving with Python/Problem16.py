"""
Problem16 |===============================================

Write a program to print all words from AAA to ZZZ 

Output : 
AAA
AAB
AAC
.
.
==========================================================
"""
def print_all_words_from_AAA_to_ZZZ():
    """
    Prints all possible three-letter words from 'AAA' to 'ZZZ'.
    """
    for i in range(ord('A'), ord('Z') + 1):  # Loop from 'A' to 'Z' for the first letter
        for j in range(ord('A'), ord('Z') + 1):  # Loop for the second letter
            for k in range(ord('A'), ord('Z') + 1):  # Loop for the third letter
                print(f"{chr(i)}{chr(j)}{chr(k)}")  # Print the three-letter combination

# Main function execution
if __name__ == "__main__":
    print_all_words_from_AAA_to_ZZZ()

