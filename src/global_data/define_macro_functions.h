#ifndef DEFINE_MACRO_FUNCTIONS_H_   /* Include guard */
#define DEFINE_MACRO_FUNCTIONS_H_

#include <iostream>
#include <stdexcept>
#include <exception>
#include <future>
#include <filesystem>
#include <ios>
#include <new>

#include "define_macros.h"
#include "variables.h"


/*
-----------------------------------------------------------------------------------------------------------
Using define macros instead of functions for increased efficiency
-----------------------------------------------------------------------------------------------------------
*/



/*
-----------------------------------------------------------------------------------------------------------
Name: HANDLEEXCEPTION
Description: Handles all exceptions
Parameters:
  code - The code to check exceptions for
Return: Writes the correct code
-----------------------------------------------------------------------------------------------------------
*/

#define HANDLEEXCEPTION \
catch (std::invalid_argument& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Invalid Argument From: " << e.what() << std::endl; \
  throw std::invalid_argument(""); \
} \
catch (std::length_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Length Error From: " << e.what() << std::endl; \
  throw std::length_error(""); \
} \
catch (std::out_of_range& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Out Of Range From: " << e.what() << std::endl; \
  throw std::out_of_range(""); \
} \
catch (std::future_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Thread / Async Error From: " << e.what() << std::endl; \
  throw std::future_error(e); \
} \
catch (std::range_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Mathematical Range Error From: " << e.what() << std::endl; \
  throw std::range_error(""); \
} \
catch (std::overflow_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Mathematical Overflow Error From: " << e.what() << std::endl; \
  throw std::overflow_error(""); \
} \
catch (std::underflow_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Mathematical Underflow Error From: " << e.what() << std::endl; \
  throw std::underflow_error(""); \
} \
catch (std::ios_base::failure& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Input / Output Error From: " << e.what() << std::endl; \
  throw std::ios_base::failure(""); \
} \
catch (std::filesystem::filesystem_error& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: File System Error From: " << e.what() << std::endl; \
  throw std::filesystem::filesystem_error(e); \
} \
catch (std::bad_typeid& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Bad Pointer Type Error From: " << e.what() << std::endl; \
  throw std::bad_typeid(); \
} \
catch (std::bad_cast& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Bad Cast Error From: " << e.what() << std::endl; \
  throw std::bad_cast(); \
} \
catch (std::bad_array_new_length& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Bad Array Error From: " << e.what() << std::endl; \
  throw std::bad_array_new_length(); \
} \
catch (std::bad_alloc& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Bad Alloc Error From: " << e.what() << std::endl; \
  throw std::bad_alloc(); \
} \
catch (std::bad_exception& e) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Error: Bad Exception Error From: " << e.what() << std::endl; \
  throw std::bad_exception(); \
} \
catch(...) \
{ \
  std::cout << "Error in " << __FUNCTION__ << " in " << __FILE__ << " at line " << __LINE__ << std::endl << "Undefined Error" << std::endl; \
  throw std::runtime_error(""); \
} \

#endif