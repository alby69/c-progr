/*
    ================================================================================
    Tutorial: Strings - Comparing Strings Alphabetically
    ================================================================================

    This program compares two words entered by the user to determine their
    alphabetical order.

    The original code implements the comparison logic manually. We will keep
    that as a reference but introduce the standard C library function `strcmp()`
    from `<string.h>`, which is the correct and standard way to compare strings.

    Concepts Covered:
    - The logic of lexicographical (alphabetical) comparison.
    - Using the `strcmp()` function to compare strings.
    - Interpreting the return value of `strcmp()`.
*/

#include <stdio.h>
#include <string.h> // For strcmp()

int main(void) {
    char word1[50];
    char word2[50];

    printf("Please enter a word: ");
    scanf("%s", word1);
    printf("And another word: ");
    scanf("%s", word2);

    /*
        Method 1: Manual Comparison (as in the original code)
        This is how comparison works under the hood. The loop finds the first
        character where the two strings differ. The comparison of those two
        characters then determines the alphabetical order of the words.

        int i = 0;
        while (word1[i] != '\0' && word2[i] != '\0' && word1[i] == word2[i]) {
            i++;
        }
        // After the loop, `i` is the index of the first differing character.
        // We can then compare `word1[i]` and `word2[i]`.
    */

    // Method 2: The Standard Library Function `strcmp()` (Preferred)
    // The `strcmp()` function (short for "string compare") does all the
    // manual work for us. It returns:
    //   - A negative number (< 0) if word1 comes before word2.
    //   - A positive number (> 0) if word1 comes after word2.
    //   - Zero (0) if the strings are identical.
    int comparison_result = strcmp(word1, word2);

    printf("\n--- Result ---\n");
    if (comparison_result < 0) {
        printf("\"%s\" comes before \"%s\" alphabetically.\n", word1, word2);
    } else if (comparison_result > 0) {
        printf("\"%s\" comes after \"%s\" alphabetically.\n", word1, word2);
    } else {
        printf("You entered the same word, \"%s\", twice.\n", word1);
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  `strcmp()` is case-sensitive. 'A' comes before 'a'. There is another
        function, often called `stricmp()` or `strcasecmp()`, that performs a
        case-insensitive comparison. Its availability can depend on the system,
        but it's good to know it exists.
    2.  How would you sort an *array* of strings? You would need a sorting
        algorithm (like bubble sort, which we'll see later) and you would use
        `strcmp()` for the comparisons. You would also need to swap the strings
        if they are out of order, which requires the `strcpy()` function. This
        is a classic, challenging C exercise!
    ================================================================================
*/
