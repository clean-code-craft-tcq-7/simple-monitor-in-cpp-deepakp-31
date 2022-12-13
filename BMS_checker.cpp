#include "BMS_checker.hpp"

using namespace std;

bool BMS::BMS::temperatureIsOk(float temperature)
{
  if (temperature < 0 || temperature > 45)
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
  if (soc < 20 || soc > 80)
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
  if (chargeRate > 0.8)
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

  tempOk = BMS::BMS::temperatureIsOk;
  socOk = BMS::BMS::socIsOk;
  inRange = BMS::BMS::checkRange;

  return tempOk && socOk && inRange;

  // if (temperature < 0 || temperature > 45)
  // {
  //   cout << "Temperature out of range!\n";
  //   return false;
  // }
  // else if (soc < 20 || soc > 80)
  // {
  //   cout << "State of Charge out of range!\n";
  //   return false;
  // }
  // else if (chargeRate > 0.8)
  // {
  //   cout << "Charge Rate out of range!\n";
  //   return false;
  // }
  // return true;
}

int main()
{
  BMS::BMS bms;
  assert(bms.batteryIsOk(25, 70, 0.7) == true);
  assert(bms.batteryIsOk(50, 85, 0) == false);
}
