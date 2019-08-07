//Analog Read with Serial communication
//potentiometer controls the lighting in unity
//08/07/2019 By Ruyi Chen

int potPin = A0;
int sensorValue = 0;
int lastSensorValue = 0;

void setup() {

  Serial.begin(9600); //initialize serial communication at 9600 bits per second
  //Serial.setTimeout(13);
}

void loop() {


  sensorValue = map(analogRead(potPin), 0, 1024, 0, 100); //read the input on analog pin0 & creare the mapping for it

  if (sensorValue - lastSensorValue > 10 || sensorValue - lastSensorValue < -10 ) {

    lastSensorValue = sensorValue;

    Serial.println(sensorValue);//print out the value you read

    //delay(20);//delay in between reads for stability
  }


}
