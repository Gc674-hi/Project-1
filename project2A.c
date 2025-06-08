#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Function Prototypes ---

/**
 * @brief Checks if a given date is valid.
 *
 * This function validates a date (month, day, year). It accounts for the
 * number of days in each month and handles leap years correctly.
 *
 * @param mm The month (1-12).
 * @param dd The day.
 * @param yyyy The year.
 * @return Returns +1 if the date is valid, -1 otherwise.
 */
int CheckDate(int mm, int dd, int yyyy);

// --- Main Program ---

int main(int argc, char *argv[]) {
    // --- Argument Validation ---
    // The program expects at least 4 arguments: ./project2A mm dd yyyy
    // It can also accept more for test case identifiers, which are ignored.
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <month> <day> <year> [Testcase ...]\n", argv[0]);
        return 1; // Indicate an error
    }

    // --- Variable Declaration and Initialization ---
    // Array of month names using a pointer-to-array format
    char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int month, day, year;

    // Convert command line arguments from string to integer
    // atoi returns 0 if the conversion fails. We'll rely on our
    // CheckDate function for more robust validation.
    month = atoi(argv[1]);
    day = atoi(argv[2]);
    year = atoi(argv[3]);

    // --- Date Validation and Output ---
    if (CheckDate(month, day, year) == 1) {
        // If the date is valid, print it in the desired format.
        // The month index is `month - 1` because arrays are 0-indexed.
        printf("%s %d, %d\n", monthNames[month - 1], day, year);
    } else {
        // If the date is invalid, print the specified error message.
        printf("Date entered is invalid - enter a valid date\n");
    }

    return 0; // Indicate successful execution
}

// --- Function Implementations ---

int CheckDate(int mm, int dd, int yyyy) {
    // --- Basic Range Checks ---
    // Check if the month is between 1 and 12.
    // Check if the day is at least 1.
    // Check if the year is non-negative (a reasonable assumption).
    if (mm < 1 || mm > 12 || dd < 1 || yyyy < 0) {
        return -1;
    }

    // --- Days in Month Check ---
    // Array holding the number of days in each month (non-leap year)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // The first element is a dummy value to make the indices match month numbers.

    // --- Leap Year Check ---
    // A year is a leap year if it's divisible by 4, unless it's a century year.
    // Century years must be divisible by 400 to be leap years.
    // Examples: 2000 is a leap year. 1900 is not. 2024 is a leap year.
    if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 400 == 0)) {
        daysInMonth[2] = 29; // It's a leap year, so February has 29 days.
    }

    // Check if the day exceeds the maximum for the given month.
    if (dd > daysInMonth[mm]) {
        return -1;
    }

    // If all checks pass, the date is valid.
    return 1;
}
