/*
    ================================================================================
    Tutorial: Pointers - Modifying Variables via Functions
    ================================================================================

    This example reinforces a key use case for pointers: allowing a function to
    modify a variable from its calling scope. Here, we pass a pointer to an 'age'
    variable to a function that changes the age based on some conditions.

    This is a very common pattern in C programming.

    Concepts Covered:
    - Passing a pointer to a function.
    - Dereferencing the pointer within the function to read the original value.
    - Dereferencing the pointer to write a new value back to the original variable.
*/

#include <stdio.h>

// Function prototype: takes a pointer to an integer.
void applyElixir(int *age_ptr);

int main(void) {
    int age;
    // We can use a pointer to read input with scanf.
    // `&age` gives the address of 'age', which is what scanf needs.
    // `age_ptr` also holds the address of 'age'. So they are interchangeable here.
    int *age_ptr = &age;

    printf("Enter your current age: ");
    scanf("%d", age_ptr); // Same as `scanf("%d", &age);`

    printf("Your current age is %d.\n", age);

    // Call the function, passing the address of the 'age' variable.
    applyElixir(age_ptr); // Same as `applyElixir(&age);`

    // The 'age' variable in main has now been changed by the function.
    printf("You drank the elixir... your new age is %d!\n", age);

    return 0;
}

/*
    Function: applyElixir
    Purpose: Modifies an age value based on a set of rules.
    Parameters:
        - age_ptr: A pointer to the integer 'age' variable from main().
*/
void applyElixir(int *age_ptr) {
    // We dereference the pointer `*age_ptr` to get the current age value
    // to use in our comparison.
    if (*age_ptr > 21) {
        // If the age is over 21, subtract 10.
        // We dereference the pointer again to assign the new value.
        *age_ptr = *age_ptr - 10;
    } else {
        // Otherwise, double the age.
        *age_ptr = *age_ptr * 2;
    }
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  The `applyElixir` function modifies the age "in-place". Can you rewrite it
        so that it doesn't take a pointer, but instead `return`s the new age?
        `int calculateNewAge(int current_age);`
        You would then call it from main like this: `age = calculateNewAge(age);`.
        Both are valid patterns, and choosing between them is a design decision.
    ================================================================================
*/
