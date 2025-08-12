/*
    ================================================================================
    Tutorial: Control Flow - Nested Loops
    ================================================================================

    This program simulates a game with multiple players (or "throws") where each
    player rolls multiple dice. It's a perfect example of a "nested loop",
    which is one loop inside another.

    The filename `06_random_numbers.c` is a bit of a misnomer, as this program
    doesn't generate *random* numbers. Instead, it reads a series of dice values
    that you provide as input. Later in the tutorial, we'll see how to generate
    truly random numbers.

    Concepts Covered:
    - Nested 'for' loops.
    - Resetting an accumulator variable for an inner loop.
    - Simulating a 2D problem (throws and dice) with loops.
*/

#include <stdio.h>

int main(void) {
    int num_throws = 0; // The number of players or turns in the game (the "outer" loop).
    int num_dice = 0;   // The number of dice each player rolls (the "inner" loop).
    int dice_value = 0; // The value of a single die, read from input.
    int throw_sum = 0;  // The sum of dice values for the current player's turn.

    printf("Enter the number of throws and the number of dice per throw: ");
    scanf("%d %d", &num_throws, &num_dice);

    // Outer Loop: Iterates once for each player/throw.
    // 'throw_idx' is the index for the current throw, from 0 to num_throws-1.
    for (int throw_idx = 0; throw_idx < num_throws; throw_idx++) {

        // Inner Loop: Iterates once for each die within a single throw.
        // 'dice_idx' is the index for the current die, from 0 to num_dice-1.
        printf("\nEnter the %d dice values for throw #%d: ", num_dice, throw_idx + 1);
        for (int dice_idx = 0; dice_idx < num_dice; dice_idx++) {
            scanf("%d", &dice_value);
            throw_sum += dice_value; // Add the die's value to the sum for this throw.
        }

        // This printf is inside the outer loop but *after* the inner loop has finished.
        // This means it runs once per throw, after all dice for that throw are summed up.
        printf("Throw %d sum equals %d\n", throw_idx + 1, throw_sum);

        // Resetting the accumulator:
        // It's crucial to reset the sum to 0 after each throw. If we didn't,
        // the sum for the second throw would start with the total from the first,
        // which is not what we want.
        throw_sum = 0;
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What would happen if you moved the `throw_sum = 0;` line to the very
        beginning of the program, before the outer loop? The program would
        calculate a grand total of all dice rolls instead of a per-throw sum.
    2.  Can you modify this program to find the highest single die roll within
        each throw? You'd need another variable, `highest_roll_this_throw`, and
        an 'if' statement inside the inner loop. Remember to reset it in the
        outer loop!
    ================================================================================

    Example Input to Copy/Paste:
    (First line is for the first scanf, the rest are for the loops)

    5 4
    1 4 2 3
    3 2 6 4
    2 4 1 4
    2 2 1 4
    3 6 1 2
*/
