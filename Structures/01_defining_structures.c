/*
    ================================================================================
    Tutorial: Structures - Defining Your Own Data Types
    ================================================================================

    Welcome to Structures, or `struct`s. This is a powerful feature that allows
    you to create your own custom data types by grouping other variables together.

    Think of a `struct` as a "blueprint" for a new type of variable. If you want
    to represent a student, you need to store their name, age, grade, etc. A
    `struct` lets you bundle all of this related information into a single,
    neat package.

    Concepts Covered:
    - The `struct` keyword for defining a new structure type.
    - Declaring a variable of your new `struct` type.
    - Initializing a `struct` variable with data.
    - Accessing the members of a `struct` using the dot operator (`.`).
*/

#include <stdio.h>

// Here, we define a new structure named 'student'.
// This acts as a template. It doesn't allocate any memory yet, it just
// defines what a 'student' variable will look like.
struct student {
    // These are the "members" or "fields" of the structure.
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

int main(void) {
    // Now we declare a variable of our new type, `struct student`.
    // This creates a variable named `me` in memory that has space for all the
    // members we defined in the blueprint.
    // We can initialize it directly using curly braces, with the values in order.
    struct student me = {"Petra", "Bonfert-Taylor", 1989, 3.5};

    // Let's create another student variable.
    struct student you = {"Remi", "Sharrock", 2005, 3.5};

    // To access the data inside a struct variable, we use the dot operator (`.`).
    printf("Names: %s %s, %s %s\n", me.firstName, me.lastName, you.firstName, you.lastName);

    // You can access any member of the struct.
    printf("Year of birth for %s: %d\n", me.firstName, me.birthYear);
    printf("Average grade for %s: %.2lf\n", you.firstName, you.aveGrade);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Define a new struct to represent a `car`. It could have members like
        `char make[20]`, `char model[20]`, `int year`, and `double price`.
    2.  Create a couple of `car` variables, initialize them, and print out
        their details.
    3.  You can also assign one struct variable to another, like `struct student new_student = me;`.
        This copies the values of all members. Try it out!
    ================================================================================
*/
