#include "BME680Sensor.h"
#include <Arduino.h>

BME680Sensor::BME680Sensor() : bme() {}

bool BME680Sensor::begin() {
    if (!bme.begin()) {
        Serial.println("Could not find a valid BME680 sensor, check wiring!");
        return false;
    }
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setGasHeater(320, 150);
    return true;
}

bool BME680Sensor::readSensor() {
    return bme.performReading();
}

float BME680Sensor::getTemperature() {
    return bme.temperature;
}

float BME680Sensor::getHumidity() {
    return bme.humidity;
}

float BME680Sensor::getGasResistance() {
    return bme.gas_resistance;
}
