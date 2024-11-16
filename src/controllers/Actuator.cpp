#include "Actuator.h"
#include <Arduino.h>

Actuator::Actuator(int pin) : ledPin(pin), lastState(LOW) {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void Actuator::setState(int state) {
    digitalWrite(ledPin, state ? HIGH : LOW);
    lastState = state;
}

int Actuator::getState() const {
    return digitalRead(ledPin);
}

bool Actuator::hasStateChanged() const {
    return digitalRead(ledPin) != lastState;
}
