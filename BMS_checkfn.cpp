#include "BMS_checkfn.hpp"

checkFunction(float variable, float min, float max, string outputString)
{
  if (variable < min || variable > max)
  {
    cout << outputString << "\n";
    return false;
  }
  else
  {
    return true;
  }
}

checkFunction(float variable, float limit, string outputString)
{
  if (variable > limit)
  {
    cout << outputString << "\n";
    return false;
  }
  else
  {
    return true;
  }
}
