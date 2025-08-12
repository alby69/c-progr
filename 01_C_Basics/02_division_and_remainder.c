/*
    ================================================================================
    Tutorial: C Basics - Integer Division and the Modulo Operator
    ================================================================================

    This exercise demonstrates how integer arithmetic works in C, specifically
    division and finding the remainder.

    Concepts Covered:
    - Integer division: how C handles division between two integers.
    - The Modulo Operator (%): how to get the remainder of a division.
    - Variable initialization.
*/

#include <stdio.h>

int main(void) {
    // Variable Declaration and Initialization:
    // We declare two integer variables to store the total number of matches
    // and the capacity (size) of each box.
    // It's good practice to initialize variables to 0 to avoid using them
    // with garbage values from memory.
    int total_matches = 0;
    int box_size = 0;

    printf("Enter the total number of matches: ");
    scanf("%d", &total_matches);

    printf("Enter the number of matches each box can hold: ");
    scanf("%d", &box_size);

    // Integer Division:
    // When you divide two integers in C, the result is also an integer.
    // Any fractional part is truncated (simply cut off, not rounded).
    // For example, 10 / 3 results in 3.
    int full_boxes = total_matches / box_size;
    printf("Number of full boxes: %d\n", full_boxes);

    // The Modulo Operator (%):
    // This operator gives you the remainder of an integer division.
    // For example, 10 % 3 results in 1, because 10 divided by 3 is 3 with
    // a remainder of 1.
    int remaining_matches = total_matches % box_size;
    printf("Number of remaining matches: %d\n", remaining_matches);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What happens if the user enters 0 for the box size? Your program will
        likely crash due to a "division by zero" error. This is a very common
        bug to watch out for!
    2.  Can you add an 'if' statement to check if 'box_size' is 0 before you
        perform the division? If it is, print an error message to the user.
    3.  Think about a real-world scenario where the modulo operator would be
        useful. For example, determining if a number is even or odd. (Hint:
        An even number has a remainder of 0 when divided by 2).
    ================================================================================
*/
