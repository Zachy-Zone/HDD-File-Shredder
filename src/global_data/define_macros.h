#ifndef DEFINE_MACROS_H_   /* Include guard */
#define DEFINE_MACROS_H_

/*
-----------------------------------------------------------------------------------------------------------
Using define statements instead of constants for increased efficiency
-----------------------------------------------------------------------------------------------------------
*/

// Color Printing
#define COLOR_PRINT_RED "\033[1;31m"
#define COLOR_PRINT_GREEN "\033[1;32m"
#define COLOR_PRINT_YELLOW "\033[1;33m"
#define COLOR_PRINT_END "\033[0m"

// General
#define PROGRAM_VERSION "Zachy-Zone-HDD-File-Shredder, Version 1.0.0" // The version of the program
#define DEFAULT_OVERWRITES 10 // Thedefault amount of overwrites

// Test
#define TEST_OUTLINE "-----------------------------------------------------------------------------------------------"
#define INVALID_PARAMETERS_ERROR_MESSAGE \
"Parameters\n" \
"All parameters are optional\n\n" \
"--parameters - List of all valid parameters\n" \
"--test - Run a test to validate system compatibility.\n" \
"--overwrite - The number of times to overwrite the file.\n"
#endif
