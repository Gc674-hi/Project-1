/*
 *   (i) Worked in a group. Group Member(s): Kahan Patel 14638615, Gary Chen 14600255
 *   (ii) This project is the work of the developer(s) listed above. No assistance was received from unauthorized persons.
 *   (iii) No AI tools were used in the development of this code.
 *   (iv) Kahan Patel: Code Development & Testing & Documentation | Gary Chen: Code Development & Testing & Documentation
 *   Signed: Kahan Patel, Gary Chen
 *
 *   (v) This program calculates the estimated tax payable for the year 2025 based on user inputs.
 *       It includes filing status selection, income input, and tax calculation using the 2025 tax brackets.
 *       The program is designed to be user-friendly and provides clear output of the tax calculations.
 *       The tax calculation follows the Qualified Dividends and Capital Gain Tax Worksheet for 2025.
 *   (vi) The following C features & libraries were used:
 *        - Standard I/O library for input/output operations (Ch. 2 & 3) (Printf (3.1), Scanf (3.2))
 *        - Math library for mathematical operations (e.g., fmax) (Ch. 4) (Arithmetic Operators (4.1), Assignment Operators (4.2), Increment/Decrement Operators 
 *        (4.3), Expressions (4.4 & 4.5))
 *        - Functions for modular code organization (Ch. 9) (Defining/Call Functions (9.1), Function Declarations (9.2), Arguments (9.3), Return Values (9.4))
 *        - Constants for standard deductions and tax brackets
 *        - Conditional statements for filing status and tax bracket selection (Ch. 5) (Logical Expressions (5.1), If-Else Statements (5.2), Switch Statements 
 *        (5.3))
 *        - Loops for input validation (Ch. 6) (While Loops (6.1), For Loops (6.3), Exiting Loops (6.4))
 *        - Basic data types (int, double) for variable declarations (Ch. 7) (Integers (7.1), Variable Declarations (7.2), Type Definitions (7.5))
 *        - Program Organization (Ch. 10) (Local Variables (10.1), External Variables (10.2), Block Statements (10.3), Scope of Variables (10.4))
 *        - Pointers for passing variables to functions (Ch. 11) (Pointers (11.1), Pointer Addressing (11.2), Pointer Assignment (11.3), Pointer as Argument 
 *        (11.4))
 *        - Strings for UI prompts (Ch.13) (String Literals (13.1))
 *   (vii)  The code uses the following chapters listed above to create a program that can take user input and calculate the tax based on the 2025 tax brackets.
 *          The program passes all test cases given in the program instructions. Edge-case testing was also done handle user-inputs that are not valid. The program
 *          responds dynamically to user inputs and provides the correct tax calculation based on the 2025 tax brackets. The program is modular and organized,
 *          making it easy to read and maintain.
 *   (viii) The code was tested via hand calculation. The first testcase was done by hand the answer was verified via the answer provided by professor. The result
 *          of the program was then compared to the hand calculation. Since the results were identical, it verified the results of the program. Moreover, since the
 *          tax calculation for 2025 follows at set algorithm, each case is implicitly verified by the algorithm itself. A screenshot of both the hand written
 *          result and program output is provided in the project submission.
 *   (ix)   Instructions for running the program:
 *          1. Compile main.c using a C compiler (e.g., gcc) (gcc -o main main.c). Note* if you experience a linker error include the the -lm flag during
 *          the compilation (gcc -o main main.c -lm).
 *          2. Run the compiled program (./main).
 *          3. The program will display a menu for selecting the filing status. Naviation is handled via keyboard inputs (1-4).
 *          4. Enter the income details as prompted. (double)
 *          5. The program will calculate and display the estimated tax payable based on the 2025 tax brackets.
 *          * The program has basic error handling for invalid inputs. If an invalid input is detected, the program will prompt the user to re-enter the value.
 *          If the user enters a non-integer value for the filing status, the program will clear the input buffer and prompt again. If nonvalid inputs are entered
 *          during income input, the program will give NULL values/0.0 for the income.
 *   (x)    Man Hours Spent: Kahan Patel: 6 hours, Gary Chen: 5 hours
 *
 * */

#include <stdio.h>
#include <math.h> // For fmax

// Define constants for filing status choices
#define SINGLE 1
#define HEAD_OF_HOUSEHOLD 2
#define MARRIED_JOINTLY 3
#define MARRIED_SEPARATELY 4

// --- 2025 Standard Deductions ---
#define DEDUCTION_SINGLE 15000.0
#define DEDUCTION_HOH 22500.0
#define DEDUCTION_MARRIED_JOINTLY 30000.0
#define DEDUCTION_MARRIED_SEPARATELY 15000.0

// --- 2025 Regular Tax Brackets ---

// --- 2025 Qualified Dividends and Capital Gains Tax Brackets (Worksheet Lines 6 & 13) ---
// Line 6 Thresholds (End of 0% bracket)
#define L6_THRESH_SINGLE_SEP 48475.0 
#define L6_THRESH_HOH 64850.0
#define L6_THRESH_MARRIED_JOINTLY 96950.0

// Line 13 Thresholds (End of 15% bracket)
#define L13_THRESH_SINGLE 533400.0
#define L13_THRESH_HOH 566700.0
#define L13_THRESH_MARRIED_JOINTLY 600050.0
#define L13_THRESH_MARRIED_SEP 300000.0

// --- Function Prototypes ---

// Input Functions
int get_filing_status();
void get_income(double *salary, double *interest, double *rent, double *dividend, double *capital_gain);

// Calculation Functions
double get_standard_deduction(int status);
double calculate_regular_tax(double taxable_income, int status);
double min_double(double a, double b);

// Main Calculation Logic (Worksheet)
void calculate_tax_worksheet(int status, double salary, double interest, double rent, double dividend, double capital_gain);

// Output Function
void print_results(double l18, double l21, double l22, double l23, double l24, double l25);


// --- Main Program ---
int main() {
    printf("--------------------------------------------------\n");
    printf(" ECEC-201 Term Project 1: 2025 Tax Calculator\n");
    printf("--------------------------------------------------\n");
    printf("Developer(s): Kahan Patel & Gary Chen\n");
    printf("Student ID(s): 14638615, 14600255\n");
    printf("\n");
    printf("Declaration:\n");
    printf("This project is exclusively the work of the developer(s) listed above.\n");
    printf("No assistance was received from unauthorized persons.\n");
    printf("No AI tools were used in the development of this code.\n");
    printf("Signed: Kahan Patel, Gary Chen\n");
    printf("--------------------------------------------------\n\n");


    int status;
    double salary, interest, rent, dividend, capital_gain;

    // Get inputs from the user
    status = get_filing_status();
    get_income(&salary, &interest, &rent, &dividend, &capital_gain);

    // Perform the tax calculation using the worksheet logic
    calculate_tax_worksheet(status, salary, interest, rent, dividend, capital_gain);

    return 0; // Indicate successful execution
}

// --- Function Definitions ---

/**
 * @brief Prompts the user to enter their filing status and validates the input.
 * @return The integer code representing the filing status.
 */
int get_filing_status() {
    int choice = 0;
    printf("Select Filing Status:\n");
    printf("  1. Single\n");
    printf("  2. Head of Household\n");
    printf("  3. Married Filing Jointly\n");
    printf("  4. Married Filing Separately\n");

    while (choice < 1 || choice > 4) {
        printf("Enter status (1-4): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n');
        }
    }
    return choice;
}

/**
 * @brief Prompts the user to enter different income amounts.
 * @param salary Pointer to store the salary income.
 * @param interest Pointer to store the interest income.
 * @param rent Pointer to store the rental income.
 * @param dividend Pointer to store the dividend income.
 * @param capital_gain Pointer to store the capital gain income.
 */
void get_income(double *salary, double *interest, double *rent, double *dividend, double *capital_gain) {
    printf("\nEnter Income Details:\n");
    printf("  Salary: ");
    scanf("%lf", salary);
    printf("  Interest: ");
    scanf("%lf", interest);
    printf("  Rent: ");
    scanf("%lf", rent);
    printf("  Dividends: ");
    scanf("%lf", dividend);
    printf("  Capital Gains: ");
    scanf("%lf", capital_gain);
    printf("\n"); // Add a newline for better formatting
}

/**
 * @brief Determines the standard deduction amount based on the filing status.
 * @param status The filing status code.
 * @return The standard deduction amount.
 */
double get_standard_deduction(int status) {
    switch (status) {
        case SINGLE:             return DEDUCTION_SINGLE;
        case HEAD_OF_HOUSEHOLD:  return DEDUCTION_HOH;
        case MARRIED_JOINTLY:    return DEDUCTION_MARRIED_JOINTLY;
        case MARRIED_SEPARATELY: return DEDUCTION_MARRIED_SEPARATELY;
        default:                 return 0.0; // Should not happen
    }
}

/**
 * @brief Calculates the regular income tax based on the 2025 tax brackets.
 * This function implements the tax tables provided in the PDF.
 * @param taxable_income The income amount subject to regular tax rates.
 * @param status The filing status code.
 * @return The calculated regular income tax.
 */
double calculate_regular_tax(double taxable_income, int status) {
    // Ensure income is not negative
    taxable_income = fmax(0.0, taxable_income);

    double tax = 0.0;
    double base_tax = 0.0;
    double rate = 0.0;
    double bracket_floor = 0.0;

    // Select the correct tax table based on filing status
    switch (status) {
        case SINGLE:
            // Single Tax Brackets 2025
            if (taxable_income <= 11925)      { base_tax = 0.0;       rate = 0.10; bracket_floor = 0.0; }
            else if (taxable_income <= 48475) { base_tax = 1192.50;   rate = 0.12; bracket_floor = 11925.0; }
            else if (taxable_income <= 103350){ base_tax = 5578.50;   rate = 0.22; bracket_floor = 48475.0; }
            else if (taxable_income <= 197300){ base_tax = 17651.00;  rate = 0.24; bracket_floor = 103350.0; }
            else if (taxable_income <= 250525){ base_tax = 40199.00;  rate = 0.32; bracket_floor = 197300.0; }
            else if (taxable_income <= 626350){ base_tax = 57231.00;  rate = 0.35; bracket_floor = 250525.0; }
            else                              { base_tax = 188769.75; rate = 0.37; bracket_floor = 626350.0; }
            break;

        case HEAD_OF_HOUSEHOLD:
            // Head of Household Tax Brackets 2025
            if (taxable_income <= 17000)      { base_tax = 0.0;       rate = 0.10; bracket_floor = 0.0; }
            else if (taxable_income <= 64850) { base_tax = 1700.00;   rate = 0.12; bracket_floor = 17000.0; }
            else if (taxable_income <= 103350){ base_tax = 7442.00;   rate = 0.22; bracket_floor = 64850.0; }
            else if (taxable_income <= 197300){ base_tax = 15912.00;  rate = 0.24; bracket_floor = 103350.0; }
            else if (taxable_income <= 250500){ base_tax = 38460.00;  rate = 0.32; bracket_floor = 197300.0; }
            else if (taxable_income <= 626350){ base_tax = 55484.00;  rate = 0.35; bracket_floor = 250500.0; }
            else                              { base_tax = 187031.50; rate = 0.37; bracket_floor = 626350.0; }
            break;

        case MARRIED_JOINTLY:
            // Married Filing Jointly Tax Brackets 2025
            if (taxable_income <= 23850)      { base_tax = 0.0;        rate = 0.10; bracket_floor = 0.0; }
            else if (taxable_income <= 96950) { base_tax = 2385.00;    rate = 0.12; bracket_floor = 23850.0; }
            else if (taxable_income <= 206700){ base_tax = 11157.00;   rate = 0.22; bracket_floor = 96950.0; }
            else if (taxable_income <= 394600){ base_tax = 35302.00;   rate = 0.24; bracket_floor = 206700.0; }
            else if (taxable_income <= 501050){ base_tax = 80398.00;   rate = 0.32; bracket_floor = 394600.0; }
            else if (taxable_income <= 751600){ base_tax = 114462.00;  rate = 0.35; bracket_floor = 501050.0; }
            else                              { base_tax = 202154.50;  rate = 0.37; bracket_floor = 751600.0; }
            break;

        case MARRIED_SEPARATELY:
            // Married Filing Separately Tax Brackets 2025
            if (taxable_income <= 11925)      { base_tax = 0.0;        rate = 0.10; bracket_floor = 0.0; }
            else if (taxable_income <= 48475) { base_tax = 1192.50;    rate = 0.12; bracket_floor = 11925.0; }
            else if (taxable_income <= 103350){ base_tax = 5578.50;    rate = 0.22; bracket_floor = 48475.0; }
            else if (taxable_income <= 197300){ base_tax = 17651.00;   rate = 0.24; bracket_floor = 103350.0; }
            else if (taxable_income <= 250525){ base_tax = 40199.00;   rate = 0.32; bracket_floor = 197300.0; }
            else if (taxable_income <= 375800){ base_tax = 57231.00;   rate = 0.35; bracket_floor = 250525.0; }
            else                              { base_tax = 101077.25;  rate = 0.37; bracket_floor = 375800.0; }
            break;
    }

    // Calculate tax: base amount + rate * (income over bracket floor)
    tax = base_tax + rate * (taxable_income - bracket_floor);

    return tax;
}


/**
 * @brief Returns the smaller of two double values.
 * @param a First double.
 * @param b Second double.
 * @return The smaller of a and b.
 */
double min_double(double a, double b) {
    return (a < b) ? a : b;
}

/**
 * @brief Implements the logic from the 2025 Qualified Dividends and Capital Gain Tax Worksheet.
 * Calculates the final tax liability considering both regular income and qualified dividends/capital gains.
 * @param status The filing status code.
 * @param salary Salary income.
 * @param interest Interest income.
 * @param rent Rental income.
 * @param dividend Qualified dividend income.
 * @param capital_gain Long-term capital gain income.
 */
void calculate_tax_worksheet(int status, double salary, double interest, double rent, double dividend, double capital_gain) {

    // --- Worksheet Calculations ---
    double l1, l2, l3, l4, l5, l6_threshold, l7, l8, l9, l10, l11, l12;
    double l13_threshold, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25;
    double standard_deduction;

    // Get standard deduction based on status
    standard_deduction = get_standard_deduction(status);

    // L1: Total Income - Standard Deduction
    l1 = salary + interest + rent + dividend + capital_gain - standard_deduction;
    l1 = fmax(0.0, l1); // Taxable income cannot be negative

    // L2: Dividends
    l2 = dividend;

    // L3: Capital Gains
    l3 = capital_gain;

    // L4: Add lines 2 and 3 (Total Qualified Dividends and Capital Gains)
    l4 = l2 + l3;

    // L5: Subtract line 4 from line 1 (Income taxed at regular rates)
    l5 = l1 - l4;
    l5 = fmax(0.0, l5); // Cannot be negative

    // L6: Enter the threshold for the 0% capital gains bracket based on status
    switch (status) {
        case SINGLE:
        case MARRIED_SEPARATELY:
            l6_threshold = L6_THRESH_SINGLE_SEP;
            break;
        case HEAD_OF_HOUSEHOLD:
            l6_threshold = L6_THRESH_HOH;
            break;
        case MARRIED_JOINTLY:
            l6_threshold = L6_THRESH_MARRIED_JOINTLY;
            break;
        default:
            l6_threshold = 0.0; // Should not happen
    }

    // L7: Enter the smaller of line 1 or line 6 threshold
    l7 = min_double(l1, l6_threshold);

    // L8: Enter the smaller of line 5 or line 7
    l8 = min_double(l5, l7);

    // L9: Subtract line 8 from line 7 (Amount taxed at 0% capital gains rate)
    l9 = l7 - l8;
    l9 = fmax(0.0, l9);

    // L10: Enter the smaller of line 1 or line 4
    l10 = min_double(l1, l4);

    // L11: Enter the amount from line 9
    l11 = l9;

    // L12: Subtract line 11 from line 10
    l12 = l10 - l11;
    l12 = fmax(0.0, l12);

    // L13: Enter the threshold for the 15% capital gains bracket based on status
     switch (status) {
        case SINGLE:
            l13_threshold = L13_THRESH_SINGLE;
            break;
        case HEAD_OF_HOUSEHOLD:
            l13_threshold = L13_THRESH_HOH;
            break;
        case MARRIED_JOINTLY:
            l13_threshold = L13_THRESH_MARRIED_JOINTLY;
            break;
        case MARRIED_SEPARATELY:
             l13_threshold = L13_THRESH_MARRIED_SEP;
            break;
        default:
            l13_threshold = 0.0; // Should not happen
    }

    // L14: Enter the smaller of line 1 or line 13 threshold
    l14 = min_double(l1, l13_threshold);

    // L15: Add lines 5 and 9
    l15 = l5 + l9;

    // L16: Subtract line 15 from line 14. If zero or less, enter -0-
    l16 = l14 - l15;
    l16 = fmax(0.0, l16);

    // L17: Enter the smaller of line 12 or line 16 (Amount taxed at 15% capital gains rate)
    l17 = min_double(l12, l16);

    // L18: Multiply line 17 by 15% (0.15) - Tax from 15% bracket
    l18 = l17 * 0.15;

    // L19: Add lines 9 and 17
    l19 = l9 + l17;

    // L20: Subtract line 19 from line 10 (Amount taxed at 20% capital gains rate)
    l20 = l10 - l19;
    l20 = fmax(0.0, l20);

    // L21: Multiply line 20 by 20% (0.20) - Tax from 20% bracket
    l21 = l20 * 0.20;

    // L22: Figure the tax on the amount on line 5 (Use regular tax brackets)
    l22 = calculate_regular_tax(l5, status);

    // L23: Add lines 18, 21, and 22 (Total tax calculated via worksheet method)
    l23 = l18 + l21 + l22;

    // L24: Figure the tax on the amount on line 1 (Use regular tax brackets on total taxable income)
    l24 = calculate_regular_tax(l1, status);

    // L25: Tax on all taxable income. Enter the smaller of line 23 or line 24.
    l25 = min_double(l23, l24);

    // Print the required results
    print_results(l18, l21, l22, l23, l24, l25);
}


/**
 * @brief Prints the calculated tax results to the console.
 * @param l18 Calculated value for worksheet line 18.
 * @param l21 Calculated value for worksheet line 21.
 * @param l22 Calculated value for worksheet line 22.
 * @param l23 Calculated value for worksheet line 23.
 * @param l24 Calculated value for worksheet line 24.
 * @param l25 Calculated value for worksheet line 25 (Final Tax).
 */
void print_results(double l18, double l21, double l22, double l23, double l24, double l25) {
    printf("--- Tax Calculation Results (2025 Worksheet) ---\n");
    printf(" L18 (Tax at 15%% Rate): $%.2f\n", l18);
    printf(" L21 (Tax at 20%% Rate): $%.2f\n", l21);
    printf(" L22 (Regular Tax on Ordinary Income): $%.2f\n", l22);
    printf(" L23 (Worksheet Tax Calculation): $%.2f\n", l23);
    printf(" L24 (Regular Tax on Total Income): $%.2f\n", l24);
    printf("--------------------------------------------------\n");
    printf(" L25 (Final Estimated Tax Payable): $%.2f\n", l25);
    printf("--------------------------------------------------\n");
}
