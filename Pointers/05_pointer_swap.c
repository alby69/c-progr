/*
    ================================================================================
    Tutorial: Pointers - The Classic Swap Function
    ================================================================================

    This program demonstrates one of the most essential and classic uses for
    pointers: a function that swaps the values of two variables.

    If you were to write a `swap` function that took regular integers (`int a, int b`)
    instead of pointers, it would fail. The function would only receive *copies*
    of the original values, and swapping those copies would have no effect on the
    original variables in `main`.

    To make the swap permanent, the function needs to know the *memory addresses*
    of the original variables, which requires pointers.

    Concepts Covered:
    - A canonical use case for pointers.
    - The logic of swapping two values using a temporary variable.
    - Passing the addresses of two different variables to a single function.
*/

#include <stdio.h>

// Function prototype for our swap function.
// It takes two "pointers to int" as arguments.
void swap(int *ptr_a, int *ptr_b);

int main() {
    int a = 9;
    int b = 1;

    printf("Before swap: a = %d, b = %d\n", a, b);

    // We call the swap function, passing the memory addresses of 'a' and 'b'.
    swap(&a, &b);

    printf("After swap:  a = %d, b = %d\n", a, b);

    return 0;
}

/*
    Function: swap
    Purpose: Swaps the integer values stored at two different memory addresses.
    Parameters:
        - ptr_a: A pointer to the first integer variable.
        - ptr_b: A pointer to the second integer variable.
*/
void swap(int *ptr_a, int *ptr_b) {
    int temp; // A temporary variable is essential for a swap.

    // 1. Store the value from the first address (`*ptr_a`) in `temp`.
    temp = *ptr_a;

    // 2. Copy the value from the second address (`*ptr_b`) into the first address.
    *ptr_a = *ptr_b;

    // 3. Copy the value we originally stored in `temp` into the second address.
    *ptr_b = temp;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  As a challenge, try to write the incorrect version of swap:
        `void failedSwap(int a, int b)`. Put the swap logic inside and call it
        from main. You will see that it does not work, which is the best way to
        understand why pointers are needed here.
    2.  We used this swap logic in the `04_Arrays/06_reversing_an_array.c`
        example. Can you go back to that file and modify it to use this new,
        reusable `swap()` function?
    ================================================================================
*/
