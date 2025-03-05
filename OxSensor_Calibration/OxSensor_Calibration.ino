#include "OxygenSensor.h"
 
/**
 * i2c slave Address, The default is ADDRESS_3.
 * ADDRESS_0   0x70  i2c device address.
 * ADDRESS_1   0x71
 * ADDRESS_2   0x72
 * ADDRESS_3   0x73
 */
#define Oxygen_IICAddress ADDRESS_3
#define OXYGEN_CONECTRATION 20.9  // The current concentration of oxygen in the air.
#define OXYGEN_MV           0     // The value marked on the sensor, Do not use must be assigned to 0.
OxygenSensor oxygen;
 
void setup(void)
{
  Serial.begin(9600);
  while(!oxygen.begin(Oxygen_IICAddress)){
    Serial.println("I2c device number error !");
    delay(1000);
  }
  Serial.println("I2c connect success !");
  oxygen.calibrate(OXYGEN_CONECTRATION, OXYGEN_MV);
}
 
void loop(void)
{
  Serial.println("The oxygen sensor was calibrated successfully.");
  delay(1000);
}