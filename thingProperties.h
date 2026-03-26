#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <Arduino_NetworkConfigurator.h>
#include "configuratorAgents/agents/BLEAgent.h"
#include "configuratorAgents/agents/SerialAgent.h"
void onLightToleranceChange();
void onServoStepChange();
void onStatusChange();

String System_State;
float Avg_Light;
float horiz_diff;
float Light_Sensor1;
float Light_Sensor2;
float Light_Sensor3;
float Light_Sensor4;
float Light_tolerance;
float PH_Volt;
float Servo_step;
float vert_diff;
float Water_PH;
bool status;

KVStore kvStore;
BLEAgentClass BLEAgent;
SerialAgentClass SerialAgent;
WiFiConnectionHandler ArduinoIoTPreferredConnection; 
NetworkConfiguratorClass NetworkConfigurator(ArduinoIoTPreferredConnection);

void initProperties(){
  NetworkConfigurator.addAgent(BLEAgent);
  NetworkConfigurator.addAgent(SerialAgent);
  NetworkConfigurator.setStorage(kvStore);
  // For changing the default reset pin uncomment and set your preferred pin. Use DISABLE_PIN for disabling the reset procedure.
  //NetworkConfigurator.setReconfigurePin(your_pin);
  ArduinoCloud.setConfigurator(NetworkConfigurator);

  ArduinoCloud.addProperty(System_State, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Avg_Light, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(horiz_diff, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Light_Sensor1, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Light_Sensor2, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Light_Sensor3, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Light_Sensor4, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Light_tolerance, READWRITE, ON_CHANGE, onLightToleranceChange);
  ArduinoCloud.addProperty(PH_Volt, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Servo_step, READWRITE, ON_CHANGE, onServoStepChange);
  ArduinoCloud.addProperty(vert_diff, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(Water_PH, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(status, READWRITE, ON_CHANGE, onStatusChange);

}
