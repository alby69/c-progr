/*
    ================================================================================
    Tutorial: Pointers - Pointer Arithmetic
    ================================================================================

    Pointer arithmetic is a powerful feature that allows you to move a pointer
    forwards or backwards in memory. This is especially useful for navigating
    arrays.

    When you add an integer `n` to a pointer, you are not adding `n` bytes to
    the address. Instead, you are moving the pointer forward by `n` *elements*
    of the type it points to. The compiler automatically knows the size of the
    data type (e.g., 4 bytes for an `int`) and does the correct calculation.

    `pointer + n` is equivalent to `address_of_pointer + n * sizeof(type)`

    Concepts Covered:
    - The equivalence of array names and pointers to the first element.
    - Using `*(ptr + n)` to access the nth element.
    - Incrementing a pointer (`ptr++`) to move to the next element.
    - Modifying a pointer by a larger value (`ptr += 3`).
*/

#include <stdio.h>

void printArray(int arr[], int size);

int main(void) {
    int array[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int *ptr = array; // ptr now points to the first element (array[0]).

    printf("Original array: ");
    printArray(array, size);
    printf("Pointer 'ptr' currently points to address %p, which holds the value %d.\n\n", ptr, *ptr);

    // --- Accessing elements using pointer arithmetic ---
    // `*(ptr + 2)` accesses the element at index 2 (value 30).
    printf("Accessing element at index 2 using *(ptr + 2): %d\n", *(ptr + 2));

    // --- Modifying elements using pointer arithmetic ---
    printf("Modifying element at index 2 to be 33...\n");
    *(ptr + 2) = 33;
    printf("Array after modification: ");
    printArray(array, size);
    printf("\n");

    // --- Moving the pointer itself ---
    // `ptr++` moves the pointer to the next element in the array.
    printf("Moving pointer with ptr++...\n");
    ptr++; // ptr now points to the second element (array[1]).
    printf("Pointer 'ptr' now points to address %p, which holds the value %d.\n", ptr, *ptr);
    printf("Modifying this element to be 22...\n");
    *ptr = 22; // This changes array[1].
    printf("Array after modification: ");
    printArray(array, size);
    printf("\n");

    // We can also move the pointer by more than one step.
    printf("Moving pointer with ptr += 3...\n");
    ptr += 3; // ptr was at index 1, now it moves to index 1 + 3 = 4.
    printf("Pointer 'ptr' now points to address %p, which holds the value %d.\n", ptr, *ptr);
    printf("Modifying this element to be 55...\n");
    *ptr = 55; // This changes array[4].
    printf("Array after modification: ");
    printArray(array, size);
    printf("\n");

    return 0;
}

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
    1.  What happens if you try to dereference a pointer that has moved past the
        end of the array (e.g., after `ptr += 3;`, add another `ptr++` and then
        try to print `*ptr`)? This is a dangerous operation that reads from
        memory you don't own, leading to undefined behavior.
    2.  You can also use the subtraction operator. If `ptr` points to `array[4]`,
        what do you think `*(ptr - 2)` would give you?
    ================================================================================
*/
