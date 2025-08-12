/*
    ================================================================================
    Tutorial: Structures - Returning a Struct from a Function
    ================================================================================

    This program introduces a new and powerful concept: functions that return
    an entire `struct`.

    So far, our functions that modify structs have taken a pointer to the original
    struct. An alternative design pattern is to have the function take a `struct`
    by value (as a copy), perform some calculations, and then return a *new*,
    modified `struct`.

    This program defines a `date` struct and a function `advanceDay` that takes
    one date and returns a new `date` struct representing the following day.

    Concepts Covered:
    - Declaring a function that returns a `struct`.
    - Returning a `struct` variable from a function.
    - A practical algorithm for date manipulation.
    - The limitations of the algorithm (e.g., leap years).
*/

#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

// Function Prototypes
void readDate(struct date *date_ptr);
void printDate(struct date d);
struct date advanceDay(struct date d);

int main(void) {
    struct date today, tomorrow;

    printf("Enter today's date (YYYY MM DD): ");
    readDate(&today);

    printf("Today's date is: ");
    printDate(today);

    // The advanceDay function returns a whole new struct, which we assign to 'tomorrow'.
    tomorrow = advanceDay(today);

    printf("Tomorrow's date is: ");
    printDate(tomorrow);

    return 0;
}

void readDate(struct date *date_ptr) {
    scanf("%d %d %d", &date_ptr->year, &date_ptr->month, &date_ptr->day);
}

void printDate(struct date d) {
    // `%02d` is a format specifier that pads a number with a leading zero if
    // it is less than 2 digits wide. Perfect for dates and times.
    printf("%04d/%02d/%02d\n", d.year, d.month, d.day);
}

/*
    Function: advanceDay
    Purpose: Calculates the date of the day after the one provided.
    Note: This is a simplified version that does not account for leap years.
*/
struct date advanceDay(struct date d) {
    struct date next_day;
    // An array to hold the number of days in each month. Index 0 is unused.
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Case 1: It's not the end of the month.
    // We simply increment the day and keep the month and year the same.
    if (d.day < days_in_month[d.month]) {
        next_day.day = d.day + 1;
        next_day.month = d.month;
        next_day.year = d.year;
    }
    // Case 2: It IS the end of the month, but not the end of the year.
    else if (d.month < 12) {
        next_day.day = 1;
        next_day.month = d.month + 1;
        next_day.year = d.year;
    }
    // Case 3: It's December 31st.
    else { // d.month == 12
        next_day.day = 1;
        next_day.month = 1;
        next_day.year = d.year + 1;
    }

    return next_day;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  The current `advanceDay` function doesn't handle leap years (where
        February has 29 days). A year is a leap year if it is divisible by 4,
        unless it is divisible by 100 but not by 400. Can you add this logic?
        You would need to check `d.year` inside the `advanceDay` function and
        adjust `days_in_month[2]` accordingly.
    ================================================================================
*/
