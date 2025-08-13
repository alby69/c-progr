/*
    ================================================================================
    Tutorial: Functions - Decomposition and Reusability
    ================================================================================

    This program demonstrates one of the most powerful concepts in programming:
    decomposition. We break down a complex problem (drawing shapes) into smaller,
    manageable, and reusable pieces called functions.

    Notice how the `printTriangle` and `printRectangle` functions both reuse
    the `printLine` function. This avoids code duplication and makes the program
    easier to understand and maintain.

    Concepts Covered:
    - Defining 'void' functions (functions that don't return a value).
    - Passing arguments to functions.
    - Function prototyping.
    - Reusing functions (one function calling another).
*/

#include <stdio.h>

// Function Prototypes:
// We declare the functions here so that `main` knows about them before they are
// called. This allows us to define the functions in any order we want after `main`.
void printLine(int nCols, char pattern);
void printTriangle(int nLines, char pattern);
void printRectangle(int nLines, int nCols, char pattern);

int main(void) {
    int nCols;
    int nLines;

    printf("--- Printing a Line ---\n");
    printf("How many columns would you like? ");
    scanf("%d", &nCols);
    printLine(nCols, 'X');
    printf("\n");

    printf("--- Printing a Triangle ---\n");
    printf("How many lines would you like? ");
    scanf("%d", &nLines);
    printTriangle(nLines, '*');
    printf("\n");

    printf("--- Printing a Rectangle ---\n");
    // We can reuse the nLines and nCols variables from before.
    printf("Using %d lines and %d columns.\n", nLines, nCols);
    printRectangle(nLines, nCols, '#');

    return 0;
}

/*
    Function: printLine
    Purpose: Prints a single line of characters of a specified length and pattern.
    Parameters:
        - nCols: The number of characters to print.
        - pattern: The character to use for printing.
    Returns: void (nothing)
*/
void printLine(int nCols, char pattern) {
    for (int i = 0; i < nCols; i++) {
        printf("%c", pattern);
    }
    printf("\n"); // Move to the next line after printing the characters.
}

/*
    Function: printTriangle
    Purpose: Prints a right-angled triangle of a specified height.
    This function *calls* `printLine` repeatedly to do its work.
*/
void printTriangle(int nLines, char pattern) {
    // The outer loop controls which line we are on (from 1 to nLines).
    for (int line = 1; line <= nLines; line++) {
        // For each line, we call printLine, telling it to print 'line' number of characters.
        // Line 1 prints 1 char, Line 2 prints 2 chars, and so on.
        printLine(line, pattern);
    }
}

/*
    Function: printRectangle
    Purpose: Prints a solid rectangle of a specified height and width.
    This function also *calls* `printLine` repeatedly.
*/
void printRectangle(int nLines, int nCols, char pattern) {
    for (int i = 0; i < nLines; i++) {
        // For each line of the rectangle, we simply print a full line of characters.
        printLine(nCols, pattern);
    }
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Can you create a new function `printSquare(int size, char pattern)` that
        calls `printRectangle`? This shows another layer of decomposition.
    2.  Create a function `printHollowRectangle(int nLines, int nCols, char pattern)`.
        For this, you'll need to modify the logic inside. The top and bottom lines
        will be solid, but the middle lines will only have the pattern character
        at the start and end, with spaces in between. This is a good challenge!
    ================================================================================
*/
