/*
    ================================================================================
    Tutorial: Structures - Structs and Memory Layout (Padding)
    ================================================================================

    This program uses the `sizeof` operator to inspect the amount of memory
    used by a `struct` and its individual members.

    This often reveals a surprising and important concept in C: **structure padding**.

    You might expect the total size of the `struct` to be the exact sum of the
    sizes of its members. However, it is often larger. The compiler adds invisible,
    unused bytes ("padding") between members to ensure that each member is
    aligned on a memory address that is a multiple of its size. This is done
    for performance reasons, as accessing aligned data is much faster on most
    computer architectures.

    Concepts Covered:
    - Using `sizeof` on a `struct` type and its members.
    - Structure padding and memory alignment.
    - The `%zu` format specifier for printing `size_t` types (the type returned by `sizeof`).
*/

#include <stdio.h>

// We use smaller array sizes here to make the padding more obvious.
struct student {
    char firstName[5]; // 5 bytes
    char lastName[5];  // 5 bytes
    int birthYear;     // Usually 4 bytes
    double aveGrade;   // Usually 8 bytes
};

int main(void) {
    struct student me;

    // The `%zu` format specifier is the correct, portable way to print a value
    // of type `size_t`, which is what `sizeof` returns.
    printf("Size of firstName is %zu bytes.\n", sizeof(me.firstName));
    printf("Size of lastName is %zu bytes.\n", sizeof(me.lastName));
    printf("Size of birthYear is %zu bytes.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %zu bytes.\n", sizeof(me.aveGrade));

    size_t sum_of_members = sizeof(me.firstName) + sizeof(me.lastName) +
                              sizeof(me.birthYear) + sizeof(me.aveGrade);

    printf("\nSum of the sizes of individual members: %zu bytes.\n", sum_of_members);

    // Now, let's see the size of the entire structure.
    // It will likely be larger than the sum of its parts!
    printf("Total size of the 'struct student' is %zu bytes.\n", sizeof(struct student));

    printf("\nThe difference is due to memory padding added by the compiler for alignment.\n");

    return 0;
}

/*
    Why the padding?
    Imagine memory as a series of numbered boxes. A `double` (8 bytes) is most
    efficiently accessed if it starts at a memory address divisible by 8.
    - firstName[5] takes 5 bytes.
    - lastName[5] takes another 5 bytes. Total = 10 bytes.
    - The next member, `birthYear` (an int), needs to be aligned. Let's say it
      starts at address 12 (the compiler adds 2 bytes of padding). It takes 4 bytes. Total = 16.
    - The next member, `aveGrade` (a double), needs to be aligned to an address
      divisible by 8. The current address is 16, which is divisible by 8, so no
      padding is needed here. It takes 8 bytes. Total = 24.
    - The compiler might even add padding at the *end* of the struct to ensure
      that in an array of these structs, each one starts on a properly aligned
      boundary. So the final size might be 24 or even 32.

    The exact rules for padding are compiler-dependent, but the principle is the same.
*/
