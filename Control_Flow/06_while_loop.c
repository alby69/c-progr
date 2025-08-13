/*
    ================================================================================
    Tutorial: Control Flow - The 'while' Loop
    ================================================================================

    This program calculates the total power of a fleet of robots based on their
    attributes. It's a great example of reading and processing multiple,
    more complex lines of input.

    The original code used a 'for' loop. We have refactored it to use a 'while'
    loop to demonstrate an alternative looping structure.

    Concepts Covered:
    - The 'while' loop.
    - The difference between 'for' and 'while' loops.
    - Reading multiple values from a single line of input.
    - Performing a calculation within a loop to accumulate a total.
*/

#include <stdio.h>

int main(void) {
    int num_robots = 0;
    int height, weight, engine_power, resistance;
    int total_fleet_power = 0;
    int i = 0; // It's common to initialize the counter *before* a while loop.

    printf("How many robots are in the fleet? ");
    scanf("%d", &num_robots);

    printf("Enter the stats for each robot (height weight power resistance):\n");

    // The 'while' loop:
    // A 'while' loop is simpler than a 'for' loop. It only has one part: the
    // condition. It will continue to execute its block as long as the condition
    // is true. It's up to us to manage the counter variable inside the loop.
    while (i < num_robots) {
        printf("Robot #%d: ", i + 1);
        scanf("%d %d %d %d", &height, &weight, &engine_power, &resistance);

        // Calculate the power for the current robot
        int single_robot_power = (engine_power + resistance) * (weight - height);

        // Add it to the fleet's total power
        total_fleet_power += single_robot_power;

        // Manual Increment:
        // We must remember to increment our counter variable 'i' at the end
        // of the loop. If we forget this, `i < num_robots` will always be true,
        // and we will have an infinite loop!
        i++;
    }

    printf("The total power of the robot fleet is: %d\n", total_fleet_power);

    return 0;
}

/*
    ================================================================================
    When to use 'for' vs. 'while'?

    - 'for' loop: Best when you know exactly how many times you want to loop
      (e.g., iterating from 0 to 'n', looping through an array). The initialization,
      condition, and increment are all neatly packaged in one line. This is the
      most common type of loop.

    - 'while' loop: Best when you want to loop as long as a certain condition
      is true, but you don't necessarily know how many iterations it will take.
      (e.g., "keep looping until the user enters -1", or "keep looping while
      the file has more data").

    In this specific example, a 'for' loop is arguably a better fit because we
    know the exact number of iterations from the start (`num_robots`). However,
    it's important to understand how to accomplish the same task with a 'while' loop.
    ================================================================================
*/
