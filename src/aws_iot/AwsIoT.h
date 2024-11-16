#ifndef AWS_IOT_H
#define AWS_IOT_H

#include <PubSubClient.h>

class AwsIoT {
public:
    AwsIoT(PubSubClient& mqttClient) : client(mqttClient) {}

    void connect();
    void setCallback(MQTT_CALLBACK_SIGNATURE);
    void processMessages();
    void publishUpdate(const char* topic, const char* message);

private:
    PubSubClient& client;
};

#endif // AWS_IOT_H
