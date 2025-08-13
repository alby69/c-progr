/*
    ================================================================================
    Tutorial: Pointers - Pointers to Pointers (Double Pointers)
    ================================================================================

    This is an advanced topic, so let's take it slow.
    - A normal pointer (like `int *`) stores the address of a variable.
    - A pointer-to-a-pointer (like `int **`) stores the address of *another pointer*.

    Why would you need this?
    1.  To create an array of pointers (as shown in this example). This is very
        common for storing an array of strings.
    2.  For a function that needs to change where a pointer points (i.e., change
        the address stored in the pointer variable itself).

    This example creates an "array of pointers", where each element of the array
    is a pointer to another array.

    Concepts Covered:
    - Declaring a pointer-to-a-pointer (`type **`).
    - Creating an array of pointers.
    - The logic of double dereferencing.
*/

#include <stdio.h>

// This function takes a pointer-to-a-pointer-to-a-short.
// `t` is an address of a pointer.
void setToZero(short **t);
void printArrays(short **t);

int main() {
    short a[] = {1245, 1924, 234};
    short b[] = {24, 256};

    // `t` is an array of pointers. Each element in `t` is a `short *`.
    // t[0] is a pointer that holds the address of the first element of `a`.
    // t[1] is a pointer that holds the address of the first element of `b`.
    short *t[2] = {a, b};

    printf("--- Before ---\n");
    printArrays(t);

    // When we pass `t` to a function, the array name `t` decays into a pointer
    // to its first element. The first element of `t` is a `short *`.
    // Therefore, a pointer to that element is a `short **`.
    setToZero(t);

    printf("\n--- After ---\n");
    printArrays(t);

    return 0;
}

/*
    Function: setToZero
    Purpose: Sets the elements of the arrays pointed to by the pointer array to zero.
    Parameters:
        - t: A pointer to the first element of the array of pointers from main.
*/
void setToZero(short **t) {
    // Let's break down the complex syntax: `*(*t) = 0;`
    //
    // 1. `t`: A pointer to a `short *`. Its value is the address of `t[0]` from main.
    // 2. `*t`: We dereference `t` once. This gives us the value *at* `t[0]`, which
    //          is the pointer to array `a`. So, `*t` is the same as `a`.
    // 3. `*(*t)`: We dereference the result again. Since `*t` is `a`, `*(*t)` is the
    //            same as `*a`, which refers to the first element of `a`.
    // So, `*(*t) = 0;` is equivalent to `a[0] = 0;`.

    *(*t) = 0; // Sets a[0] to 0.

    // Let's look at `*((*t) + 1) = 0;`
    // 1. `*t` is `a`.
    // 2. `(*t) + 1` is pointer arithmetic, same as `a + 1`, which points to a[1].
    // 3. `*((*t) + 1)` dereferences that, so it's the same as `a[1]`.
    *((*t) + 1) = 0; // Sets a[1] to 0.
    *((*t) + 2) = 0; // Sets a[2] to 0.

    // Now let's look at `*(*(t + 1)) = 0;`
    // 1. `t + 1`: Pointer arithmetic. Moves from pointing at `t[0]` to pointing at `t[1]`.
    // 2. `*(t + 1)`: Dereferences that. This gives us the value *at* `t[1]`, which is the pointer `b`.
    // 3. `*(*(t + 1))`: Dereferences `b`, giving us `b[0]`.
    *(*(t + 1)) = 0;     // Sets b[0] to 0.
    *(*(t + 1) + 1) = 0; // Sets b[1] to 0.
}

// A helper function to see the results.
void printArrays(short **t) {
    // This is just for demonstration; in a real program, we would also need
    // to pass the size of each individual array to do this safely in a loop.
    printf("Content of array 'a': %d, %d, %d\n", t[0][0], t[0][1], t[0][2]);
    printf("Content of array 'b': %d, %d\n", t[1][0], t[1][1]);
}
