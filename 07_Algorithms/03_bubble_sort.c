/*
    ================================================================================
    Tutorial: Algorithms - Bubble Sort
    ================================================================================

    This program demonstrates a simple but inefficient sorting algorithm called
    **Bubble Sort**.

    The core idea is to repeatedly step through the list, compare adjacent
    elements, and swap them if they are in the wrong order. This process is
    repeated until the list is sorted. The smaller elements "bubble" to the
    top of the list.

    Characteristics of Bubble Sort:
    - Simplicity: It is one of the simplest sorting algorithms to understand.
    - Performance: It is very slow for anything other than small or mostly-sorted
      lists. Its time complexity is O(n^2) or "quadratic" time. This means if
      you double the size of the list, the sorting time roughly quadruples.

    Concepts Covered:
    - The bubble sort algorithm.
    - Using nested loops for sorting.
    - A simple in-place swap.
    - An optimized version of bubble sort.
*/

#include <stdio.h>

void printArray(int arr[], int size);

int main(void) {
    int list[] = {759, 14, 2, 900, 106, 77, -10, 8, -3, 5};
    int n = 10;
    int temp_swap;

    printf("Unsorted list: \n");
    printArray(list, n);
    printf("\n");

    // The outer loop (`j`) controls how many passes we make over the array.
    // After the first pass, the largest element is guaranteed to be at the end.
    // After the second pass, the second-largest is in place, and so on.
    // We need n-1 passes in the worst case.
    for (int j = 0; j < n - 1; j++) {
        // --- Optimization ---
        // We can add a flag to check if any swaps were made during a pass.
        // If a full pass completes with no swaps, the array is already sorted,
        // and we can exit early.
        int swapped = 0;

        // The inner loop (`i`) does the actual comparison and swapping.
        // It "bubbles" the largest unsorted element towards the end of the array.
        // The `n - 1 - j` is a further optimization: we don't need to re-check
        // the elements that are already sorted at the end of the array.
        for (int i = 0; i < n - 1 - j; i++) {
            if (list[i] > list[i + 1]) {
                // The elements are in the wrong order, so we swap them.
                temp_swap = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp_swap;
                swapped = 1; // Set the flag because we made a swap.
            }
        }

        printf("After pass %d: ", j + 1);
        printArray(list, n);

        // If the 'swapped' flag is still 0, it means the list is sorted.
        if (swapped == 0) {
            printf("Array is sorted! Exiting early.\n");
            break; // Exit the outer loop.
        }
    }

    printf("\nFinal sorted list: \n");
    printArray(list, n);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
