//digital Read with Serial communication
//2 bottoms control the play/pause of camera movement in unity
//08/07/2019 By Ruyi Chen

const int buttonPin01 = 6; //left button is connected to 6
const int buttonPin02 = 7; //right button is connected to 7

void setup() {
  
  Serial.begin(9600);

  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);

  digitalWrite(buttonPin01, HIGH); //set default as high
  digitalWrite(buttonPin02, HIGH); //set default as high
}

void loop() {
  if (digitalRead(buttonPin01) == LOW) // if the button status is changed
  {
    Serial.write(1); //send useful info to unity
    Serial.flush(); //wait for the data import to be done sending
    delay(20); //give unity time to react
    Serial.println("LEFT");
  }

  if (digitalRead(buttonPin02) == LOW)
  {
    Serial.write(2); //send useful info to unity
    Serial.flush(); //wait for the data import to be done sending
    delay(20); //give unity time to react
    Serial.println("RIGHT");
  }

}
