/*
    ================================================================================
    Tutorial: C Basics - The 'char' Data Type
    ================================================================================

    This exercise introduces the 'char' data type, which is used to store
    single characters.

    Concepts Covered:
    - The 'char' data type for single characters.
    - Character literals, enclosed in single quotes (e.g., 'A').
    - The '%c' format specifier for printing characters.
*/

#include <stdio.h>

int main(void) {
    // Variable Declaration and Initialization:
    // We declare three variables of type 'char'.
    // A 'char' holds a single character value.
    // Character literals in C are enclosed in single quotes (' ').
    // Note the difference: 'A' is a char, while "A" is a string.
    char letter1 = 'i';
    char letter2 = 'n';
    char letter3 = 'C';

    // The '%c' format specifier in printf is used to print a single character.
    // We provide the char variables as arguments, and they are substituted
    // for the %c placeholders in the output.
    printf("Programming %c%c %c\n", letter1, letter2, letter3);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  In C, characters are actually stored as small integer values according to
        a standard like ASCII. You can see this by printing a char variable
        using the '%d' (integer) format specifier instead of '%c'.
        Try it: `printf("The ASCII value of %c is %d\n", letter3, letter3);`
    2.  You can also perform arithmetic on char variables. What do you think
        `letter3 + 1` would produce if you print it as a character? Try it out!
    ================================================================================
*/
