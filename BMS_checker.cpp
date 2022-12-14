#include "BMS_checker.hpp"
#include "BMS_parameters.hpp"

bool BMS::BMS::temperatureIsOk(float temperature)
{
  if (temperature < temperatureMin || temperature > temperatureMax)
  {
    cout << "Temperature out of range!\n";
    return false;
  }
  else
  {
    return true;
  }
}

bool BMS::BMS::socIsOk(float soc)
{
  if (soc < socMin || soc > socMax)
  {
    cout << "State of Charge out of range!\n";
    return false;
  }
  else
  {
    return true;
  }
}

bool BMS::BMS::checkRange(float chargeRate)
{
  if (chargeRate > chargeRateLimit)
  {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  else
  {
    return true;
  }
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
