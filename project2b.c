/*Outside Code Documentation
 * (i) Worked in a group. Group Member(s): Kahan Patel 14638615, Gary Chen 14600255.
 * (ii) This project is the work of the developer(s) listed above. No assistance was received from unauthorized persons other than those mentioned above.
 * (iii) No AI tools were used in the development of this code.
 * (iv) Kahan Patel: Code Development & Testing & Documentation | Gary Chen: Code Development & Testing & Documentation
 * Signed: Kahan Patel, Gary Chen
 *
 * (v) This program converts calender information from numberic format to written/verbal format. The program incorporates the usage of command-line arguments and basic error detection for more responsive UI experience.
 * (vi) The following C features and libraries were used in this project:
 * - Standard I/O library for input and output operations (Ch. 2 & 3) (printf (3.1))
 * - Mathematical operations (Ch. 4) (Arithmetic Operators (4.1), Assignment Operators (4.2), Increment and Decrement Operators (4.3))
 * - (4.3), Expressions (4.4 & 4.5))
 * - Functions for modular code organization (Ch. 9) (Defining/Call Functions (9.1), Function Declarations (9.2), Arguments (9.3), Return Values (9.4))
 * - Constants for standard deductions and tax brackets
 * - Conditional statements for filing status and tax bracket selection (Ch. 5) (Logical Expressions (5.1), If-Else Statements (5.2), Switch Statements 
 * (5.3))
 * - Loops for input validation (Ch. 6) (For Loops (6.3), Exiting Loops (6.4))
 * - Basic data types (int, double) for variable declarations (Ch. 7) (Integers (7.1), Variable Declarations (7.2), Type Definitions (7.5))
 * - Program Organization (Ch. 10) (Local Variables (10.1), External Variables (10.2), Block Statements (10.3), Scope of Variables (10.4))
 * - Pointers for passing variables to functions (Ch. 11) (Pointers (11.1), Pointer Addressing (11.2), Pointer Assignment (11.3), Pointer as Argument 
 * (11.4))
 * - Strings for UI prompts (Ch.13) (String Literals (13.1), String Variables (13.2), Reading and Writing Strings (13.3), C string library (13.5), Array of Strings (13.7))
 * - Advance use of Pointers (Ch. 17)
 * (vii) The code uses the following chapeters listed above to create a program that can take user input via the command line and convert the input into written/verbal format of the calendar information. The program passes all test cases given in the program instructions. Edge-case testing was also done to ensure the program is robust and handles invalid inputs gracefully. The program is modular and uses functions to validate the date input, ensuring that it is a valid date before converting it to the written format. The program also handles leap years correctly.
 * (viii) The code was tested using the provided test cases and the conversions were also done by hand to validate of a given date was valid. After doing both the results of the program was then compared to the hand calculation. Since the results were identical, it verified the results of the program. Moreover, all the other test cases were also complied and tested. All test cases gave valid results. Thus, proving the validity of the program. Screenshots of the results and tests are provided in the assignment submission.
 * (ix) Instructions for running the program:
 * 1. Download project2B.c file
 * 2. Install a C compiler (e.g., GCC)
 * 3. Open a terminal or command prompt
 * 4. Navigate to the directory where project2B.c is located
 * 5. Compile the program using the command: gcc project2B.c -o project2B or clang project2B.c -o project2B (depending on your compiler)
 * 6. Run the program using the command: ./project2B <Month> <day> <year>
 * For example: ./project2B January 31 2023
 *
 * (x) Man hours spent Kahan Patel: 3 hours, Gary Chen: 3 hours
 * */

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

int main(int argc, char *argv[]) 
{
    if (argc < 4) 
    {
        fprintf(stderr, "Usage: %s <Month> <day> <year> [Testcase ...]\n", argv[0]);
        return 1; 
    }

    char **monthNames;
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December", NULL
    };

    monthNames = months;

    char *inputMonthStr = argv[1];
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);
    int month = 0; 

    for (int i = 0; monthNames[i] != NULL; i++) 
    {
        if (strcmp(inputMonthStr, monthNames[i]) == 0) 
        {
            month = i + 1; 
            break; 
        }
    }
 
    if (month != 0 && CheckDate(month, day, year) == 1) 
    {
        printf("%d %d %d\n", month, day, year);
    } 
    else 
    {
        printf("Date entered is invalid - enter a valid date\n");
    }

    return 0; 
}

int CheckDate(int mm, int dd, int yyyy) {
    
    if (mm < 1 || mm > 12 || dd < 1 || yyyy < 0) 
    {
        return -1;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     
    if ((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 400 == 0)) 
    {
        daysInMonth[2] = 29; 
    }
 
    if (dd > daysInMonth[mm]) 
    {
        return -1;
    }

    return 1;
}
