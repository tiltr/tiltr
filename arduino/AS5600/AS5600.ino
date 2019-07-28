#include "AS5600.h"

AS5600 encoder;
double output;

const int ledPin = 13;
bool light = true;


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  output = encoder.getPosition(); // get the absolute position of the encoder
  output = (output / 4096 ) * 360;
  Serial.println(output);
  delay(50);
  light = !light;
  light ? digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);

  
}
