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
        bool temperatureIsOk(float temperature);

        bool socIsOk(float soc);

        bool checkRange(float chargeRate);

        bool batteryIsOk(float temperature, float soc, float chargeRate);

    private:
        bool tempOk;
        bool socOk;
        bool inRange;
    };
}

#endif
