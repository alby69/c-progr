/*
    ================================================================================
    Tutorial: Structures - Arrays of Structs
    ================================================================================

    Now that we know how to create a `struct`, we can create an array of them!
    This is an extremely common and powerful pattern for managing a collection
    of related data objects, like a class roster of students, a fleet of cars,
    or, in this case, the vertices of a polygon.

    This program reads the vertices of a polygon from the user, stores them in
    an array of `point` structs, and then prints them back out.

    This example merges the logic from two previous files into a more general
    and robust program.

    Concepts Covered:
    - Declaring an array of `struct`s.
    - Passing an array of `struct`s to a function.
    - Looping through an array of `struct`s to process each element.
*/

#include <stdio.h>

struct point {
    int x;
    int y;
};

// Function Prototypes
void printPoint(struct point pt);
void readPoint(struct point *ptr);
void printPolygon(struct point polygon[], int num_vertices);
void readPolygon(struct point polygon[], int num_vertices);


int main(void) {
    int num_vertices;

    printf("How many vertices does the polygon have? ");
    scanf("%d", &num_vertices);

    // Basic input validation
    if (num_vertices <= 0) {
        printf("A polygon must have at least 1 vertex.\n");
        return 1; // Exit with an error
    }

    // A Note on Variable-Length Arrays (VLAs):
    // `struct point polygon[num_vertices];` creates a VLA, whose size is
    // determined at runtime. While convenient, they are not part of the most
    // recent C standards and can be risky if `num_vertices` is very large.
    // A more common and safer approach in production code would be to either
    // declare an array with a fixed maximum size, or use dynamic allocation (`malloc`).
    struct point polygon[num_vertices];

    readPolygon(polygon, num_vertices);
    printPolygon(polygon, num_vertices);

    return 0;
}

/*
    Function: readPolygon
    Purpose: Reads the coordinates for all vertices of a polygon.
    It loops and calls readPoint for each vertex.
*/
void readPolygon(struct point polygon[], int num_vertices) {
    printf("\nEnter the %d vertices for the polygon:\n", num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex #%d:\n", i + 1);
        // We pass the address of the current struct in the array, `&polygon[i]`,
        // to the readPoint function.
        readPoint(&polygon[i]);
    }
}

/*
    Function: printPolygon
    Purpose: Prints the coordinates of all vertices of a polygon.
*/
void printPolygon(struct point polygon[], int num_vertices) {
    printf("\nThe vertices of your polygon are:\n");
    for (int i = 0; i < num_vertices; i++) {
        // We pass the struct itself, `polygon[i]`, by value to printPoint.
        printPoint(polygon[i]);
    }
}

/*
    Function: readPoint
    Purpose: Reads a single point's coordinates from the user.
*/
void readPoint(struct point *ptr) {
    printf("  x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("  y-coordinate: ");
    scanf("%d", &ptr->y);
}

/*
    Function: printPoint
    Purpose: Prints a single point in (x, y) format.
*/
void printPoint(struct point pt) {
    printf("  (%d, %d)\n", pt.x, pt.y);
}
