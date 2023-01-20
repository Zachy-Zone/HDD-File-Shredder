#include <string>
#include <iostream>
#include <fstream>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "define_macros_test.h"

#include "file_shredder_functions.h"

#include "variables_test.h"
#include "file_shredder_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: file_shredder_functions_test
Return: The number of passed file_functions test
-----------------------------------------------------------------------------------------------------------
*/

int file_shredder_functions_test(void)
{
  // reset the global variables
  countTest = 0;

  // Variables
  std::string s;

  // write the start test message
  std::cout << std::endl << COLOR_PRINT_YELLOW << TEST_OUTLINE << std::endl << "file_shredder_functions_test - Total test: " << FILE_SHREDDER_FUNCTIONS_TOTAL_TEST << std::endl << TEST_OUTLINE << std::endl << std::endl << COLOR_PRINT_END;

  // run the test

  // shredFile
  std::ofstream fileData(PROGRAM_VERSION);
  fileData << PROGRAM_VERSION;
  fileData.close();
  if (shredFile(PROGRAM_VERSION))
  {
    std::cout << COLOR_PRINT_GREEN << "PASSED! shredFile" << COLOR_PRINT_END;
    countTest++;
  }
  else
  {
    std::cout << COLOR_PRINT_RED << "FAILED! shredFile" << COLOR_PRINT_END;
  }


  // write the end test message
  std::cout << COLOR_PRINT_YELLOW << std::endl << std::endl << TEST_OUTLINE << std::endl << "file_shredder_functions_test - Passed test: " << countTest << ", Failed test: " << FILE_SHREDDER_FUNCTIONS_TOTAL_TEST-countTest << std::endl << TEST_OUTLINE << std::endl << std::endl << std::endl << COLOR_PRINT_END;
  return countTest;
}