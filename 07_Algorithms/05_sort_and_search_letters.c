/*
    ================================================================================
    Tutorial: Algorithms - Counting Duplicate Characters
    ================================================================================

    This program counts the number of unique characters that are repeated in a word.
    For example, in the word "erroneousnesses", the letters 'e', 'r', 'o', and 's'
    are all repeated, so the program should output 4.

    The algorithm used here is quite clever and demonstrates a powerful technique:
    1.  **Sort:** The characters of the word are sorted alphabetically. This has
        the effect of grouping all identical letters together.
        "erroneousnesses" -> "eeeennoorrssssu"
    2.  **Count Groups:** Iterate through the sorted string and count the number
        of times a new group of duplicate letters begins.

    Concepts Covered:
    - Combining sorting and searching to solve a problem.
    - Using Bubble Sort on a character array.
    - A custom algorithm to count groups of duplicates in a sorted list.
*/

#include <stdio.h>
#include <string.h> // For strlen()

int main(void) {
    char word[51];
    char temp_swap;
    int num_duplicate_groups = 0;

    printf("Enter a word to find the number of repeated character types: ");
    scanf("%s", word);

    int n = strlen(word);

    // --- Step 1: Sort the String using Bubble Sort ---
    // This arranges the word so all identical letters are adjacent.
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            if (word[i] > word[i + 1]) {
                temp_swap = word[i];
                word[i] = word[i + 1];
                word[i + 1] = temp_swap;
            }
        }
    }

    printf("Sorted word: %s\n", word);

    // --- Step 2: Count the Groups of Duplicates ---
    // We iterate up to n-1 so we can always check `word[i+1]`.
    for (int i = 0; i < n - 1; i++) {
        // If the current character is the same as the next one, we've found
        // the beginning of a group of duplicates.
        if (word[i] == word[i + 1]) {
            num_duplicate_groups++;

            // This is a crucial inner loop. Once we've counted a group (like the
            // first 'e' in 'eeeee...'), we need to skip past all the other
            // identical characters in that same group so we don't count it again.
            while (i < n - 1 && word[i] == word[i + 1]) {
                i++;
            }
        }
    }

    printf("Number of unique characters that are repeated: %d\n", num_duplicate_groups);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  This approach is clever but not the most efficient because Bubble Sort is
        slow. A different approach would be to use a frequency array, like we
        saw in the `04_word_lengths_frequency.c` example. You could have an
        array of size 26 (for the English alphabet) and increment the count for
        each letter you see. Afterwards, you would loop through the frequency
        array and count how many elements have a value greater than 1.
    2.  Try that alternative approach! It will be much faster for long strings.
    ================================================================================
*/
