/*
    ================================================================================
    Tutorial: C Basics - Type Casting for Accurate Division
    ================================================================================

    This program calculates the average of a set of grades. It highlights a
    critical concept in C: type casting, which is necessary to get an accurate
    decimal result from a division of two integers.

    Concepts Covered:
    - The problem with integer division when a decimal result is needed.
    - Type Casting: Explicitly converting a value from one data type to another.
    - Using 'double' for floating-point numbers.
    - The '%lf' format specifier for printing doubles.
*/

#include <stdio.h>

int main(void) {
    int num_grades = 0;
    int current_grade = 0;
    int sum = 0;
    double average = 0.0; // Use a 'double' for the average to store decimal values.

    printf("How many grades do you want to enter? ");
    scanf("%d", &num_grades);

    printf("Enter %d grades, one at a time:\n", num_grades);
    for (int i = 0; i < num_grades; i++) {
        printf("Enter grade #%d: ", i + 1);
        scanf("%d", &current_grade);
        sum += current_grade; // Shorthand for sum = sum + current_grade
    }

    // The Problem with Integer Division:
    // If we were to write 'average = sum / num_grades;', C would perform
    // integer division, because both 'sum' and 'num_grades' are integers.
    // The result would be an integer, and any decimal part would be lost
    // *before* it gets assigned to the 'average' variable.
    // For example, if sum=10 and num_grades=4, `10 / 4` would result in 2, not 2.5.

    // The Solution: Type Casting
    // To fix this, we must convert one of the operands to a floating-point type
    // *before* the division happens. We do this by prefixing the variable with
    // the desired type in parentheses, like `(double)sum`.
    // When one operand is a double, C performs floating-point division,
    // preserving the decimal part of the result.
    average = (double)sum / num_grades;

    // The '%.2lf' format specifier tells printf to display a double ('lf')
    // rounded to two decimal places ('.2').
    printf("The average of the grades is: %.2lf\n", average);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Remove the `(double)` cast from the calculation and see what happens.
        Enter numbers that should result in a decimal average (e.g., 3 grades: 5, 5, 6).
        You'll see the incorrect result firsthand.
    2.  What if you cast the entire result, like `(double)(sum / num_grades)`?
        Try it out. You'll find that this doesn't work, because the integer
        division happens first inside the parentheses *before* the cast can occur.
        This demonstrates that the cast must happen on an operand *before* the division.
    ================================================================================
*/
