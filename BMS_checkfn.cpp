#include "BMS_checkfn.hpp"

void printOutput(std::string outputString)
{
  std::cout << outputString << "\n";
}

bool isBatteryParameterWithinLimits(float variable, float min, float max, std::string outputString)
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

bool highEarlyWarningBatteryParameter(float variable, float min, float max, float warningPercent, std::string outputString)
{
  if (variable > max)
  {
    outputString = "HIGH_" + outputString + "_BREACH";
    printOutput(outputString);
    // HIGH_"Battery_PARAM"_BREACH
    return false;
  }
  // HIGH_"Battery_PARAM"_WARNING
  outputString = "HIGH_" + outputString + "_WARNING";
  printOutput(outputString);
  return true;
}

bool lowEarlyWarningBatteryParameter(float variable, float min, float max, float warningPercent, std::string outputString)
{
  if (variable > min)
  {
    // LOW_"Battery_PARAM"_WARNING
    outputString = "LOW_" + outputString + "_WARNING";
    printOutput(outputString);
    return true;
  }
  else
  {
    // LOW_"Battery_PARAM"_BREACH
    outputString = "LOW_" + outputString + "_BREACH";
    printOutput(outputString);
    return false;
  }
}

bool isBatteryParameterWithinLimitsWithWarning(float variable, float min, float max, float warningPercent, std::string outputString)
{
  if (variable > (max * warningPercent))
  {

    return highEarlyWarningBatteryParameter(variable, min, max, warningPercent, outputString);
  }

  else if (variable > (min * warningPercent))
  {
    // NORMAL
    outputString = "NORMAL_" + outputString;
    printOutput(outputString);
    return true;
  }
  return lowEarlyWarningBatteryParameter(variable, min, max, warningPercent, outputString);
}

bool isBatteryParameterinRange(float variable, float limit, std::string outputString)
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
bool isBatteryParameterinRangeWithWarning(float parameter, float parameterRange, float warningPercent, std::string outputString)
{
  if (parameter > parameterRange)
  {
    // printOutput(outputString);
    // "Battery_PARAM"_RANGE_BREACH,
    outputString = outputString + "_RANGE_BREACH";
    printOutput(outputString);
    return false;
  }
  else if (parameter > (parameterRange * warningPercent))
  {
    // "Battery_PARAM"_RANGE_WARNING
    outputString = outputString + "_RANGE_WARNING";
    printOutput(outputString);
    return true;
  }

  outputString = outputString + "_IN_RANGE";
  printOutput(outputString);
  return true;
}
