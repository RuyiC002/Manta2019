// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int thermoSO = 4;
int thermoCS = 5;
int thermoSCK = 6;

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {

  Serial.begin(9600);
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);

}

void loop() {
  // basic readout test, just print the current temp

  //print Celsius
  //Serial.print("C = ");
  //Serial.println(thermocouple.readCelsius());
  
  //print Fahrenheit
  //Serial.print("F = ");
  //Serial.println(thermocouple.readFahrenheit());

  //Map the vaule to 0-225 range
  int val = thermocouple.readCelsius();
  val = map(val, 24, 30, 0, 24);
  //print the value of the ObjMaterial
  //Serial.print("ObjMaterial= ");
  Serial.println(val);

  delay(1000);
}
