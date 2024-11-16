#ifndef BME680_SENSOR_H
#define BME680_SENSOR_H

#include <Adafruit_BME680.h>

class BME680Sensor {
public:
    BME680Sensor();
    bool begin();
    bool readSensor();
    float getTemperature();
    float getHumidity();
    float getGasResistance();

private:
    Adafruit_BME680 bme;
};

#endif // BME680_SENSOR_H
