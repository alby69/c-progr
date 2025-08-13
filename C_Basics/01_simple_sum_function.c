/*
    ================================================================================
    Tutorial: C Basics - A Simple Function for Summation
    ================================================================================

    Welcome to your C tutorial! This first exercise covers some of the most
    fundamental concepts in C programming.

    Concepts Covered:
    - The #include directive for using standard libraries.
    - The main() function: the entry point of every C program.
    - Declaring integer variables.
    - Using printf() for output to the console.
    - Using scanf() to read user input.
    - Defining and calling a simple function.
    - The return statement.
*/

// The #include directive tells the compiler to include the contents of a file.
// <stdio.h> is the standard input/output library in C. It provides functions
// like printf() and scanf().
#include <stdio.h>

/*
    This is a user-defined function named 'sum'.
    - It takes two integer arguments, 'x' and 'y'.
    - It returns an integer value, which is the result of their addition.
    - Defining functions like this helps in organizing code and reusing it.
*/
int sum(int x, int y) {
    // The 'return' statement provides the result of the function call.
    return x + y;
}

/*
    The main() function is special. It's where the execution of any C program begins.
    'int' before main indicates that the function returns an integer value.
    'void' in the parentheses means it takes no arguments.
*/
int main(void) {
    // Variable Declaration:
    // We declare two integer variables, 'a' and 'b', to store the numbers
    // provided by the user.
    int a, b;

    // We use printf() to display a message to the user, prompting them for input.
    // The '\n' at the end of a string is an "escape sequence" that represents a newline character.
    printf("Please enter two numbers separated by a space: ");

    // Using scanf() to read input from the user:
    // - The first argument "%d%d" is a format string. It tells scanf() to expect
    //   two integer values.
    // - The following arguments, &a and &b, are the memory addresses of the variables
    //   where the input values should be stored. The '&' is the "address-of" operator.
    scanf("%d%d", &a, &b);

    // Calling our 'sum' function:
    // We pass the user's numbers (a and b) to our sum() function.
    // The returned value is then used as an argument to printf().
    printf("The result of the sum is %d.\n", sum(a, b));

    // The 'return 0;' statement at the end of main() indicates that the program
    // has executed successfully. A non-zero value typically indicates an error.
    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  Can you modify this program to calculate the product of the two numbers
        instead of the sum? You'll need to create a new function called 'product'.
    2.  What happens if the user enters a non-integer value (like "hello")?
        Experiment and see. We'll cover how to handle such errors later.
    3.  Try creating functions for subtraction and division. Remember that division
        with integers might not give you the result you expect if there's a
        remainder!
    ================================================================================
*/
