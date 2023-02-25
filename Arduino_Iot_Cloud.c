#include "thingProperties.h"
void setup()
{
    pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    Serial.begin(9600);
    initProperties();
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    setDebugMessageLevel(2);
    ArduinoCloud.printDebugInfo();
}
void loop()
{
    ArduinoCloud.update();
    energy=Serial.readStringUntil('\r');
    Serial.println(energy);
}
void onSwitch1Change()
{
    if (switch_1 == 1)
    {
       digitalWrite(5, LOW);
    }
    else
    {
       digitalWrite(5, HIGH);
    }
}
void onSwitch2Change()
{
    if (switch_2 == 1)
    {
       digitalWrite(14,LOW);
    }
    else
    {
       digitalWrite(14, HIGH);
    }
}
void onSwitch3Change()
{
    if (switch_3 == 1)
    {
       digitalWrite(12, LOW);
    }
    else
    {
       digitalWrite(12, HIGH);
    }
}
void onSwitch4Change()
{
    if (switch_4 == 1)
    {
        digitalWrite(13, LOW);
    }
    else
    {
        digitalWrite(13, HIGH);
    }
}
//Library of “Thinproperties.h”
/*
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
const char DEVICE_LOGIN_NAME[] = "7ead4649-6f27-471c-84a0-
c4a8d64c1127";
const char SSID[] = SECRET_SSID; // Network SSID (name)
const char PASS[]
or use as key for WEP)
= SECRET_PASS; // Network password (use for WPA,
const char DEVICE_KEY[] = SECRET_DEVICE_KEY; // Secret device
password
40
void onSwitch1Change();
void onSwitch2Change();
void onSwitch3Change();
void onSwitch4Change();
String energy;
CloudSwitch switch_1;
CloudSwitch switch_2;
CloudSwitch switch_3;
CloudSwitch switch_4;
void initProperties()
{
    ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
    ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
    ArduinoCloud.addProperty(energy, READ, ON_CHANGE, NULL);
    ArduinoCloud.addProperty(switch_1,
    onSwitch1Change);
    READWRITE, ON_CHANGE,
    ArduinoCloud.addProperty(switch_2,
    onSwitch2Change);
    READWRITE, ON_CHANGE,
    41
    ArduinoCloud.addProperty(switch_3,
    onSwitch3Change);
    READWRITE, ON_CHANGE,
    ArduinoCloud.addProperty(switch_4,
    onSwitch4Change);
    READWRITE, ON_CHANGE,
}
WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
*/
