/* Unity <---> Arduino (Serial Communication)
   - Send a single sensor value to Unity
   Tested in Unity version 2019.1.10f1
   For Manta19 temperature sensor & unity serial communication
   By Ruyi Chen. 08/02/2019
   Reference by Hayeon Hwang. 06/13/2019
*/

const int tempPotPin = A0; // Analog input pin that the temperature is attached to
int sensorValue = 0;
int lastSensorValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Arduino ---> Unity
  sensorValue = analogRead(tempPotPin);

  if (sensorValue != lastSensorValue){
    Serial.println(sensorValue);
    delay(20);
  }

  lastSensorValue = sensorValue;

}
