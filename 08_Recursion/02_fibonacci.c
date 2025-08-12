/*
    ================================================================================
    Tutorial: Recursion - Fibonacci Numbers
    ================================================================================

    This program calculates the Nth number in the Fibonacci sequence, another
    classic example of recursion.

    The Fibonacci sequence is defined as:
    F(1) = 0
    F(2) = 1
    F(n) = F(n-1) + F(n-2) for n > 2

    This definition translates very directly into a recursive function.

    **A VERY IMPORTANT NOTE ON EFFICIENCY:**
    While this is a great example for learning recursion, this specific
    implementation is extremely inefficient! It recalculates the same values
    many, many times. For example, to calculate `fibonacci(5)`, it calculates
    `fibonacci(3)` twice, `fibonacci(2)` three times, etc. For larger numbers
    (try anything over 40), this becomes incredibly slow. A loop-based (iterative)
    solution is much more efficient for this particular problem.

    Concepts Covered:
    - Recursion with multiple base cases.
    - Recursion with multiple recursive calls in a single return statement.
    - An example of an inefficient recursive algorithm.
*/

#include <stdio.h>

int fibonacci(int n);

int main(void) {
    int N, fib;
    printf("Which Fibonacci number would you like (e.g., 1st, 2nd, 3rd...)? ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("%d is not a positive number. Aborting!\n", N);
    } else {
        fib = fibonacci(N);
        printf("The %dth Fibonacci number is %d.\n", N, fib);
    }

    return 0;
}

/*
    Function: fibonacci
    Purpose: Calculates the Nth Fibonacci number using recursion.
*/
int fibonacci(int n) {
    // Base Case 1: The first Fibonacci number is 0.
    if (n == 1) {
        return 0;
    }
    // Base Case 2: The second Fibonacci number is 1.
    else if (n == 2) {
        return 1;
    }
    // Recursive Step: The Nth number is the sum of the previous two.
    // The function makes two recursive calls to itself.
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

/*
    How does `fibonacci(5)` work?
    - It returns fibonacci(4) + fibonacci(3)
      - fibonacci(4) returns fibonacci(3) + fibonacci(2)
        - fibonacci(3) returns fibonacci(2) + fibonacci(1) -> returns 1 + 0 = 1
        - fibonacci(2) returns 1 (Base Case)
        - So, fibonacci(4) returns 1 + 1 = 2
      - fibonacci(3) returns fibonacci(2) + fibonacci(1) -> returns 1 + 0 = 1
    - Finally, fibonacci(5) returns 2 + 1 = 3.
    Notice that `fibonacci(3)` was calculated twice! This is the source of the inefficiency.
*/
