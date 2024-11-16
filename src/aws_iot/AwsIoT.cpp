#include "AwsIoT.h"
#include <Arduino.h>

void AwsIoT::connect() {
    if (client.connected()) return;

    Serial.println("Connecting to AWS IoT");
    while (!client.connect(THINGNAME)) {
        Serial.print(".");
        delay(1000);
    }

    client.subscribe(AWS_IOT_DELTA_TOPIC);
    client.subscribe(AWS_IOT_GET_ACCEPTED_TOPIC);
    Serial.println("AWS IoT Connected!");
}

void AwsIoT::setCallback(MQTT_CALLBACK_SIGNATURE) {
    client.setCallback(callback);
}

void AwsIoT::processMessages() {
    client.loop();
}

void AwsIoT::publishUpdate(const char* topic, const char* message) {
    client.publish(topic, message);
}
