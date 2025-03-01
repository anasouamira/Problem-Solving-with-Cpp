""""
Problem01 |===================================================

Write a program to print the multiplication table From 1 to 10
order. 

Output :
                        Multipliaction Table From 1 to 10

        1       2       3       4       5       6       7       8       9       10
___________________________________________________________________________________
 1   |  1       2       3       4       5       6       7       8       9       10
 2   |  2       4       6       8       10      12      14      16      18      20
 3   |  3       6       9       12      15      18      21      24      27      30
 4   |  4       8       12      16      20      24      28      32      36      40
 5   |  5       10      15      20      25      30      35      40      45      50
 6   |  6       12      18      24      30      36      42      48      54      60
 7   |  7       14      21      28      35      42      49      56      63      70
 8   |  8       16      24      32      40      48      56      64      72      80
 9   |  9       18      27      36      45      54      63      72      81      90
 10  |  10      20      30      40      50      60      70      80      90      100


==============================================================
"""

def print_table_header():
    """
    Function to print the header of the multiplication table.
    It includes column labels from 1 to 10 and a separator line.
    """
    print("\n\n\t\t\tMultiplication Table From 1 to 10\n")
    print("\t", end="")

    for i in range(1, 11):
        print(f"{i:4}", end="")  # Ensuring equal spacing

    print("\n" + "-" * 50)  # Separator line


def print_multiplication_table():
    """
    Function to print the full multiplication table from 1 to 10.
    It calls print_table_header() first, then prints each row of the table.
    """
    print_table_header()

    for i in range(1, 11):
        print(f"{i:2} |", end="")  # Align row numbers

        for j in range(1, 11):
            print(f"{i * j:4}", end="")  # Align multiplication values

        print()  # New line for next row

    print("-" * 50)  # Bottom border for table consistency


# Main entry point
if __name__ == "__main__":
    print_multiplication_table()





