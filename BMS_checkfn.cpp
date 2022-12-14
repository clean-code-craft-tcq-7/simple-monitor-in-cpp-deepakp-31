#include "BMS_checkfn.hpp"

bool checkFunction(float variable, float min, float max, std::string outputString)
{
  if (variable < min || variable > max)
  {
    std::cout << outputString << "\n";
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
    std::cout << outputString << "\n";
    return false;
  }
  else
  {
    return true;
  }
}
