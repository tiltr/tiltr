#include "AS5600.h"

AS5600 encoder;
double output;

const int ledPin = 13;
const int motorSpeedPin = 20;
bool light = true;

long revolutions = 0;   // number of revolutions the encoder has made
double position = 0;    // the calculated value the encoder is at
long lastOutput;        // last output from AS5600


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  Serial.begin(9600);
  analogWrite(motorSpeedPin, 20);
  
  output = encoder.getPosition();
  lastOutput = output;
  position = output;

}


void loop() {
  
//  output = encoder.getPosition(); // get the absolute position of the encoder
//  //output = (output / 4096 ) * 360;
//  Serial.println(output);
//  delay(50);
//  light = !light;
//  light ? digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);

  output = encoder.getPosition();           // get the raw value of the encoder                      
  
  if ((lastOutput - output) > 2047 )        // check if a full rotation has been made
    revolutions++;
  if ((lastOutput - output) < -2047 )
    revolutions--;
    
  position = revolutions * 4096 + output;   // calculate the position the the encoder is at based off of the number of revolutions

  Serial.println(position);

  lastOutput = output;                      // save the last raw value for the next loop 
  
}
