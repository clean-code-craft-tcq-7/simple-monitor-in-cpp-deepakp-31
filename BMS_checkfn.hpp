#ifndef CHECK_FN
#define CHECK_FN
#include <string>
#include <iostream>

void printOutput(std::string outputString);

bool isBatteryParameterWithinLimits(float variable, float min, float max, std::string outputString);

bool isBatteryParameterWithinLimitsWithWarning(float variable, float min, float max, float warningPercent, std::string outputString);

bool isBatteryParameterinRange(float variable, float limit, std::string outputString);

bool isBatteryParameterinRangeWithWarning(float variable, float limit, float warningPercent, std::string outputString);

#endif
