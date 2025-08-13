/*
    ================================================================================
    Tutorial: Functions - Pass-by-Value vs. Pass-by-Reference
    ================================================================================

    This program demonstrates a critical concept: how to make a function modify
    a variable that belongs to another function (in this case, `main`).

    In C, arguments are "passed by value". This means when you pass a variable
    like `a` to a function, the function gets a *copy* of its value. Any changes
    to that copy inside the function do not affect the original variable in `main`.

    To get around this, we use "pass-by-reference". We don't pass the variable's
    value; instead, we pass its *memory address* using a pointer. The function
    can then use this address to find and modify the original variable.

    Concepts Covered:
    - Pointers as function arguments.
    - The "address-of" operator (&) to get a variable's address.
    - The "dereference" operator (*) to access the value at an address.
    - How pointers enable a function to "return" a value through its arguments.
*/

#include <stdio.h>

// Function Prototype:
// Notice the third argument: `int *`. This declares the argument as a
// pointer to an integer. It's a variable that will hold the memory address
// of another integer variable.
void add(int a, int b, int *sum_pointer);

int main(void) {
    int num1, num2, sum;

    printf("Please enter two integers: ");
    scanf("%d%d", &num1, &num2);

    // Calling the function:
    // We pass num1 and num2 by value (the function gets copies of them).
    // For the third argument, we use the address-of operator (&) to pass the
    // *memory address* of our 'sum' variable. We are not passing the value of
    // sum (which is garbage at this point), but its location in memory.
    add(num1, num2, &sum);

    // Because the 'add' function had the address of 'sum', it was able to
    // modify it directly. When we print 'sum' here, it will have the new
    // value calculated by the function.
    printf("Back in main: %d + %d = %d\n", num1, num2, sum);

    return 0;
}

/*
    Function: add
    Purpose: Calculates the sum of two integers and stores the result in a
             variable provided by the caller via a pointer.
    Parameters:
        - a: The first integer (passed by value).
        - b: The second integer (passed by value).
        - sum_pointer: A pointer holding the memory address of the integer
                       variable where the result should be stored.
*/
void add(int a, int b, int *sum_pointer) {
    int result = a + b;

    printf("Inside add(): The calculated sum is %d.\n", result);

    // Modifying the variable in main():
    // We use the dereference operator (*) on the pointer.
    // `*sum_pointer` means "the value at the address that sum_pointer holds".
    // By assigning to `*sum_pointer`, we are not changing the pointer itself,
    // but rather the value in the memory location it points to. This directly
    // changes the 'sum' variable back in the main() function.
    *sum_pointer = result;

    printf("Inside add(): Updated the value in main() via the pointer.\n");
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What would happen if you changed the `add` function to accept `int sum`
        instead of `int *sum_pointer` and tried to do `sum = result;`? Try it!
        You'll find that the 'sum' variable in main() is never updated, because
        the function only received a copy of its initial (garbage) value.
    2.  Write a function `void getMinMax(int x, int y, int *min, int *max)` that
        takes two integers and "returns" both the minimum and the maximum value
        through pointers. This is a classic example of why pass-by-reference is
        so useful, as a C function can only have one direct return value.
    ================================================================================
*/
