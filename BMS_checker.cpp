#include "BMS_checker.hpp"
#include "BMS_parameters.hpp"
#include "BMS_checkfn.hpp"

float BMS::BMS::convertBateryParam(float paramatervalue, float scaleFactor, float shiftFactor)
{
  return ((scaleFactor * paramatervalue) + shiftFactor);
}

// WITHOUT WARNING TOLERANCE
bool BMS::BMS::temperatureIsOk(float temperature)
{
  std::string outputString = "TEMPERATURE";
  return isBatteryParameterWithinLimits(convertBateryParam(temperature, temperatureScaleFactor, temperatureShiftFactor),
                                        temperatureMin, temperatureMax, outputString);
}

bool BMS::BMS::socIsOk(float soc)
{
  std::string outputString = "SOC";
  return isBatteryParameterWithinLimits(convertBateryParam(soc, socScaleFactor, socShiftFactor),
                                        socMin, socMax, outputString);
}

bool BMS::BMS::checkChargeRate(float chargeRate)
{
  std::string outputString = "CHARGERATE";
  return isBatteryParameterinRange(convertBateryParam(chargeRate, chargeRateScaleFactor, chargeRateShiftFactor),
                                   chargeRateLimit, outputString);
}

// WITH WARNING TOLERANCE
bool BMS::BMS::temperatureIsOk(float temperature)
{
  std::string outputString = "TEMPERATURE";
  return isBatteryParameterWithinLimitsWithWarning(
      convertBateryParam(temperature, temperatureScaleFactor, temperatureShiftFactor),
      temperatureTolerance, temperatureMin, temperatureMax, outputString);
}

bool BMS::BMS::socIsOk(float soc)
{
  std::string outputString = "SOC";
  return isBatteryParameterWithinLimitsWithWarning(
      convertBateryParam(soc, socScaleFactor, socShiftFactor),
      socTolerance, socMin, socMax, outputString);
}

bool BMS::BMS::checkChargeRate(float chargeRate)
{
  std::string outputString = "CHARGERATE";
  return isBatteryParameterinRangeWithWarning(
      convertBateryParam(chargeRate, chargeRateScaleFactor, chargeRateShiftFactor),
      chargeRateTolerance, chargeRateLimit, outputString);
}

bool BMS::BMS::batteryIsOk(float temperature, float soc, float chargeRate)
{

  tempOk = BMS::BMS::temperatureIsOk(temperature);
  socOk = BMS::BMS::socIsOk(soc);
  inRange = BMS::BMS::checkChargeRate(chargeRate);

  return tempOk && socOk && inRange;
}
