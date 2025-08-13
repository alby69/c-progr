/*
    ================================================================================
    Tutorial: C Basics - A Simple Unit Converter
    ================================================================================

    This program is a simple unit converter that brings together many of the
    concepts we've learned so far. It converts meters to feet, grams to pounds,
    and Celsius to Fahrenheit.

    This is a great example of a complete, small program.

    Concepts Covered:
    - Function prototyping (declaring functions before they are defined).
    - Breaking a problem down into smaller functions.
    - Using a loop to process multiple conversions.
    - Conditional logic with 'if-else if-else'.
    - The 'switch' statement for multi-way branching.
    - Using 'const' for defining constants.
*/

#include <stdio.h>

// Function Prototypes:
// These lines tell the main function about the functions we plan to use later.
// This is necessary because we define them *after* main(), but we call them
// *inside* main(). A prototype specifies the function's return type, name,
// and the types of its arguments.
double perform_conversion(double value, char input_unit);

int main(void) {
    int num_conversions = 0;
    double input_value = 0.0;
    double output_value = 0.0;
    char input_unit_char; // e.g., 'm', 'g', 'c'

    printf("How many conversions would you like to perform? ");
    scanf("%d", &num_conversions);

    for (int i = 0; i < num_conversions; i++) {
        printf("\nEnter the value and unit (m, g, or c) for conversion #%d: ", i + 1);
        scanf("%lf %c", &input_value, &input_unit_char);

        // We call our conversion function to get the result.
        output_value = perform_conversion(input_value, input_unit_char);

        // Check if the conversion was successful. Our function returns a special
        // value (-1.0 in this case, a simple error handling method) to indicate
        // an invalid unit was entered.
        if (output_value == -1.0) {
            printf("Error: Invalid unit '%c'. Please use 'm', 'g', or 'c'.\n", input_unit_char);
        } else {
            // Here we use a 'switch' statement to print the correct unit label.
            // A switch is often cleaner than a long if-else-if chain when you are
            // checking a single variable against multiple constant values.
            printf("Result: %.6lf ", output_value);
            switch (input_unit_char) {
                case 'm':
                    printf("ft\n");
                    break; // The 'break' is important! It exits the switch.
                case 'g':
                    printf("lbs\n");
                    break;
                case 'c':
                    printf("F\n");
                    break;
            }
        }
    }

    return 0;
}

/*
    This function contains the logic for the conversions.
    It takes the value and the input unit character.
    It returns the converted value, or -1.0 if the unit is invalid.
*/
double perform_conversion(double value, char input_unit) {
    // Using 'const' declares a variable whose value cannot be changed.
    // This is good practice for conversion factors and other magic numbers.
    const double METERS_TO_FEET = 3.2808;
    const double GRAMS_TO_POUNDS = 0.002205;

    double result = 0.0;

    switch (input_unit) {
        case 'm': // meters to feet
            result = value * METERS_TO_FEET;
            break;
        case 'g': // grams to pounds
            result = value * GRAMS_TO_POUNDS;
            break;
        case 'c': // Celsius to Fahrenheit
            // The formula is: F = (C * 9/5) + 32.  1.8 is the same as 9/5.
            result = 32.0 + (1.8 * value);
            break;
        default: // Handle invalid units
            result = -1.0; // Use a special value to signal an error
            break;
    }

    return result;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Add more conversions! For example, add a case for converting from
        kilograms ('k') to pounds. You'll need to add it to the switch
        statement and provide the correct conversion factor.
    2.  This program only converts from metric to imperial. Can you add the
        reverse conversions? You might need to add new character codes (e.g., 'f'
        for feet) and expand the logic to handle them.
    ================================================================================
*/
