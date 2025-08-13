/*
    ================================================================================
    Tutorial: Arrays - A Practical Example with Doubles
    ================================================================================

    This program demonstrates a practical use of arrays. It performs two "passes"
    over the data. First, it reads a set of weights into an array of doubles and
    calculates their sum. Second, after calculating the average, it iterates over
    the array again to show how much each individual weight needs to be adjusted
    to match the average.

    This two-pass approach is very common in data processing and highlights why
    we need arrays: we need to store all the values first before we can calculate
    the average and compare each value against it.

    Concepts Covered:
    - Declaring an array of `double`s.
    - Using a variable to define the number of elements to use in an array.
    - Performing multiple passes over array data.
*/

#include <stdio.h>

int main(void) {
    // We declare an array with a maximum capacity of 50.
    // This means the program can handle *up to* 50 cars, but not more.
    double car_weights[50];
    int num_cars = 0;
    double total_weight = 0.0;
    double average_weight = 0.0;

    printf("How many cars are there (up to 50)? ");
    scanf("%d", &num_cars);

    // It's good practice to check if the user's input is within our array's capacity.
    if (num_cars > 50 || num_cars <= 0) {
        printf("Error: Invalid number of cars. Please enter a number between 1 and 50.\n");
        return 1; // Exit the program with an error code.
    }

    // First Pass: Read weights and calculate the sum.
    printf("Enter the weight for each of the %d cars:\n", num_cars);
    for (int i = 0; i < num_cars; i++) {
        printf("Car #%d weight: ", i + 1);
        scanf("%lf", &car_weights[i]);
        total_weight += car_weights[i];
    }

    // Calculate the average.
    average_weight = total_weight / num_cars;
    printf("\nThe average weight of the cars is: %.2lf\n", average_weight);

    // Second Pass: Calculate and print the difference from the average for each car.
    printf("Weight adjustment needed for each car to reach the average:\n");
    for (int i = 0; i < num_cars; i++) {
        double difference = average_weight - car_weights[i];
        // The '%.1lf' format specifier prints the double with 1 decimal place.
        // A positive number means the car is lighter than average and needs weight added.
        // A negative number means the car is heavier and needs weight removed.
        printf("Car #%d: %.1lf\n", i + 1, difference);
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Can you find the car with the heaviest weight and the car with the
        lightest weight? You would do this by iterating through the array after
        it's populated, keeping track of the `max_weight_so_far` and
        `min_weight_so_far`.
    2.  What if you wanted to store the name (a string) of each car along with its
        weight? This would require a more advanced data structure, like two
        separate arrays (one for weights, one for names) or an array of `structs`,
        which we will cover later in the tutorial.
    ================================================================================
*/
