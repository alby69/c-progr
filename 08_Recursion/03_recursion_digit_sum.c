/*
    ================================================================================
    Tutorial: Recursion - Sum of Digits
    ================================================================================

    This program calculates the sum of the digits of an integer using a very
    elegant recursive solution. This is a great example of thinking about a
    problem in a recursive way.

    The core idea is to recognize that the sum of digits of a number (e.g., 123)
    is equal to `(the last digit) + (the sum of digits of the rest of the number)`.
    sum(123) = 3 + sum(12)
    sum(12)  = 2 + sum(1)
    sum(1)   = 1 + sum(0)

    This pattern leads directly to a recursive solution.

    Concepts Covered:
    - A non-obvious but elegant application of recursion.
    - Using the modulo (%) and division (/) operators to decompose a number.
*/

#include <stdio.h>

int sumOfDigits(int n);

int main(void) {
    int n, sum;
    printf("Enter an integer to sum its digits: ");
    scanf("%d", &n);

    // Let's handle negative numbers gracefully.
    int input_num = n;
    if (n < 0) {
        n = -n; // Work with the positive version for the calculation.
    }

    sum = sumOfDigits(n);

    printf("The sum of the digits of %d is %d.\n", input_num, sum);

    return 0;
}

/*
    Function: sumOfDigits
    Purpose: Recursively calculates the sum of the digits of an integer.
*/
int sumOfDigits(int n) {
    // Base Case: If the number is 0, the sum of its digits is 0.
    // This stops the recursion.
    if (n == 0) {
        return 0;
    }
    // Recursive Step:
    else {
        // Here's the mathematical trick:
        // 1. `n % 10` (modulo 10) gives you the last digit of the number.
        //    (e.g., 123 % 10 is 3)
        // 2. `n / 10` (integer division by 10) effectively removes the last digit.
        //    (e.g., 123 / 10 is 12)

        // We return the last digit PLUS the sum of the digits of the rest of the number.
        return (n % 10) + sumOfDigits(n / 10);
    }
}

/*
    How does sumOfDigits(123) work?
    - It returns 3 + sumOfDigits(12)
      - which returns 2 + sumOfDigits(1)
        - which returns 1 + sumOfDigits(0)
          - which returns 0 (Base Case!)
    The results are then added back up the chain: 1 + 0 = 1 -> 2 + 1 = 3 -> 3 + 3 = 6.
*/
