/*
    ================================================================================
    Tutorial: Pointers - The Absolute Basics
    ================================================================================

    Welcome to Pointers! This is one of the most powerful and defining features
    of the C language. It can seem intimidating, but let's break it down.

    A pointer is simply a variable that holds a memory address as its value.
    Instead of storing a number like `42` or a character like 'r', it stores
    the location where another variable lives in the computer's memory.

    This first example shows how to declare a pointer and how to get the
    memory address of a regular variable.

    Concepts Covered:
    - Declaring a pointer variable (e.g., `int *my_pointer;`).
    - The "address-of" operator (&) to get a variable's memory location.
    - The '%p' format specifier for printing memory addresses.
*/

#include <stdio.h>

int main() {
    // There are two `#include <stdio.h>` lines in the original file.
    // While harmless, it's redundant. We only need one.

    // Declare some regular variables of different types.
    int a = 42;
    double d = 58.394;
    char c = 'r';

    // --- Declaring and Assigning Pointers ---

    // This declares a variable named 'addressOfA' that is a "pointer to an int".
    // The asterisk (*) indicates that it's a pointer.
    // We then use the address-of operator (&) to get the memory address of 'a'
    // and we assign that address as the value of our pointer.
    int *addressOfA = &a;

    // We do the same for the other data types.
    double *addressOfD = &d;
    char *addressOfC = &c;


    // --- Printing Memory Addresses ---

    // The `%p` format specifier is used with `printf` to print memory addresses
    // in a standard hexadecimal format.
    printf("The value of 'a' is %d, and it is stored at memory address: %p\n", a, addressOfA);
    printf("The value of 'd' is %lf, and it is stored at memory address: %p\n", d, addressOfD);
    printf("The value of 'c' is '%c', and it is stored at memory address: %p\n", c, addressOfC);

    // You can also print the address directly without using a pointer variable:
    printf("\nWe can also print the address of 'a' directly: %p\n", &a);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What is the value *of the pointer variable itself*? It's a memory address.
        What is the *address of the pointer variable*? A pointer is a variable,
        so it has its own memory address too! You can find it with `&addressOfA`.
        Try printing it out!
    2.  What is the size of a pointer? Try `printf("%zu", sizeof(addressOfA));`.
        Do this for `addressOfD` and `addressOfC` as well. You will likely find
        that all pointers have the same size on your system (typically 4 or 8
        bytes), because they all just store a memory address, regardless of the
        type of data they point to.
    ================================================================================
*/
