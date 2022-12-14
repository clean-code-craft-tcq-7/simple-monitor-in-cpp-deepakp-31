#include "BMS_checker.hpp"

int main()
{
  BMS::BMS bms;
  assert(bms.batteryIsOk(25, 70, 0.7) == true);
  assert(bms.batteryIsOk(50, 85, 0) == false);
}

