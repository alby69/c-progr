/*
    ================================================================================
    Tutorial: Arrays - Reversing an Array
    ================================================================================

    This program demonstrates a classic and efficient algorithm for reversing
    an array "in-place" (meaning, without creating a second, temporary array).

    The core idea is to swap the first element with the last, the second element
    with the second-to-last, and so on, stopping at the middle of the array.

    Concepts Covered:
    - In-place modification of an array.
    - The "two-pointer" or "symmetric swap" algorithm for reversal.
    - Using a temporary variable for swapping values.
*/

#include <stdio.h>

// Function Prototypes
void readArray(int arr[], int size);
void reverseArray(int arr[], int size);
void printArray(int arr[], int size);

int main(void) {
    const int SIZE = 6; // Using a constant for the size is good practice.
    int array[SIZE];

    printf("Please enter %d integers:\n", SIZE);
    readArray(array, SIZE);

    printf("\nOriginal array: ");
    printArray(array, SIZE);

    reverseArray(array, SIZE);

    printf("Reversed array: ");
    printArray(array, SIZE);

    return 0;
}

/*
    Function: reverseArray
    Purpose: Reverses the elements of an array in-place.
*/
void reverseArray(int arr[], int size) {
    int temp; // A temporary variable is essential for swapping.

    // The loop only needs to go to the middle of the array.
    // If size is 6, we loop from i=0 to 2.
    // i=0 swaps with 5.
    // i=1 swaps with 4.
    // i=2 swaps with 3.
    // If we went all the way to size-1, we would just swap them back!
    for (int i = 0; i < size / 2; i++) {
        // The index of the element symmetric to `i` is `size - 1 - i`.
        int symmetric_index = size - 1 - i;

        // The three steps for a classic swap:
        // 1. Store the value of the first element in a temporary variable.
        temp = arr[i];
        // 2. Overwrite the first element with the value of the second.
        arr[i] = arr[symmetric_index];
        // 3. Overwrite the second element with the value from the temp variable.
        arr[symmetric_index] = temp;
    }
}

/*
    Function: printArray
    Purpose: Prints all elements of an integer array.
*/
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
    Function: readArray
    Purpose: Reads integers from the user to populate an array.
*/
void readArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What happens if the array has an odd number of elements (e.g., size 7)?
        Trace the loop with `size / 2`. Integer division means `7 / 2` is 3. The
        loop will run for i=0, 1, 2. The middle element (at index 3) is never
        touched, which is correct! It doesn't need to be swapped with anything.
    2.  Can you write a function `void swap(int *a, int *b)` that takes pointers
        to two integers and swaps their values? Then, you could call this
        `swap(&arr[i], &arr[symmetric_index])` inside your `reverseArray`
        function to make the code even cleaner. This is an excellent pointer exercise.
    ================================================================================
*/
