/*
    ================================================================================
    Tutorial: Strings - Finding the Longest Word
    ================================================================================

    This program reads a specified number of words from the user and finds the
    length of the longest word among them.

    This is a common string processing task that combines loops, string handling,
    and a max-finding algorithm.

    Concepts Covered:
    - Reading strings from input.
    - Using `strlen()` to get the length of a string.
    - The algorithm for finding a maximum value, applied to string lengths.
*/

#include <stdio.h>
#include <string.h> // We need this header for the strlen() function.

int main(void) {
    int num_words = 0;
    // This buffer will hold each word as we read it.
    // Size 101 can hold a 100-character word plus the null terminator.
    char current_word[101];
    int max_length_so_far = 0;

    printf("How many words will you enter? ");
    scanf("%d", &num_words);

    printf("Please enter %d words:\n", num_words);

    for (int i = 0; i < num_words; i++) {
        scanf("%s", current_word);

        // Use the standard strlen() function to get the length of the word just read.
        int current_length = strlen(current_word);

        // This is the standard max-finding algorithm.
        // If the length of the new word is greater than the max we've seen so far...
        if (current_length > max_length_so_far) {
            // ...then we have a new maximum!
            max_length_so_far = current_length;
        }
    }

    printf("The length of the longest word entered is: %d\n", max_length_so_far);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  This program only tells you the *length* of the longest word, but not
        what the word itself is. Can you modify it to store the longest word?
        You would need another character array, maybe `char longest_word[101];`,
        and inside the `if` block, you would use the `strcpy()` function (also
        from `<string.h>`) to copy the `current_word` into `longest_word`.
    2.  What if two words have the same, maximum length? The current program
        correctly reports their length. The modification in #1 would only store
        the *first* longest word it finds. How could you change it to store the
        *last* longest word?
    ================================================================================
*/
