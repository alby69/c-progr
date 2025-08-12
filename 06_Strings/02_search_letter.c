/*
    ================================================================================
    Tutorial: Strings - Searching for a Character
    ================================================================================

    This program searches for the first occurrence of the letter 't' (or 'T')
    in a given word. It then reports if the letter was found in the first or
    second half of the word.

    This is a great example of a linear search algorithm applied to a string.

    Concepts Covered:
    - Iterating through a string with a 'for' loop.
    - Character comparison.
    - Handling case-insensitivity with `tolower()`.
    - Using a "flag" variable to track if an item was found.
    - Using `break` to exit a loop early.
*/

#include <stdio.h>
#include <string.h> // For strlen()
#include <ctype.h>  // For tolower()

int main(void) {
    char word[51];
    int found_flag = 0; // A "flag" to track if we've found the letter. 0=false, 1=true.

    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);

    // We can loop through the string using a 'for' loop, which is often
    // cleaner than a 'while' loop for this kind of task.
    for (int i = 0; i < length; i++) {
        // To handle case-insensitivity, we can convert the current character
        // to lowercase before comparing it. The tolower() function is from <ctype.h>.
        if (tolower(word[i]) == 't') {
            printf("Found 't' at index %d.\n", i);

            // The original logic for determining the "half" was a bit complex.
            // Let's simplify: if the index is less than half the length, it's
            // in the first half.
            // Note on integer division: For length 5, `5 / 2` is 2.
            // Indices 0, 1 are in the first half. Index 2 (the middle) is not.
            if (i < length / 2) {
                printf("Output: 1 (first half)\n");
            } else {
                printf("Output: 2 (second half)\n");
            }

            // We found the letter, so we set our flag to true...
            found_flag = 1;
            // ...and use 'break' to exit the loop immediately. We only care
            // about the *first* occurrence.
            break;
        }
    }

    // After the loop has finished, we check the flag.
    // If the flag is still false, it means the loop completed without ever
    // finding the character.
    if (found_flag == 0) {
        printf("The letter 't' was not found.\n");
        printf("Output: -1\n");
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  The definition of "half" can be tricky. In our version, for a word with
        an odd length like "seven" (length 5), the middle character (at index 2)
        is considered part of the "second half". Is this the behavior you want?
        How would you change the condition to include the middle character in the
        first half?
    2.  Can you modify this program to count *all* occurrences of 't', not just
        the first one? You would need a counter variable and you would remove
        the `break` statement.
    ================================================================================
*/
