/*
    ================================================================================
    Tutorial: Arrays - Storing and Accessing Data
    ================================================================================

    This program introduces the concept of an array. An array is a collection
    of elements of the same data type, stored in contiguous memory locations.
    This allows you to manage a list of items using a single variable name.

    This example creates an array to store recipe ingredient amounts, reads
    values into it, and then retrieves a specific ingredient amount based on
    a user-provided ID (index).

    Concepts Covered:
    - Declaring an array with a fixed size.
    - Accessing array elements using an index (e.g., `my_array[0]`).
    - The concept of zero-based indexing.
    - Using a 'for' loop to iterate over an array.
*/

#include <stdio.h>

int main(void) {
    // Array Declaration:
    // This declares an array named 'ingredients' that can hold 10 integers.
    // The elements are accessed with an index from 0 to 9.
    int ingredients[10];
    int read_id = 0; // The index of the ingredient to read back.

    printf("Please enter 10 integer ingredient amounts:\n");

    // Populating the array using a loop:
    // We loop from i = 0 to 9 to read a value for each of the 10 array slots.
    for (int i = 0; i < 10; i++) {
        printf("Enter amount for ingredient #%d: ", i);
        // We read the value into the element at the current index 'i'.
        scanf("%d", &ingredients[i]);
    }

    printf("\nAll ingredients entered.\n");
    printf("Which ingredient ID (0-9) would you like to retrieve? ");
    scanf("%d", &read_id);

    // Accessing an array element:
    // We use the user-provided 'read_id' as the index to retrieve and print
    // a specific value from the array.
    // IMPORTANT: C does not check if the index is valid. If the user enters 15,
    // the program will try to access memory outside the array's bounds, which
    // leads to "undefined behavior" (it might crash, or it might print garbage).
    if (read_id >= 0 && read_id < 10) {
        printf("The amount for ingredient ID %d is %d.\n", read_id, ingredients[read_id]);
    } else {
        printf("Error: Invalid ID. Please enter a value between 0 and 9.\n");
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Modify the program to calculate and print the sum of all the ingredient
        amounts after they have been entered. You'll need another 'for' loop.
    2.  Instead of hard-coding the size of the array to 10, use a constant
        (e.g., `#define RECIPE_SIZE 10`). This makes it much easier to change
        the number of ingredients later, as you only have to modify one line.
    ================================================================================
*/
