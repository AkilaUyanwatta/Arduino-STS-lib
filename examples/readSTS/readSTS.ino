/*
Notes by Akila Uyanwatta
********Pin configuration*********
  Pin Number of STS - Arduino pin
          1         - A4
          2         - GND
          4         - A5
          5         - 5V
          7         - GND
          8         - GND
  Leave pin 3 and 6 unconnected
*/

/*
 * V Example to read temperature from STS-30: https://create.arduino.cc/projecthub/Dcube/temperature-measurement-using-sts21-and-arduino-nano-a5f264
 * V Example to read temperature and humidity from SHT-30: https://developer.sensirion.com/platforms/arduino/
 * 
 * X Expand with adding more I2C lines to the Arduino by assigning pins: https://www.arduino.cc/en/Tutorial/SamdSercom
 * 
 */

#include <Wire.h>
#include <STSSensor.h>

STSSensor sts( Wire );            // adapted version of SHT library

void setup()
{
  Wire.begin();                 // Join i2c bus (address optional for master)
  Wire.setClock(400000);        // Selecting Fast I2C. Comment if you need 100kHz clock speed
  Serial.begin(115200);         // Selecting Serial communication speed
  sts.init(Wire);
}


void loop() {
  sts.readSample();
  Serial.print("STS:\n");
  Serial.print("  T:  ");
  Serial.println(sts.getTemperature(), 2);
  Serial.print("\n");
  delay(10);
}
