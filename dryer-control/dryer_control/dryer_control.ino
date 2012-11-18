/*
 * Dryer Control program
 */

#include <Servo.h>

int switchPin = 2;              // Switch connected to digital pin 2
int solenoidPin = 12;
int pressed = false;
Servo servo;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(switchPin, INPUT);    // sets the digital pin as input to read switch
  pinMode(solenoidPin, OUTPUT);
  servo.attach(A0);
  Serial.println("Ready");
}


void loop()
{
  if(digitalRead(switchPin) == HIGH) {
    if(!pressed) {
      startDryer();
      pressed = true;
    }
  } else {
    pressed = false; 
  }
  
  delay(100);
 
}

void startDryer() {
  servo.write(0);
  delay(50);
  for(int i = 1; i < 180; i++) {
    servo.write(i);
    delay(10);
  }
  
  Serial.println("Firing Solenoid!");
  digitalWrite(solenoidPin, HIGH);
  delay(50);
  digitalWrite(solenoidPin, LOW);
}
