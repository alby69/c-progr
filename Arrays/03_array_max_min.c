/*
    ================================================================================
    Tutorial: Arrays - Finding Maximum and Minimum Values
    ================================================================================

    A very common task when working with data is to find the largest or smallest
    value in a set. This program shows the standard algorithm for finding the
    maximum and minimum values in an array.

    This file merges the logic from two previous examples (`03_array_max_min.c`
    and `04_array_max_age.c`).

    Concepts Covered:
    - The algorithm for finding the maximum value in an array.
    - The algorithm for finding the minimum value in an array.
    - The importance of correct initialization when searching for min/max.
*/

#include <stdio.h>

int main(void) {
    int ages[10];

    printf("Please enter the ages of 10 people:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &ages[i]);
    }

    // --- Finding the Maximum and Minimum ---

    // The key to finding the min or max is to have a variable that holds the
    // "biggest value seen so far" or "smallest value seen so far".

    // A ROBUST way to initialize is to set both max and min to the *first*
    // element of the array. This guarantees they hold a real value from the
    // data set to start with.
    int age_max = ages[0];
    int age_min = ages[0];

    // The original code for finding the minimum was `int ageMin = 200;`. This is
    // a "magic number" and is a bug! It would fail if all the ages entered
    // were greater than 200. Initializing with the first element is safer.

    // Now, we loop through the *rest* of the array (starting from the second element, index 1).
    for (int i = 1; i < 10; i++) {
        // Check for a new maximum
        if (ages[i] > age_max) {
            // We found a new biggest age, so we update our variable.
            age_max = ages[i];
        }

        // Check for a new minimum
        if (ages[i] < age_min) {
            // We found a new smallest age, so we update our variable.
            age_min = ages[i];
        }
    }

    printf("\nThe maximum age is %d.\n", age_max);
    printf("The minimum age is %d.\n", age_min);

    // --- Using the Results ---
    printf("\nAge differences with the eldest person:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d:%d ", ages[i], age_max - ages[i]);
    }

    printf("\n\nAge differences with the youngest person:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d:%d ", ages[i], ages[i] - age_min);
    }
    printf("\n");

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What if you wanted to find the *index* of the oldest person, not just
        their age? You would need another variable, `max_age_index`, that you
        update inside the `if (ages[i] > age_max)` block.
    2.  This program uses a fixed-size array of 10. Can you modify it to first
        ask the user how many ages they want to enter, and then process that
        many? (You'll still need to declare an array with a fixed *maximum* size).
    ================================================================================
*/
