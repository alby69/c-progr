/*
    ================================================================================
    Tutorial: Control Flow - Decisions Based on String Length
    ================================================================================

    This program reads a word from the user and then prints either 1 or 2
    based on whether the length of the word is even or odd.

    The original code calculates the string length manually with a 'while' loop.
    We will show that method and then introduce the standard C library function
    `strlen()` from `<string.h>`, which is the correct and more efficient way
    to do this.

    Concepts Covered:
    - Character arrays (strings) in C.
    - The null terminator ('\0') at the end of a string.
    - Manually calculating string length with a loop.
    - Using the standard `strlen()` function from the `<string.h>` library.
    - The ternary operator as a shortcut for 'if-else'.
*/

// We include <string.h> to get access to standard string functions like strlen().
#include <stdio.h>
#include <string.h>

int main(void) {
    // Declare a character array to hold the user's input.
    // We make it size 51 to hold a 50-character word plus the null terminator.
    char word[51];
    int length = 0;
    int output_value = 0;

    printf("Enter a single word (up to 50 characters): ");
    // When using scanf with %s, it reads a sequence of non-whitespace characters.
    // It automatically adds the null terminator '\0' at the end.
    scanf("%s", word);

    /*
        Method 1: Manual Calculation (as in the original code)
        This is a great way to understand how strings work in C. The loop
        continues until it finds the special null terminator character ('\0')
        that marks the end of every string.

        int i = 0;
        while (word[i] != '\0') {
            i++;
        }
        length = i;
    */

    // Method 2: The Standard Library Function `strlen()` (Preferred)
    // This function does the same loop for us, but it's optimized and less
    // error-prone. It returns the number of characters in the string, not
    // including the null terminator.
    length = strlen(word);
    printf("The length of the word \"%s\" is %d.\n", word, length);

    // Now, we make a decision based on the length.
    if (length % 2 == 0) {
        // The length is even.
        output_value = 1;
    } else {
        // The length is odd.
        output_value = 2;
    }
    printf("The output value is: %d\n", output_value);

    // Bonus: The Ternary Operator
    // For a simple if-else that assigns a value to a single variable, C provides
    // a shortcut called the ternary operator `(condition ? value_if_true : value_if_false)`.
    int ternary_output = (length % 2 == 0) ? 1 : 2;
    printf("Result using the ternary operator: %d\n", ternary_output);


    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What happens if the user enters a sentence with spaces, like "hello world"?
        `scanf("%s", ...)` stops reading at the first space. To read a whole line
        of text, you would need a different function, like `fgets()`.
    2.  Try to write a program that prints "VOWEL" if a user-entered word starts
        with a vowel (a, e, i, o, u) and "CONSONANT" otherwise. You would need to
        check the first character of the string, which is `word[0]`.
    ================================================================================
*/
