#include "BMS_checker.hpp"

int main()
{
  BMS::BMS bms;
  assert(bms.batteryIsOk(25, 70, 0.7) == true);
  assert(bms.batteryIsOk(50, 85, 0) == false);

  assert(bms.batteryIsOk(-0.1, 20, 0.8) == false);
  assert(bms.batteryIsOk(45, 20, 0.8) == true);
  assert(bms.batteryIsOk(0.1, 20, 0.8) == true);
  assert(bms.batteryIsOk(44.9, 20, 0.8) == true);

  assert(bms.batteryIsOk(0, 80.1, 0.8) == false);
  assert(bms.batteryIsOk(0, 20.1, 0.8) == true);
  assert(bms.batteryIsOk(0, 79.9, 0.8) == true);

  assert(bms.batteryIsOk(0, 20, 0.79) == true);

  // Temperature
  assert(bms.temperatureIsOk(-0.1) == false);
  assert(bms.temperatureIsOk(0) == true);
  assert(bms.temperatureIsOk(45) == true);
  assert(bms.temperatureIsOk(45.1) == false);

  // State of Charge
  assert(bms.socIsOk(19.9) == false);
  assert(bms.socIsOk(20) == true);
  assert(bms.socIsOk(80) == true);
  assert(bms.socIsOk(80.1) == false);

  // Charge rate
  assert(bms.checkChargeRate(0.81) == false);
  assert(bms.checkChargeRate(0.8) == true);
}

