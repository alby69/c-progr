/*
    ================================================================================
    Tutorial: Structures - Dynamic Allocation of Structs
    ================================================================================

    This program is a capstone example that brings together many of the topics
    we've covered: structs, pointers, arrays, and dynamic memory allocation.

    It creates a dynamically-sized array of `point` structs. This is the proper,
    safe, and standard way to handle cases where you don't know the size of your
    array until runtime, and it's the preferred alternative to Variable-Length
    Arrays (VLAs).

    The process is:
    1.  Ask the user how many vertices they need.
    2.  Use `malloc` to request enough memory for that many `point` structs.
    3.  Treat the resulting block of memory as an array.
    4.  `free` the memory when we are done.

    Concepts Covered:
    - Using `malloc` to create a dynamic array of structs.
    - Using `sizeof(struct type)` to calculate the correct memory size.
    - Accessing elements in the dynamically allocated array.
    - The importance of `free`ing the allocated memory.
*/

#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

struct point {
    int x;
    int y;
};

void printPoint(struct point pt);
void readPoint(struct point *ptr);
void printPolygon(struct point *polygon, int num_vertices);

int main(void) {
    // `polygon` is not an array. It's a pointer that will hold the
    // starting address of a block of memory we get from malloc.
    struct point *polygon;
    int num_vertices;

    printf("How many vertices does your polygon have? ");
    scanf("%d", &num_vertices);

    // Dynamic Allocation:
    // 1. We want space for `num_vertices` number of `point` structs.
    // 2. `sizeof(struct point)` gives us the size of a single struct.
    // 3. We multiply them to get the total number of bytes needed.
    // 4. `malloc` returns a `void *`, which we cast to `struct point *`.
    polygon = (struct point *) malloc(num_vertices * sizeof(struct point));

    // ALWAYS check if malloc was successful.
    if (polygon == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Now, we can treat `polygon` as if it were an array.
    // We can use the familiar `[]` array notation to access elements.
    for (int i = 0; i < num_vertices; i++) {
        printf("Enter vertex #%d:\n", i + 1);
        readPoint(&polygon[i]); // Pass the address of the i-th struct
    }

    printPolygon(polygon, num_vertices);

    // THE GOLDEN RULE: If you `malloc`, you must `free`.
    // This releases the entire block of memory back to the system.
    free(polygon);
    polygon = NULL; // Good practice to prevent using a "dangling pointer".

    return 0;
}

void readPoint(struct point *ptr) {
    printf("  x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("  y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printPolygon(struct point *polygon, int num_vertices) {
    printf("\nYour polygon's vertices are:\n");
    for (int i = 0; i < num_vertices; i++) {
        printPoint(polygon[i]);
    }
}

void printPoint(struct point pt) {
    printf("  (%d, %d)\n", pt.x, pt.y);
}
