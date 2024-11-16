#include "aws_iot/AwsIoT.h"
#include "sensors/BME680Sensor.h"
#include "controllers/LedController.h"
#include "WiFiConnection.h"
#include <ArduinoJson.h>

#define LED_PIN 2

WiFiClientSecure net;
PubSubClient mqttClient(net);
AwsIoT awsIot(mqttClient);
BME680Sensor sensor;
LedController led(LED_PIN);

void messageHandler(char* topic, byte* payload, unsigned int length) {
    StaticJsonDocument<300> doc;
    deserializeJson(doc, payload, length);

    if (strcmp(topic, AWS_IOT_DELTA_TOPIC) == 0) {
        Serial.println("Recibido mensaje de actualización para el shadow.");
        if (doc.containsKey("state") && doc["state"].containsKey("fan")) {
            int fanCommand = doc["state"]["fan"];
            led.setState(fanCommand);
            Serial.println(fanCommand ? "Fan encendido (LED encendido)" : "Fan apagado (LED apagado)");
            StaticJsonDocument<300> updateDoc;
            updateDoc["state"]["reported"]["fan"] = fanCommand;
            char jsonBuffer[512];
            serializeJson(updateDoc, jsonBuffer);
            awsIot.publishUpdate(AWS_IOT_UPDATE_TOPIC, jsonBuffer);
        }
    }
}

void setup() {
    Serial.begin(115200);
    connectWiFi();

    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    mqttClient.setServer(AWS_IOT_ENDPOINT, 8883);
    awsIot.setCallback(messageHandler);

    awsIot.connect();

    if (!sensor.begin()) {
        while (1); // Detener si el sensor no inicia.
    }
}

void loop() {
    awsIot.connect();
    awsIot.processMessages();

    if (sensor.readSensor()) {
        if (led.hasStateChanged()) {
            StaticJsonDocument<300> updateDoc;
            updateDoc["state"]["reported"]["builtInLed"] = led.getState();
            updateDoc["state"]["reported"]["temperature"] = sensor.getTemperature();
            updateDoc["state"]["reported"]["humidity"] = sensor.getHumidity();
            updateDoc["state"]["reported"]["gasResistance"] = sensor.getGasResistance();
            char jsonBuffer[512];
            serializeJson(updateDoc, jsonBuffer);
            awsIot.publishUpdate(AWS_IOT_UPDATE_TOPIC, jsonBuffer);
        }
    }

    delay(2000);
}
