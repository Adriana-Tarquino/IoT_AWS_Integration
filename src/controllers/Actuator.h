#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

class Actuator {
public:
    Actuator(int pin);

    void setState(int state);
    int getState() const;
    bool hasStateChanged() const;

private:
    int ledPin;
    int lastState;
};

#endif // LED_CONTROLLER_H
