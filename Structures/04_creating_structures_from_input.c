/*
    ================================================================================
    Tutorial: Structures - Structs and Functions (Pass-by-Value vs. Pass-by-Pointer)
    ================================================================================

    This program demonstrates the two primary ways to work with `struct`s and
    functions. It highlights when to pass the whole `struct` and when to pass a
    pointer to it.

    1.  **Pass-by-Value (`printPoint`)**:
        - A *copy* of the entire `struct` is made and given to the function.
        - The function can read the data, but any changes it makes are to the
          copy and will NOT affect the original `struct` in `main`.
        - This is simple and safe for read-only operations, but can be inefficient
          if the `struct` is very large, as copying takes time and memory.
        - We use the **dot operator (`.`)** to access members.

    2.  **Pass-by-Pointer (`readPoint`)**:
        - Only the *memory address* of the `struct` is passed to the function.
        - This is very efficient as no data is copied.
        - The function can now modify the original `struct`'s data directly. This
          is essential for functions that need to write or change data, like `readPoint`.
        - We use the **arrow operator (`->`)** as a convenient shortcut to
          dereference the pointer and access a member.

    Concepts Covered:
    - Passing a `struct` to a function by value.
    - Passing a pointer to a `struct` to a function.
    - The dot operator (`.`) for direct access.
    - The arrow operator (`->`) for access via a pointer.
*/

#include <stdio.h>

struct point {
    int x;
    int y;
};

// Function prototypes
void printPoint(struct point pt);
void readPoint(struct point *ptr);

int main(void) {
    struct point z;

    // We pass the ADDRESS of `z` to readPoint so it can be filled with data.
    readPoint(&z);

    printf("\nBack in main, the point is: ");
    // We pass `z` itself (a copy) to printPoint, since it only needs to read the data.
    printPoint(z);

    return 0;
}

/*
    Function: readPoint
    Purpose: Reads x and y coordinates from the user into a `point` struct.
    Method: Pass-by-Pointer.
*/
void readPoint(struct point *ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");

    // The Arrow Operator (`->`):
    // This is a shortcut. The expression `ptr->x` is exactly equivalent to
    // `(*ptr).x`, which means:
    // 1. Dereference the pointer `ptr` to get the whole `struct`.
    // 2. Use the dot operator on that `struct` to access the `x` member.
    // The arrow operator is much cleaner and easier to read.
    scanf("%d", &ptr->x);

    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

/*
    Function: printPoint
    Purpose: Prints the coordinates of a `point` struct.
    Method: Pass-by-Value.
*/
void printPoint(struct point pt) {
    // Here, `pt` is a copy of the `z` variable from main.
    // Since we have the struct directly, we use the dot operator.
    printf("(%d, %d)\n", pt.x, pt.y);
}
