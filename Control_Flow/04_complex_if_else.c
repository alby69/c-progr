/*
    ================================================================================
    Tutorial: Control Flow - Simplifying with 'else if'
    ================================================================================

    This program calculates a cost based on a person's age and weight, using
    a set of rules. The original code uses nested 'if-else' statements.

    We will refactor this code to use the 'else if' structure, which is often
    cleaner and easier to read when you have a chain of mutually exclusive conditions.

    Concepts Covered:
    - Nested 'if-else' statements.
    - The 'else if' ladder for cleaner multi-condition logic.
    - Logical AND (&&) to combine conditions.
*/

#include <stdio.h>

int main(void) {
    int age = 0;
    int weight = 0; // in pounds
    int cost = 0;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter weight in pounds: ");
    scanf("%d", &weight);

    /*
        Original Logic (with nested if-else):
        This works, but it can be hard to read as more conditions are added,
        leading to deeper and deeper nesting (the "arrowhead" anti-pattern).

        if (age == 60) {
            cost = 0;
        } else {
            if (age < 10) {
                cost = 5;
            } else {
                cost = 30;
                if (weight > 20) {
                    cost = cost + 10;
                }
            }
        }
    */

    // Refactored Logic (with 'else if' ladder):
    // This structure is much flatter and easier to follow. The conditions are
    // checked from top to bottom. As soon as one is true, its block is executed,
    // and the rest of the chain is skipped.
    if (age == 60) {
        cost = 0;
    } else if (age < 10) {
        cost = 5;
    } else { // This block handles everyone else (age >= 10 and not 60)
        cost = 30;
        // This nested 'if' is now much simpler. It only applies to the group
        // that qualifies for the base $30 cost.
        if (weight > 20) {
            cost = cost + 10;
        }
    }

    printf("The calculated cost is: %d\n", cost);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  The rules in this program are a bit ambiguous. For example, what is the
        cost for a person who is exactly 10 years old? The current logic charges
        them $30. Is that correct? Modify the conditions to handle the age of 10
        explicitly if you want a different cost.
    2.  Add a new rule: if a person is over 100 years old, the cost is also 0.
        Where would you add this 'else if' statement in the chain? Does the
        order matter? (Hint: Yes, it can! You'd want to check for > 100 before
        the final 'else' block).
    ================================================================================
*/
