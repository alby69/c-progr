/*
    ================================================================================
    Tutorial: Control Flow - Logical Operators and a Bug Fix
    ================================================================================

    This program simulates a simple dice game where a tax is calculated based
    on the sum of two dice. It's a good example of nested 'if' statements.

    This file also contains a subtle bug that provides a great learning opportunity
    about logical operators!

    Concepts Covered:
    - Nested 'if' statements.
    - Boolean logic stored in an integer (a common C idiom).
    - The logical AND (&&) vs. logical OR (||) operators.
*/

#include <stdio.h>

int main(void) {
    int dice1 = 0;
    int dice2 = 0;
    int sum = 0;

    printf("Enter the values for two dice: ");
    scanf("%d %d", &dice1, &dice2);

    // A common C idiom: Storing a boolean result in an int.
    // The expression `sum >= 10` evaluates to either 1 (true) or 0 (false).
    // This result is then stored in the integer variable 'is_special_total'.
    sum = dice1 + dice2;
    int is_special_total = (sum >= 10);

    // --- A BUG TO FIX ---
    // The original code had a bug here: `(dice1 >= 1 || dice1 <= 6)`.
    // The logical OR (||) operator is true if *either* condition is true. Since
    // any number is either "greater than or equal to 1" OR "less than or equal to 6",
    // this condition was always true, even for invalid dice rolls like 99.
    //
    // The FIX is to use the logical AND (&&) operator, which is only true if
    // *both* conditions are true. This correctly validates the dice roll.
    if ((dice1 >= 1 && dice1 <= 6) && (dice2 >= 1 && dice2 <= 6)) {
        // This is a valid dice roll, so we can proceed.
        printf("The roll is valid.\n");

        // Nested 'if' statement:
        // This 'if' is checked only if the outer 'if' was true.
        if (is_special_total) { // This is the same as writing `if (is_special_total == 1)`
            printf("This is a special total!\n");
            printf("Special tax: 36\n");
        } else {
            printf("This is a regular total.\n");
            printf("Regular tax: %d\n", 2 * sum);
        }

    } else {
        // This 'else' belongs to the outer 'if'. It catches invalid dice rolls.
        printf("Error: Invalid dice values entered. Please enter numbers between 1 and 6.\n");
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Change the `&&` back to `||` in the validation 'if' statement and try
        entering invalid dice numbers like `7` or `-2`. See how the program
        incorrectly processes them. This is a great way to understand the bug.
    2.  The variable 'is_special_total' is convenient but not strictly necessary.
        Can you rewrite the program to not use it, putting the `sum >= 10`
        check directly into the nested 'if' statement?
    ================================================================================
*/
