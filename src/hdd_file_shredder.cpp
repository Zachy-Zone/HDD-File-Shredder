#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "define_macros_test.h"
#include "structures.h"
#include "variables.h"

#include "file_shredder_functions.h"
#include "time_functions.h"
#include "hdd_file_shredder_test.h"
#include "hdd_file_shredder.h"

/*
-----------------------------------------------------------------------------------------------------------
Global Variables
-----------------------------------------------------------------------------------------------------------
*/

// Parameters
std::string file;
unsigned int fileOverWrites;
bool productionSettings;

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: setParameters
Description: Sets the parameters
Parameters:
  parametersCount - The parameter count
  parameters - The parameters
-----------------------------------------------------------------------------------------------------------
*/

void setParameters(int parametersCount, char* parameters[])
{
  try
  {  
    // Variables
    std::vector<std::string> settings = {parameters+1, parameters+parametersCount};

    // set the default parameters
    productionSettings = true;
    fileOverWrites = DEFAULT_OVERWRITES;
  
    // Loop through all the parameters and get the settings
    for (std::string &data : settings)
    { 
      std::cout << data << std::endl;
      if (data == "--parameters")
      {
        std::cout << INVALID_PARAMETERS_ERROR_MESSAGE;
      }
      if (data == "--test")
      {
        productionSettings = false;
        test();
        exit(0);
      }
      if (data == "--overwrite")
      {
        fileOverWrites = std::stoul(*(&data + 1));
      }
      else
      {
        file = data;
      }
    }
  }
  HANDLEEXCEPTION;
  return;
}



/*
-----------------------------------------------------------------------------------------------------------
Name: printSettings
Description: Prints the settings
-----------------------------------------------------------------------------------------------------------
*/

void printSettings(void)
{
  // print the title
  std::cout << COLOR_PRINT_YELLOW << TEST_OUTLINE << std::endl << "Starting " PROGRAM_VERSION << std::endl << currentTime() << std::endl << std::endl << "SETTINGS" << std::endl << "File: " << file << std::endl << "Overwrites: " << fileOverWrites << std::endl << TEST_OUTLINE << std::endl << COLOR_PRINT_END;

  return;
}



/*
-----------------------------------------------------------------------------------------------------------
Name: userConfirmation
Description: Ask the user to confirm they wanted to delete the file
-----------------------------------------------------------------------------------------------------------
*/

void userConfirmation(void)
{
  // Variables
  std::string data;

  // print the title
  std::cout << "Are you sure you want to shred the above file? (N | Y): ";

  // error check
  if (!std::getline(std::cin, data) || data.empty())
  {
    std::cout << COLOR_PRINT_RED << "An error has occured and the file could not be shreded" << COLOR_PRINT_END << std::endl;
    exit(0);
  }

  // check if the user cancelled the file shred
  if (data != "Y")
  {
    std::cout << COLOR_PRINT_RED << "Cancelling the file shreding" << COLOR_PRINT_END << std::endl;
    exit(0);
  } 

  std::cout << std::endl;

  return;
}

/*
-----------------------------------------------------------------------------------------------------------
Name: main
Description: The start point of the program
Parameters:
  parametersCount - The parameter count
  parameters - The parameters
Return: 0 if successfull
-----------------------------------------------------------------------------------------------------------
*/

int main(int parametersCount, char* parameters[])
{
  // initialize the random seed
  std::srand(std::time(nullptr));

  // set the parameters
  setParameters(parametersCount,parameters);

  // print the settings
  printSettings();

  // get user confirmation
  userConfirmation();

  // shred the file
  if (shredFile(file))
  {
    std::cout << std::endl << COLOR_PRINT_GREEN << "The file has been shredded successfully" << COLOR_PRINT_END << std::endl;
  }
  else
  {
    std::cout << std::endl << COLOR_PRINT_RED << "The file could not be shredded" << COLOR_PRINT_END << std::endl;
  }

  return 0;
}