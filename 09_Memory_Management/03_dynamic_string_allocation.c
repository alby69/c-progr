/*
    ================================================================================
    Tutorial: Memory Management - Dynamic Memory Allocation
    ================================================================================

    This program introduces one of C's most powerful and advanced features:
    **dynamic memory allocation**.

    So far, the size of all our arrays had to be a fixed constant known when we
    compile the program. Dynamic allocation allows us to request a block of
    memory of a specific size *while the program is running*.

    This is essential when you don't know how much memory you'll need until
    runtime (e.g., the user tells you how many items they want to enter).

    The two key functions are from `<stdlib.h>`:
    - `malloc(size)`: "Memory Allocate". It requests a block of `size` bytes
      from the operating system (from a memory pool called the "heap"). It
      returns a `void *` pointer to the start of that block, or `NULL` if the
      allocation fails.
    - `free(pointer)`: Releases the block of memory pointed to by `pointer`
      back to the system, so it can be used again.

    **THE GOLDEN RULE:** For every call to `malloc()`, there must be exactly
    one call to `free()`. Forgetting to `free` memory causes a "memory leak".

    Concepts Covered:
    - The need for dynamic allocation.
    - The `malloc()` and `free()` functions.
    - Casting the `void *` returned by `malloc()`.
    - The "off-by-one" error with null terminators (a very common bug!).
    - Checking for `malloc` failure.
*/

#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

char *allocateString(int num_chars);

int main(void) {
    int lengthLight, lengthDark;
    char *strLight, *strDark;

    printf("Enter the desired length for the light and dark side strings: ");
    scanf("%d %d", &lengthLight, &lengthDark);

    // Allocate memory for the strings based on user input.
    strLight = allocateString(lengthLight);
    strDark = allocateString(lengthDark);

    // It's crucial to check if malloc succeeded. If the system is out of
    // memory, it will return NULL.
    if (strLight == NULL || strDark == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1; // Exit with an error code.
    }

    printf("Enter the light side setting (max %d chars): ", lengthLight);
    scanf("%s", strLight);
    printf("Enter the dark side setting (max %d chars): ", lengthDark);
    scanf("%s", strDark);

    printf("Local settings: %s - %s\n", strLight, strDark);

    // **CRUCIAL STEP:** Free the memory when you are done with it.
    // If you don't, your program will have a memory leak.
    free(strLight);
    free(strDark);

    return 0;
}

/*
    Function: allocateString
    Purpose: Dynamically allocates enough memory to hold a string of a given
             number of characters.
*/
char *allocateString(int num_chars) {
    // --- A VERY COMMON BUG AND ITS FIX ---
    // The original code was `malloc(numChars * sizeof(char))`.
    // The problem is that a string needs one extra byte for the null terminator ('\0').
    // If you ask for 5 chars, you need 6 bytes of space. `scanf` will write the
    // null terminator at the 6th byte, which is outside the allocated memory.
    // This is a "buffer overflow" and a major security vulnerability.
    //
    // The FIX is to always allocate `num_chars + 1` bytes.
    // `sizeof(char)` is always 1 by definition, so it's optional, but good for clarity.
    char *ptr = (char *) malloc((num_chars + 1) * sizeof(char));

    return ptr;
}
