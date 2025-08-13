/*
    ================================================================================
    Tutorial: C Basics - Reading Multiple Inputs with a Loop
    ================================================================================

    This program demonstrates how to use a loop to read a specific number of
    inputs from the user and calculate their sum.

    Concepts Covered:
    - The 'for' loop for repeating actions a set number of times.
    - Using a counter variable in a loop.
    - Combining scanf() with a loop for multiple inputs.
    - Accumulating a sum.
*/

#include <stdio.h>

int main() {
    // how_many_to_sum: stores the total count of numbers the user wants to add.
    int how_many_to_sum = 0;
    // current_number: stores the number entered by the user in each iteration of the loop.
    int current_number = 0;
    // sum: an "accumulator" variable, initialized to 0, to store the running total.
    int sum = 0;

    printf("How many numbers do you want to sum? ");
    // Read the total count from the user.
    scanf("%d", &how_many_to_sum);

    printf("Great! Please enter %d numbers, one at a time.\n", how_many_to_sum);

    // The 'for' loop:
    // This is a powerful construct for repeating a block of code.
    // It consists of three parts, separated by semicolons:
    // 1. Initialization (int i = 0): Runs once at the beginning. Creates a counter 'i'.
    // 2. Condition (i < how_many_to_sum): Checked before each iteration. The loop
    //    continues as long as this condition is true.
    // 3. Post-iteration (i++): Runs at the end of each iteration. Increments the counter.
    for (int i = 0; i < how_many_to_sum; i++) {
        printf("Enter number %d: ", i + 1); // We use i+1 to show a 1-based count to the user.
        scanf("%d", &current_number);

        // Accumulation:
        // We add the number just entered to our running total.
        // 'sum = sum + current_number;' is often written with the shorthand 'sum += current_number;'.
        sum = sum + current_number;

        printf("You entered %d. The current sum is %d.\n", current_number, sum);
    }

    printf("\nAll numbers have been entered.\n");
    printf("The final sum is: %d\n", sum);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Can you modify this program to calculate the average of the numbers instead
        of the sum? You would calculate the sum first, then divide by 'how_many_to_sum'.
        Be careful about integer division vs. floating-point division! You might
        need to use 'double' or 'float' variables.
    2.  What if you wanted to find the largest number entered instead of the sum?
        You would need a new variable, maybe called 'largest_so_far', and an 'if'
        statement inside the loop to update it.
    ================================================================================
*/
