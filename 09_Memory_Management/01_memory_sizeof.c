/*
    ================================================================================
    Tutorial: Memory Management - The `sizeof` Operator
    ================================================================================

    This program introduces the `sizeof` operator, a fundamental tool for
    understanding and managing memory in C.

    `sizeof` is a compile-time operator that returns the size, in bytes, of a
    variable or a data type. A "byte" is the standard unit of data storage in
    a computer (typically 8 bits).

    The exact size of data types (like `int`, `double`, etc.) can vary between
    different computer architectures (e.g., 32-bit vs. 64-bit systems). `sizeof`
    allows you to write portable code that doesn't rely on hard-coded "magic numbers"
    for type sizes.

    This program calculates the total memory required for a list of items of
    different data types and then formats the result in a human-readable way
    (Bytes, Kilobytes, and Megabytes).

    Concepts Covered:
    - The `sizeof` operator.
    - The size in bytes of common data types.
    - Memory usage calculation.
    - Integer arithmetic for formatting byte counts into KB/MB.
*/

#include <stdio.h>

int main(void) {
    int num_item_types = 0;
    int quantity = 0;
    char type_code; // 'i' for int, 'd' for double, 'c' for char
    long long total_bytes = 0; // Use long long to handle potentially large sizes.

    printf("How many different item types are there? ");
    scanf("%d", &num_item_types);

    printf("For each type, enter the quantity and the type code (i, d, or c).\n");

    for (int i = 0; i < num_item_types; i++) {
        printf("Enter quantity and type for item #%d: ", i + 1);
        scanf("%d %c", &quantity, &type_code);

        if (type_code == 'i') {
            total_bytes += sizeof(int) * quantity;
        } else if (type_code == 'd') {
            total_bytes += sizeof(double) * quantity;
        } else if (type_code == 'c') {
            total_bytes += sizeof(char) * quantity;
        } else {
            printf("Invalid tracking code type '%c'.\n", type_code);
        }
    }

    printf("\n--- Total Memory Required ---\n");
    printf("Raw bytes: %lld\n", total_bytes);

    // Format the byte count into a more human-readable format.
    // 1 KB = 1000 Bytes, 1 MB = 1000 KB = 1,000,000 Bytes
    if (total_bytes >= 1000000) {
        int megabytes = total_bytes / 1000000;
        int kilobytes = (total_bytes % 1000000) / 1000;
        int bytes = total_bytes % 1000;
        printf("Formatted: %d MB, %d KB, and %d B\n", megabytes, kilobytes, bytes);
    } else if (total_bytes >= 1000) {
        int kilobytes = total_bytes / 1000;
        int bytes = total_bytes % 1000;
        printf("Formatted: %d KB and %d B\n", kilobytes, bytes);
    } else {
        printf("Formatted: %lld B\n", total_bytes);
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  On your system, what are the sizes of `short`, `long`, `float`, and
        `long long`? Write a simple program to print the `sizeof` each one.
    2.  What is the size of a pointer, like `int *`? You'll find it's likely
        4 or 8, depending on whether you're on a 32-bit or 64-bit system.
    ================================================================================
*/
