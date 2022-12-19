#include "BMS_checker.hpp"
#include "BMS_parameters.hpp"
#include "BMS_checkfn.hpp"

// bool BMS::BMS::temperatureIsOk(float temperature)
// {
//   std::string outputString = "Temperature out of range!";
//   return isBatteryParameterWithinLimits(temperature, temperatureMin, temperatureMax, outputString);
// }

// bool BMS::BMS::socIsOk(float soc)
// {
//   std::string outputString = "State of Charge out of range!";
//   return isBatteryParameterWithinLimits(soc, socMin, socMax, outputString);
// }

// bool BMS::BMS::checkChargeRate(float chargeRate)
// {
//   std::string outputString = "Charge Rate out of range!";
//   return isBatteryParameterinRange(chargeRate, chargeRateLimit, outputString);
// }

// bool BMS::BMS::temperatureIsOk(float temperature, float warningPercent)
// {
//   std::string outputString = "Temperature out of range!";
//   return isBatteryParameterWithinLimits(temperature, temperatureMin, temperatureMax, outputString);
// }

// bool BMS::BMS::socIsOk(float soc, float warningPercent)
// {
//   std::string outputString = "State of Charge out of range!";
//   return isBatteryParameterWithinLimits(soc, socMin, socMax, outputString);
// }

// bool BMS::BMS::checkChargeRate(float chargeRate, float warningPercent)
// {
//   std::string outputString = "Charge Rate out of range!";
//   return isBatteryParameterinRange(chargeRate, chargeRateLimit, outputString);
// }

bool BMS::BMS::temperatureIsOk(float temperature)
{
  std::string outputString = "TEMPERATURE";
  return isBatteryParameterWithinLimits(temperature, temperatureMin, temperatureMax, outputString);
}

bool BMS::BMS::socIsOk(float soc)
{
  std::string outputString = "SOC";
  return isBatteryParameterWithinLimits(soc, socMin, socMax, outputString);
}

bool BMS::BMS::checkChargeRate(float chargeRate)
{
  std::string outputString = "CHARGERATE";
  return isBatteryParameterinRange(chargeRate, chargeRateLimit, outputString);
}

bool BMS::BMS::temperatureIsOk(float temperature, float warningPercent)
{
  std::string outputString = "TEMPERATURE";
  return isBatteryParameterWithinLimits(temperature, temperatureMin, temperatureMax, outputString);
}

bool BMS::BMS::socIsOk(float soc, float warningPercent)
{
  std::string outputString = "SOC";
  return isBatteryParameterWithinLimits(soc, socMin, socMax, outputString);
}

bool BMS::BMS::checkChargeRate(float chargeRate, float warningPercent)
{
  std::string outputString = "CHARGERATE";
  return isBatteryParameterinRange(chargeRate, chargeRateLimit, outputString);
}

bool BMS::BMS::batteryIsOk(float temperature, float soc, float chargeRate)
{

  tempOk = BMS::BMS::temperatureIsOk(temperature);
  socOk = BMS::BMS::socIsOk(soc);
  inRange = BMS::BMS::checkChargeRate(chargeRate);

  return tempOk && socOk && inRange;
}
