const int ledPin = 8;  // LED connected to digital pin 8

void setup(){
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop(){
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(1000);  // Wait for 1 second
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(1000);  // Wait for 1 second
}