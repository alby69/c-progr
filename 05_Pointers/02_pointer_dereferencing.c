/*
    ================================================================================
    Tutorial: Pointers - Dereferencing ("Going to the Address")
    ================================================================================

    If a pointer holds a memory address, how do we see what's *at* that address?
    This action is called "dereferencing", and it's done with the same asterisk (*)
    we use to declare a pointer.

    When used on an existing pointer variable, `*my_pointer` means
    "go to the address stored in `my_pointer` and get the value there".

    This is the key to reading and *writing* data through pointers.

    This file merges concepts from four different examples.

    Concepts Covered:
    - The dereference operator (*) to read a value.
    - Using a dereferenced pointer to modify a value.
    - A practical example: passing a pointer to a function to modify a variable.
    - The relationship between pointers and arrays.
*/

#include <stdio.h>

// Function prototype that takes a pointer as an argument.
void timesTwo(int *num_ptr);

int main(void) {
    // --- Part 1: Basic Dereferencing ---

    int i = 42;
    int *i_ptr = &i; // i_ptr now holds the address of i.

    double a = 3.14;
    double *a_ptr = &a;

    // To read the value *at* the address, we dereference the pointer.
    printf("The variable 'i' lives at address %p.\n", i_ptr);
    printf("The value stored at that address is %d.\n\n", *i_ptr); // Dereference!

    printf("The variable 'a' lives at address %p.\n", a_ptr);
    printf("The value stored at that address is %lf.\n\n", *a_ptr);

    // --- Part 2: Modifying Values via Dereferencing ---

    printf("The original value of 'i' is %d.\n", i);
    printf("Now, we will modify 'i' using the pointer...\n");

    // We are not changing the pointer `i_ptr`, but the value at the address it points to.
    *i_ptr = 50;

    // If we now check the original variable 'i', we see it has changed!
    printf("The new value of 'i' is %d.\n\n", i);


    // --- Part 3: Practical Use - Modifying a Value in a Function ---

    int n = 10;
    printf("The value of 'n' before the function call is %d.\n", n);

    // We pass the ADDRESS of 'n' to the function.
    timesTwo(&n);

    // Because the function had the address, it could change 'n' directly.
    printf("The value of 'n' after the function call is %d.\n\n", n);


    // --- Part 4: The Relationship Between Pointers and Arrays ---

    int my_array[] = {100, 200, 300};
    int *array_ptr = my_array; // Notice: no '&' needed for an array!

    // The name of an array, when used by itself, decays into a pointer
    // to its first element. So, `my_array` is equivalent to `&my_array[0]`.

    printf("The first element is %d.\n", *array_ptr); // Prints 100

    // We can use pointer arithmetic to access other elements.
    // `*(array_ptr + 1)` means "go to the address of the first element, move
    // forward by the size of one int, and get the value there".
    printf("The second element is %d.\n", *(array_ptr + 1)); // Prints 200

    // This is why array access `my_array[1]` is equivalent to `*(my_array + 1)`.
    // The array bracket notation is just more convenient "syntactic sugar".

    return 0;
}

/*
    Function: timesTwo
    Purpose: Takes a pointer to an integer, and doubles the value stored at
             that integer's address.
*/
void timesTwo(int *num_ptr) {
    printf(" -> Inside function: The received value is %d.\n", *num_ptr);
    // Here, we dereference the pointer to get the value, multiply it by 2,
    // and then use the pointer again to store the new value back in the
    // original memory location.
    *num_ptr = *num_ptr * 2;
    printf(" -> Inside function: The value has been doubled to %d.\n", *num_ptr);
}
