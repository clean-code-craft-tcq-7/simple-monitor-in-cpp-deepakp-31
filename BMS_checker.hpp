#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <assert.h>
#include <iostream>
#include <string>

namespace BMS
{
    class BMS
    {
    public:
        //Assuming the parameter is just transformation achieved by simple multiplication and shifting
        float convertBatteryParam(float paramatervalue, float scaleFactor, float shiftFactor);

        bool temperatureIsOk(float temperature);

        bool socIsOk(float soc);

        bool checkChargeRate(float chargeRate);

        bool temperatureIsOkWithTolerance(float temperature);

        bool socIsOkWithTolerance(float soc);

        bool checkChargeRateWithTolerance(float chargeRate);

        bool batteryIsOk(float temperature, float soc, float chargeRate);

    private:
        bool tempOk;
        bool socOk;
        bool inRange;
    };
}

#endif
