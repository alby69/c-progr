# A Beginner's Guide to C
### A Tutorial Generated from Your Exercises

---

## Table of Contents

### 01: C Basics
- [A Simple Function for Summation](./01_C_Basics/01_simple_sum_function.c)
- [Integer Division and the Modulo Operator](./01_C_Basics/02_division_and_remainder.c)
- [Reading Multiple Inputs with a Loop](./01_C_Basics/03_user_input.c)
- [Type Casting for Accurate Division](./01_C_Basics/04_type_casting.c)
- [The 'char' Data Type](./01_C_Basics/05_character_output.c)
- [Nested Loops](./01_C_Basics/06_random_numbers.c)
- [A Simple Unit Converter](./01_C_Basics/07_unit_converter_example.c)

### 02: Control Flow
- [The 'if' Statement](./02_Control_Flow/01_if_statement.c)
- [Logical Operators and a Bug Fix](./02_Control_Flow/02_dice_game_with_tax.c)
- [Tug of War](./02_Control_Flow/03_tug_of_war_game.c)
- [Simplifying with 'else if'](./02_Control_Flow/04_complex_if_else.c)
- [Decisions Based on String Length](./02_Control_Flow/05_if_on_string_length.c)
- [The 'while' Loop](./02_Control_Flow/06_while_loop.c)

### 03: Functions
- [Decomposition and Reusability](./03_Functions/01_simple_functions.c)
- [Pass-by-Value vs. Pass-by-Reference](./03_Functions/02_pass_by_reference.c)

### 04: Arrays
- [Storing and Accessing Data](./04_Arrays/01_integer_array.c)
- [A Practical Example with Doubles](./04_Arrays/02_double_array.c)
- [Finding Maximum and Minimum Values](./04_Arrays/03_array_max_min.c)
- [Passing Arrays to Functions](./04_Arrays/05_passing_arrays_to_functions.c)
- [Reversing an Array](./04_Arrays/06_reversing_an_array.c)

### 05: Pointers
- [The Absolute Basics](./05_Pointers/01_pointer_basics.c)
- [Dereferencing ("Going to the Address")](./05_Pointers/02_pointer_dereferencing.c)
- [Modifying Variables via Functions](./05_Pointers/03_modifying_with_pointers.c)
- [Pointer Arithmetic](./05_Pointers/04_pointer_arithmetic.c)
- [The Classic Swap Function](./05_Pointers/05_pointer_swap.c)
- [Pointers to Pointers (Double Pointers)](./05_Pointers/06_pointers_to_pointers.c)

### 06: Strings
- [Finding the Longest Word](./06_Strings/01_longest_word.c)
- [Searching for a Character](./06_Strings/02_search_letter.c)
- [Comparing Strings Alphabetically](./06_Strings/03_sort_strings.c)
- [Word Length Frequency Counter](./06_Strings/04_word_lengths_frequency.c)
- [Pointers and String Literals](./06_Strings/05_string_concatenation.c)

### 07: Algorithms
- [Linear Search](./07_Algorithms/01_linear_search.c)
- [Binary Search (Bisection Search)](./07_Algorithms/02_bisection_search.c)
- [Bubble Sort](./07_Algorithms/03_bubble_sort.c)
- [Finding the Minimum Value (Streaming)](./07_Algorithms/04_find_smallest_integer.c)
- [Counting Duplicate Characters](./07_Algorithms/05_sort_and_search_letters.c)

### 08: Recursion
- [Factorial Example](./08_Recursion/01_factorial_iterative_vs_recursive.c)
- [Fibonacci Numbers](./08_Recursion/02_fibonacci.c)
- [Sum of Digits](./08_Recursion/03_recursion_digit_sum.c)

### 09: Memory Management
- [The `sizeof` Operator](./09_Memory_Management/01_memory_sizeof.c)
- [Dynamic Memory Allocation](./09_Memory_Management/03_dynamic_string_allocation.c)

### 10: Structures
- [Defining Your Own Data Types](./10_Structures/01_defining_structures.c)
- [Populating Structs with User Input](./10_Structures/02_accessing_structure_members.c)
- [Structs and Memory Layout (Padding)](./10_Structures/03_structure_size_in_memory.c)
- [Structs and Functions (Pass-by-Value vs. Pass-by-Pointer)](./10_Structures/04_creating_structures_from_input.c)
- [Arrays of Structs](./10_Structures/05_array_of_structures.c)
- [Returning a Struct from a Function](./10_Structures/09_manipulating_structures_with_functions.c)
- [Dynamic Allocation of Structs](./10_Structures/10_allocating_memory_for_structures.c)

---

\newpage

## 01: C Basics

### `01_simple_sum_function.c`
```c
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
```

... (the rest of the very long file, with `\newpage` before each `## 0X:` heading) ...
