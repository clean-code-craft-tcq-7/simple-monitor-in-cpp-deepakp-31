#ifndef BMS_PARAM
#define BMS_PARAM

// Temperature
float temperatureMin = 0.0;
float temperatureMax = 45.0;
float temperatureTolerance = 0.05;
float temperatureScaleFactor = 5 / 9;
float temperatureShiftFactor = (-32 * 5) / 9;

// SOC
float socMin = 20.0;
float socMax = 80.0;
float socTolerance = 0.05;
float socScaleFactor = 1.0;
float socShiftFactor = 0.0;

// charge Rate Limit
float chargeRateLimit = 0.8;
float chargeRateTolerance = 0.05;
float chargeRateScaleFactor = 1.0;
float chargeRateShiftFactor = 0.0;

#endif
