/*
    ================================================================================
    Tutorial: Algorithms - Finding the Minimum Value (Streaming)
    ================================================================================

    This program finds the smallest integer from a list of numbers provided by
    the user.

    The original code read all numbers into an array first. However, to find the
    minimum value, you don't actually need to store the entire list! You can
    process the numbers as they arrive, keeping track of the smallest one you've
    seen so far. This "streaming" approach uses much less memory and is more
    efficient if you don't need the full list for other purposes.

    We will refactor the code to use this more efficient, streaming approach.

    Concepts Covered:
    - The "streaming" approach to finding a minimum value.
    - The importance of correct initialization.
    - Variable-Length Arrays (VLAs) and why they should often be avoided.
*/

#include <stdio.h>
#include <limits.h> // For INT_MAX

// This helper function is fine. It clearly returns the smaller of two integers.
int min(int a, int b);

int main(void) {
    int num_to_read = 0;
    int current_num = 0;
    // We need a variable to store the minimum value found so far.
    // A great way to initialize it is with the largest possible integer value.
    // This guarantees that the very first number the user enters will be smaller
    // and will become the first "real" minimum.
    // INT_MAX is a constant from the <limits.h> library.
    int min_so_far = INT_MAX;

    printf("How many integers do you want to compare? ");
    scanf("%d", &num_to_read);

    if (num_to_read <= 0) {
        printf("Nothing to compare.\n");
        return 0;
    }

    printf("Enter %d integers:\n", num_to_read);

    for (int i = 0; i < num_to_read; i++) {
        scanf("%d", &current_num);
        // Compare the newly entered number with our running minimum.
        // Update the minimum if the new number is smaller.
        min_so_far = min(min_so_far, current_num);
    }

    printf("The smallest integer entered was: %d\n", min_so_far);

    return 0;
}

/*
    A Note on Variable-Length Arrays (VLAs):
    The original code used `int array[len];` where `len` was a variable read from
    the user. This is called a Variable-Length Array. While some C compilers
    support this, it is NOT part of the modern C standard (C11/C18) and can be
    risky. If a user enters a very large number for `len`, it can cause a "stack
    overflow" and crash your program. For this problem, storing the array was
    unnecessary, so the streaming approach is much better and safer.
*/

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
