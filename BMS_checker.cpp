#include "BMS_checker.hpp"
#include "BMS_parameters.hpp"
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

bool BMS::BMS::temperatureIsOk(float temperature)
{
  string outputString = "Temperature out of range!";
  return checkFunction(temperature, temperatureMin, temperatureMax, outputString);

  // if (temperature < temperatureMin || temperature > temperatureMax)
  // {
  //   cout << "Temperature out of range!\n";
  //   return false;
  // }
  // else
  // {
  //   return true;
  // }
}

bool BMS::BMS::socIsOk(float soc)
{
  string outputString = "State of Charge out of range!";
  return checkFunction(soc, socMin, socMax, outputString);
  // if (soc < socMin || soc > socMax)
  // {
  //   cout << "State of Charge out of range!\n";
  //   return false;
  // }
  // else
  // {
  //   return true;
  // }
}

bool BMS::BMS::checkRange(float chargeRate)
{
  string outputString = "Charge Rate out of range!";
  return checkFunction(chargeRate, chargeRateLimit, outputString);

  // if (chargeRate > chargeRateLimit)
  // {
  //   cout << "Charge Rate out of range!\n";
  //   return false;
  // }
  // else
  // {
  //   return true;
  // }
}

bool BMS::BMS::batteryIsOk(float temperature, float soc, float chargeRate)
{

  tempOk = BMS::BMS::temperatureIsOk(temperature);
  socOk = BMS::BMS::socIsOk(soc);
  inRange = BMS::BMS::checkRange(chargeRate);

  return tempOk && socOk && inRange;
}

// int main()
// {
//   BMS::BMS bms;
//   assert(bms.batteryIsOk(25, 70, 0.7) == true);
//   assert(bms.batteryIsOk(50, 85, 0) == false);
// }
