#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <assert.h>
#include <iostream>

using namespace std;

namespace BMS
{
    class BMS
    {
    public:
        bool temperatureIsOk(float temperature);

        bool socIsOk(float soc);

        bool checkRange(float chargeRate);

        bool batteryIsOk(float temperature, float soc, float chargeRate);

        bool checkFunction(float variable, float min, float max, string outputString);

        bool checkFunction(float variable, float limit, string outputString);

    private:
        bool tempOk;
        bool socOk;
        bool inRange;
    };
}

#endif
