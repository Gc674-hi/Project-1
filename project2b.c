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
    // The program expects at least 4 arguments: ./project2B Month dd yyyy
    // It can also accept more for test case identifiers, which are ignored.
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <Month> <day> <year> [Testcase ...]\n", argv[0]);
        return 1; // Indicate an error
    }

    // --- Variable Declaration and Initialization ---
    // Array of month names using a pointer-to-pointer format
    char **monthNames;
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December", NULL
    };
    monthNames = months;


    char *inputMonthStr = argv[1];
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);
    int month = 0; // Initialize month to an invalid value (0)

    // --- Month String to Integer Conversion ---
    // Loop through the month names to find a match.
    for (int i = 0; monthNames[i] != NULL; i++) {
        // strcmp returns 0 if the strings are identical.
        if (strcmp(inputMonthStr, monthNames[i]) == 0) {
            month = i + 1; // Month number is index + 1
            break; // Exit the loop once a match is found
        }
    }

    // --- Date Validation and Output ---
    // First, check if the month string was found.
    // Then, call CheckDate with the converted values.
    if (month != 0 && CheckDate(month, day, year) == 1) {
        // If the date is valid, print it in the desired format.
        printf("%d %d %d\n", month, day, year);
    } else {
        // If the month name was wrong or the date is invalid,
        // print the specified error message.
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
