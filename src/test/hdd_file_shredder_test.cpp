#include <string>
#include <iostream>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "define_macros_test.h"

#include "variables_test.h"

#include "file_shredder_functions.h"
#include "time_functions.h"

#include "file_shredder_functions_test.h"
#include "time_functions_test.h"

#include "hdd_file_shredder_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Name: Global Variables
-----------------------------------------------------------------------------------------------------------
*/

int countTest;



/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: test
Description: Run the test
-----------------------------------------------------------------------------------------------------------
*/

void test()
{
  // Variables
  int total_test = TOTAL_TEST;
  int count = 0;

  // print the start message
  std::cout << COLOR_PRINT_YELLOW << TEST_OUTLINE << std::endl << "Starting " PROGRAM_VERSION " Test" << std::endl << currentTime() << std::endl << TEST_OUTLINE << std::endl << COLOR_PRINT_END;
  
  // run the tests
  count += time_functions_test();
  count += file_shredder_functions_test();

  // write the end test message
  std::cout << COLOR_PRINT_YELLOW << TEST_OUTLINE << std::endl << PROGRAM_VERSION " Test Results - Passed Test: " << count << " Failed Test: " << total_test - count << std::endl << currentTime() << std::endl << TEST_OUTLINE << std::endl << COLOR_PRINT_END;
  return;
}
