#include "BMS_checker.hpp"
#include "BMS_parameters.hpp"
#include "BMS_checkfn.hpp"

bool BMS::BMS::temperatureIsOk(float temperature)
{
  std::string outputString = "Temperature out of range!";
  return checkFunction(temperature, temperatureMin, temperatureMax, outputString);
}

bool BMS::BMS::socIsOk(float soc)
{
  std::string outputString = "State of Charge out of range!";
  return checkFunction(soc, socMin, socMax, outputString);
}

bool BMS::BMS::checkRange(float chargeRate)
{
  std::string outputString = "Charge Rate out of range!";
  return checkFunction(chargeRate, chargeRateLimit, outputString);
}

bool BMS::BMS::batteryIsOk(float temperature, float soc, float chargeRate)
{

  tempOk = BMS::BMS::temperatureIsOk(temperature);
  socOk = BMS::BMS::socIsOk(soc);
  inRange = BMS::BMS::checkRange(chargeRate);

  return tempOk && socOk && inRange;
}
