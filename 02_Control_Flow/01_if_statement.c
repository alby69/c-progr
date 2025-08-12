/*
    ================================================================================
    Tutorial: Control Flow - The 'if' Statement
    ================================================================================

    This program demonstrates the most fundamental control flow statement: the 'if'
    statement. It allows the program to make decisions and execute different
    code blocks based on a condition.

    This example was recreated to replace a file that was lost due to technical
    issues. It captures the concept of checking a temperature value.

    Concepts Covered:
    - The 'if' statement for conditional execution.
    - Relational operators (e.g., > for "greater than").
    - The 'else' statement for handling the case when the condition is false.
*/

#include <stdio.h>

int main(void) {
    int temperature;

    printf("Enter the current temperature in Celsius: ");
    scanf("%d", &temperature);

    // The 'if' statement checks a condition in the parentheses.
    // If the condition is true, the block of code immediately following it is executed.
    if (temperature > 30) {
        printf("It's hot outside! Stay hydrated.\n");
    }

    // The 'else' statement is optional.
    // Its code block is executed if the 'if' condition is false.
    else {
        printf("It's not too hot. Enjoy the weather!\n");
    }

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Can you add an 'else if' statement to handle more conditions? For example,
        check for temperatures below 10 degrees Celsius and print a message
        saying "It's cold, wear a jacket!".
    2.  What happens if you only have an 'if' without an 'else'? Try removing the
        'else' block and see how the program behaves for different temperatures.
    ================================================================================
*/
