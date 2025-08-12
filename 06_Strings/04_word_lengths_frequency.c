/*
    ================================================================================
    Tutorial: Strings and Arrays - Word Length Frequency Counter
    ================================================================================

    This program reads a number of words and then calculates the frequency of
    each word length. For example, it counts how many 3-letter words, 4-letter
    words, etc., were entered by the user.

    This is a fantastic example of a common programming pattern: using an
    array as a frequency counter or histogram.

    Concepts Covered:
    - Using an array as a frequency counter.
    - The importance of initializing an array to zero.
    - Using one variable's value (word length) as an index for another array.
    - Preventing out-of-bounds array access.
*/

#include <stdio.h>
#include <string.h> // For strlen()

// It's good practice to use constants for array sizes.
#define MAX_WORD_LENGTH 10
#define MAX_WORDS 50

int main(void) {
    int num_words_to_read = 0;
    char current_word[MAX_WORD_LENGTH + 1]; // +1 for the null terminator

    // This is our frequency array. The index will represent the word length.
    // `length_counts[3]` will store the number of 3-letter words.
    // We make it size `MAX_WORD_LENGTH + 1` to safely handle words of length
    // up to MAX_WORD_LENGTH (indices 0 through 10).
    // Initializing with `{0}` sets all elements to zero, which is crucial.
    int length_counts[MAX_WORD_LENGTH + 1] = {0};

    printf("How many words do you want to analyze (up to %d)? ", MAX_WORDS);
    scanf("%d", &num_words_to_read);

    if (num_words_to_read > MAX_WORDS || num_words_to_read <= 0) {
        printf("Invalid number of words.\n");
        return 1;
    }

    printf("Enter %d words (max length %d each):\n", num_words_to_read, MAX_WORD_LENGTH);

    for (int i = 0; i < num_words_to_read; i++) {
        scanf("%s", current_word);

        int current_length = strlen(current_word);
        // The original code printed here, which can be noisy.
        // printf("Read word: \"%s\", length: %d\n", current_word, current_length);

        // --- The Core Logic ---
        // We use the length of the word as an index into our frequency array.
        // But first, we must check if the length is within the bounds of our array!
        if (current_length <= MAX_WORD_LENGTH) {
            // If the word has length `L`, we increment the counter at index `L`.
            length_counts[current_length]++;
        } else {
            printf("Warning: The word \"%s\" is too long and will be ignored.\n", current_word);
        }
    }

    // --- Printing the Results ---
    printf("\n--- Word Length Frequency ---\n");
    // We loop through our frequency array to print the results.
    for (int j = 0; j <= MAX_WORD_LENGTH; j++) {
        // We only print the counts for lengths that we actually saw.
        if (length_counts[j] > 0) {
            printf("There are %d word(s) with %d letter(s).\n", length_counts[j], j);
        }
    }

    return 0;
}
