#include <cstring>
#include <string>
#include <fstream>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "variables.h"

#include "file_shredder_functions.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

bool shredFile(std::string file)
{
  // Variables
  std::streampos fileSize;
  int randomByte;
  int count;
  int writeCount;
  
  // get the file size
  std::ifstream fileDataInput(file, std::ifstream::ate | std::ifstream::binary);
  fileSize = fileDataInput.tellg();
  fileDataInput.close();

  // open the file
  std::ofstream fileDataOutput(file,std::ifstream::binary);

  // loop to the overwrite count
  for (writeCount = 0; writeCount < fileOverWrites; writeCount++)
  {  
    // loop through each byte and replace it with random byte
    for (count = 0; count < fileSize; count++)
    {
      // create the random byte
      randomByte = 1 + std::rand()/((RAND_MAX + 0u)/255);

      // set the file to the current byte to overwrite
      fileDataOutput.seekp(count);

      // overwrite the byte
      fileDataOutput.write(reinterpret_cast<char*>(&randomByte),sizeof(char));	
    }
    if (productionSettings)
    {
      std::cout << COLOR_PRINT_YELLOW << "The file has been overwritten successfully" << COLOR_PRINT_END << std::endl;
    }
  }

  // flush the buffer and close the file
  fileDataOutput.flush();	
  fileDataOutput.close();

  // delete the file
  return remove(file.c_str()) == 0 ? true : false;
}
