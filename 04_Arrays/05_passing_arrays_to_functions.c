/*
    ================================================================================
    Tutorial: Arrays - Passing Arrays to Functions
    ================================================================================

    This is a very important topic. When you pass an array to a function in C,
    you are not passing a copy of the entire array. Instead, you are passing a
    *pointer* to the first element of the array.

    This has a huge implication: any modifications the function makes to the
    array elements will affect the original array in the calling function!
    This is different from passing a simple variable (like an int), where the
    function only gets a copy.

    This file merges concepts from three different examples to provide a
    comprehensive overview.

    Concepts Covered:
    - How arrays are passed to functions as pointers.
    - How functions can modify the original array's data.
    - The equivalence of pointer notation (`*(ptr + i)`) and array notation (`ptr[i]`).
    - The need to pass the array's size as a separate argument.
*/

#include <stdio.h>

// Function Prototypes
// When a function expects an array, you can declare the parameter as a pointer
// (e.g., `int *ptr`) or with empty array brackets (e.g., `int arr[]`). Both are
// treated identically by the compiler: they are both pointers.
void printArray(int arr[], int size);
void squareArray(int arr[], int size);
void resetArray(int *ptr, int size); // Showing the pointer syntax is the same

int main(void) {
    // We can initialize an array with values when we declare it.
    // The compiler will automatically determine the size.
    int array[] = {6, 2, -4, 8, 5, 1};
    int size = 6;

    printf("Original array: ");
    printArray(array, size);

    // This function will modify the original array.
    squareArray(array, size);
    printf("After squaring: ");
    printArray(array, size);

    // This function also modifies the original array.
    resetArray(array, size);
    printf("After resetting:  ");
    printArray(array, size);

    return 0;
}

/*
    Function: squareArray
    Purpose: Squares each element of an integer array.
*/
void squareArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // This modification directly changes the 'array' in main().
        arr[i] = arr[i] * arr[i];
    }
}

/*
    Function: resetArray
    Purpose: Resets the first 3 elements of an array to 0.
    This demonstrates using pointer notation to achieve the same result.
*/
void resetArray(int *ptr, int size) {
    // In C, `ptr[i]` is just "syntactic sugar" for `*(ptr + i)`.
    // The following lines show the equivalence. Most programmers use the
    // array notation `ptr[i]` because it's easier to read.
    if (size >= 1) {
        *(ptr + 0) = 0; // Same as ptr[0] = 0
    }
    if (size >= 2) {
        *(ptr + 1) = 0; // Same as ptr[1] = 0
    }
    if (size >= 3) {
        ptr[2] = 0;     // Same as *(ptr + 2) = 0
    }
}


/*
    Function: printArray
    Purpose: Prints all elements of an integer array.
    Note: A function that receives an array has no way of knowing its size on
    its own. This is why we MUST pass the size as a separate argument.
*/
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  One of the original examples had a function that found the maximum value
        in an array and another function that used that result to modify the array.
        Can you write a function `int findMax(int arr[], int size)` that returns
        the largest value, and then call it from `main`?
    2.  What happens if you declare a function parameter with `const`, like
        `void printArray(const int arr[], int size)`? This is a promise to the
        compiler that the function will *not* modify the array. If you then try
        to write `arr[i] = 0;` inside that function, the compiler will give you
        an error. This is a very good practice for functions that should only
        read from an array, not write to it.
    ================================================================================
*/
