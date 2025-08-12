/*
    ================================================================================
    Tutorial: Recursion - Factorial Example
    ================================================================================

    This program calculates the factorial of a number, and it serves as a classic
    introduction to **Recursion**.

    A recursive function is a function that calls itself. To prevent it from
    calling itself forever, it must have two parts:
    1.  A **Base Case**: A simple condition that stops the recursion. For factorial,
        the base case is `0! = 1`.
    2.  A **Recursive Step**: The part of the function that calls itself, but with
        a "smaller" or "simpler" input that moves it closer to the base case.
        For factorial, this is `n * factorial(n-1)`.

    This file shows both the recursive and the more common iterative (loop-based)
    solutions to demonstrate the differences.

    Concepts Covered:
    - The definition of recursion.
    - Base cases and recursive steps.
    - Comparing a recursive solution to an iterative one.
*/

#include <stdio.h>

// Function prototypes
long long factorial_iterative(int n);
long long factorial_recursive(int n);

int main(void) {
    int n;
    printf("Please enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("%d is negative! Aborting...\n", n);
    } else {
        // We use `%lld` to print a `long long` integer, which is needed because
        // factorials grow extremely quickly.
        printf("Iterative solution: %d! = %lld\n", n, factorial_iterative(n));
        printf("Recursive solution: %d! = %lld\n", n, factorial_recursive(n));
    }

    return 0;
}

/*
    Function: factorial_iterative
    Purpose: Calculates n! using a standard 'for' loop.
    This approach is generally more efficient in C for this problem.
*/
long long factorial_iterative(int n) {
    long long result = 1;
    // We loop from 1 up to n, multiplying the result by each number.
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

/*
    Function: factorial_recursive
    Purpose: Calculates n! using recursion.
    This approach is often more elegant and closer to the mathematical definition.
*/
long long factorial_recursive(int n) {
    // 1. Base Case: The condition that stops the recursion.
    // If n is 0, we know the answer is 1, so we just return it.
    if (n == 0) {
        return 1;
    }
    // 2. Recursive Step: The function calls itself with a smaller input.
    // We calculate `n * factorial(n-1)`. The call to `factorial(n-1)` will
    // continue until it hits the base case of `factorial(0)`.
    else {
        return n * factorial_recursive(n - 1);
    }
}

/*
    How does `factorial_recursive(4)` work?
    - It returns 4 * factorial_recursive(3)
      - which returns 3 * factorial_recursive(2)
        - which returns 2 * factorial_recursive(1)
          - which returns 1 * factorial_recursive(0)
            - which returns 1 (Base Case!)
    The results are then multiplied back up the chain: 1*1 -> 2*1 -> 3*2 -> 4*6 = 24.
*/
