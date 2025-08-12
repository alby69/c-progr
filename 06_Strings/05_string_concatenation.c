/*
    ================================================================================
    Tutorial: Strings - Pointers and String Literals
    ================================================================================

    This program determines the name of a fictional tree based on its height
    and number of leaflets.

    While the filename mentions concatenation, this program's core concept is
    actually about **character pointers** and **string literals**.

    A "string literal" is a sequence of characters enclosed in double quotes,
    like "hello world". When you write this in your code, the compiler stores
    this string in a special, often read-only, part of the program's memory.

    Concepts Covered:
    - Character pointers (`char *`).
    - String literals.
    - Assigning the address of a string literal to a character pointer.
    - Using `if-else if` to implement a set of rules.
*/

#include <stdio.h>

int main(void) {
    int height = 0;
    int leaflets = 0;

    // Here, `tree_name` is a POINTER to a character.
    // We initialize it to point to the beginning of the string literal "uncertain".
    // This doesn't copy the string; it just stores the memory address of the 'u'.
    char *tree_name = "uncertain";

    printf("Enter the tree's height: ");
    scanf("%d", &height);
    printf("Enter the number of leaflets: ");
    scanf("%d", &leaflets);

    // The following `if-else if` chain checks the rules.
    // If a rule matches, we simply change the `tree_name` pointer to point to
    // a *different* string literal. No strings are being copied or modified.
    if (height <= 5 && leaflets >= 8) {
        tree_name = "Tinuviel";
    } else if (height >= 10 && leaflets >= 10) {
        tree_name = "Calaelen";
    } else if (height <= 8 && leaflets <= 5) {
        tree_name = "Falarion";
    } else if (height >= 12 && leaflets <= 7) {
        tree_name = "Dorthonion";
    }
    // If none of the conditions match, `tree_name` keeps its original value, "uncertain".

    // The `%s` format specifier tells printf to go to the address stored in
    // `tree_name` and print characters until it finds a null terminator.
    printf("The tree's name is: %s\n", tree_name);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  What is the difference between `char *name = "My Name";` and
        `char name[] = "My Name";`? This is a crucial and classic C question.
        - `char *name` creates a pointer to a read-only string literal. You
          can re-point `name` to something else, but you should NOT try to
          modify the content (e.g., `name[0] = 'm';` is undefined behavior).
        - `char name[]` creates an ARRAY and initializes it by copying the
          string literal into it. The array is writable, so you CAN modify
          its contents. However, you cannot re-point `name` itself to a
          different string.
    ================================================================================
*/
