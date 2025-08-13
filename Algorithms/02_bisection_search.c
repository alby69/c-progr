/*
    ================================================================================
    Tutorial: Algorithms - Binary Search (Bisection Search)
    ================================================================================

    This program demonstrates a much more efficient searching algorithm called a
    **Binary Search** or **Bisection Search**.

    The core idea is to repeatedly divide the search interval in half. If the
    value of the search key is less than the item in the middle of the interval,
    narrow the interval to the lower half. Otherwise, narrow it to the upper half.
    This is continued until the value is found or the interval is empty.

    **CRITICAL REQUIREMENT: Binary search ONLY works on a SORTED list.**

    Characteristics of Binary Search:
    - Efficiency: It is extremely fast. For a list of `n` items, it takes at
      most `log2(n)` comparisons. For a list of 1,000,000 items, a linear search
      might take 1,000,000 steps, while a binary search will take at most 20!
      This is "logarithmic" or O(log n) time complexity.
    - Data Requirement: The data MUST be sorted.

    Concepts Covered:
    - The binary search algorithm.
    - Manipulating interval boundaries (lower and upper bounds).
    - The power of "divide and conquer" algorithms.
*/

#include <stdio.h>

int main(void) {
    // Note that this list is already sorted in ascending order.
    int list[] = {-10, -3, 2, 5, 8, 14, 77, 106, 759, 900};
    int n = 10;
    int item_to_find;
    int found_flag = 0;

    // We need three variables to track our search space:
    int lower_bound = 0;        // The starting index of our search space.
    int upper_bound = n - 1;    // The ending index of our search space.
    int midpoint;               // The calculated middle index.

    printf("Which number are you looking for? ");
    scanf("%d", &item_to_find);

    // The loop continues as long as we haven't found the item AND our search
    // space is still valid (the lower bound hasn't crossed the upper bound).
    while (found_flag == 0 && lower_bound <= upper_bound) {
        // Calculate the middle index of the current search space.
        midpoint = lower_bound + (upper_bound - lower_bound) / 2; // Avoids overflow for huge arrays
        printf("Searching between index %d and %d... Midpoint is %d (value %d)\n", lower_bound, upper_bound, midpoint, list[midpoint]);

        if (item_to_find == list[midpoint]) {
            // We found it!
            found_flag = 1;
        } else if (item_to_find < list[midpoint]) {
            // The item must be in the lower half.
            // We discard the top half by moving our upper bound.
            printf(" -> Item is smaller, tossing the top half.\n");
            upper_bound = midpoint - 1;
        } else { // item_to_find > list[midpoint]
            // The item must be in the upper half.
            // We discard the bottom half by moving our lower bound.
            printf(" -> Item is larger, tossing the bottom half.\n");
            lower_bound = midpoint + 1;
        }
    }

    if (found_flag == 0) {
        printf("Number %d was not found in the array.\n", item_to_find);
    } else {
        // Note: `midpoint` will hold the correct index if the item was found.
        printf("Number %d was found at index %d in the array.\n", item_to_find, midpoint);
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Try searching for a number that isn't in the list (e.g., 6) and watch how
        the search space (lower_bound and upper_bound) shrinks until it becomes
        invalid (`lower_bound > upper_bound`), causing the loop to terminate.
    2.  What happens if the list is not sorted? Try changing the order of the
        elements in the `list` array and see how the algorithm fails. This will
        prove why the sorted requirement is so important.
    ================================================================================
*/
