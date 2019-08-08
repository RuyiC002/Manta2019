//A combination between analoginput & digitalinput serial communication
//potentiometer control the lighting in unity
//2 bottoms control the play/pause of camera movement in unity
//08/07/2019 By Ruyi Chen

//digital input of 2 bottoms
const int buttonPin01 = 6; //left button is connected to 6
const int buttonPin02 = 7; //right button is connected to 7

//analog input of potentiometer
int potPin = A0;
int sensorValue = 0;
int lastSensorValue = 0;

void setup() {

  Serial.begin(9600);//initialize serial communication at 9600 bits per second

  //digital input of 2 bottoms
  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);

  digitalWrite(buttonPin01, HIGH); //set default as high
  digitalWrite(buttonPin02, HIGH); //set default as high

}

void loop() {

  //digital input of 2 bottoms
  if (digitalRead(buttonPin01) == LOW) // if the button status is changed
  {
    Serial.write(1); //send useful info to unity
    Serial.flush(); //wait for the data import to be done sending
    delay(20); //give unity time to react
    //Serial.println("LEFT");
  }

  if (digitalRead(buttonPin02) == LOW)
  {
    Serial.write(2); //send useful info to unity
    Serial.flush(); //wait for the data import to be done sending
    delay(20); //give unity time to react
    //Serial.println("RIGHT");
  }


  //analog input of potentiometer
  sensorValue = map(analogRead(potPin), 0, 1024, 0, 100); //read the input on analog pin0 & creare the mapping for it

  if (sensorValue - lastSensorValue > 10 || sensorValue - lastSensorValue < -10 ) {

    lastSensorValue = sensorValue;

    Serial.println(sensorValue);//print out the value you read

    //delay(20);//delay in between reads for stability
  }

}
