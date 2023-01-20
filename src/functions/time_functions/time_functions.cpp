#include <iostream>
#include <ctime>
#include <string>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "variables.h"

#include "time_functions.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: currentTime
Description: Prints the current time in a string format
Return: The current time in a string format
-----------------------------------------------------------------------------------------------------------
*/

std::string currentTime()
{  
  // Variables
  std::time_t dateAndTime = std::time(0);
  char buffer[50];

  // Get the current time and date
  std::strftime(buffer, sizeof(buffer), "%a %d %b %Y %H:%M:%S UTC", std::gmtime(&dateAndTime));

  // Convert the char array to a string
  std::string s(buffer);

  return s;
}