/*
    ================================================================================
    Tutorial: Structures - Populating Structs with User Input
    ================================================================================

    This program builds on the previous example. Instead of initializing the
    `struct` with hard-coded values, we declare an uninitialized `struct` variable
    and then fill its members with data provided by the user.

    The key takeaway is how we use the dot operator (`.`) to access each member
    and pass it to `scanf`.

    Concepts Covered:
    - Declaring an uninitialized `struct` variable.
    - Using the dot operator (`.`) to access members for writing/input.
    - The difference in `scanf` usage for arrays vs. other types.
*/

#include <stdio.h>

struct student {
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

int main(void) {
    // We declare a `struct student` variable named 'learner'.
    // At this point, the values of its members are garbage (undefined).
    struct student learner;

    printf("Enter the student's first name: ");
    // IMPORTANT: When scanning a string into a character array like `learner.firstName`,
    // you do NOT use the '&' address-of operator. This is because the name of an
    // array already "decays" into a pointer to its first element.
    scanf("%s", learner.firstName);

    printf("Enter the student's last name: ");
    scanf("%s", learner.lastName);

    printf("Enter the student's year of birth: ");
    // For simple numeric types like `int` and `double`, you DO need the '&'
    // to pass the memory address of that specific member to scanf.
    scanf("%d", &learner.birthYear);

    printf("Enter the student's average grade: ");
    scanf("%lf", &learner.aveGrade);

    printf("\n--- Student Record ---\n");
    printf("Name: %s %s\n", learner.firstName, learner.lastName);
    printf("Year of birth: %d\n", learner.birthYear);
    printf("Average grade: %.2lf\n", learner.aveGrade);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  After populating the `learner` struct, declare a new struct variable,
        `struct student partner;`, and then try to copy the data using a single
        assignment: `partner = learner;`. Print the details of `partner` to
        confirm that all the members were copied successfully.
    ================================================================================
*/
