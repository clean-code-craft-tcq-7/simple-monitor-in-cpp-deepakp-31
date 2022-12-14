#include "BMS_checkfn.hpp"

void printOutput(std::string outputString)
{
  std::cout << outputString << "\n";
}

bool checkFunction(float variable, float min, float max, std::string outputString)
{
  if (variable < min || variable > max)
  {
    printOutput(outputString);
    return false;
  }
  else
  {
    return true;
  }
}

bool checkFunction(float variable, float limit, std::string outputString)
{
  if (variable > limit)
  {
    printOutput(outputString);
    return false;
  }
  else
  {
    return true;
  }
}
