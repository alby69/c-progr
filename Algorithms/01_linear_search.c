/*
    ================================================================================
    Tutorial: Algorithms - Linear Search
    ================================================================================

    This program demonstrates a fundamental searching algorithm called a
    **Linear Search**.

    A linear search is the most straightforward search strategy. It sequentially
    checks each element of a list until a match is found or the whole list has
    been searched.

    Characteristics of Linear Search:
    - Simplicity: It's very easy to understand and implement.
    - Data Requirement: It works on any list of data, sorted or unsorted.
    - Performance: It can be slow for large lists. In the worst case, if the
      item is the last element or not in the list at all, you have to check
      every single element. This is described as O(n) or "linear" time complexity.

    Concepts Covered:
    - The linear search algorithm.
    - Using a 'while' loop that terminates on one of two conditions.
    - Using a "flag" variable to track search success.
*/

#include <stdio.h>

int main(void) {
    int list[] = {6, -2, 5, 12, 7, 3, 8, 18, -10, 1};
    int n = 10;
    int item_to_find;
    int i = 0;
    int found_flag = 0; // 0 for false, 1 for true

    printf("Here is the list of numbers: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", list[j]);
    }
    printf("\nWhich number are you looking for? ");
    scanf("%d", &item_to_find);

    // The core of the linear search.
    // The `while` loop continues as long as we haven't found the item AND
    // we haven't run out of elements to check (i < n).
    while (found_flag == 0 && i < n) {
        printf("Checking index %d (value %d)...\n", i, list[i]);
        if (item_to_find == list[i]) {
            // We found a match!
            found_flag = 1;
        } else {
            // No match, so we move to the next element.
            i++;
        }
    }

    // After the loop, we check the flag to see if the search was successful.
    if (found_flag == 0) { // Or just `if (!found_flag)`
        printf("%d is not a member of this list.\n", item_to_find);
    } else {
        printf("I found %d at index %d in the list.\n", item_to_find, i);
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  A `for` loop can also be used for a linear search. Can you rewrite this
        program to use a `for` loop instead of a `while` loop? You would still
        need a `found_flag` and a `break` statement to exit the loop early once
        the item is found.
    2.  What if the list contains duplicates? This implementation will always
        find the *first* occurrence. How would you modify it to find the *last*
        occurrence? (Hint: you couldn't exit the loop early).
    3.  The next example will show a "bisection" or "binary" search, which is
        much faster but requires the data to be sorted first.
    ================================================================================
*/
