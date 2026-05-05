int redPin = 13;  // Pin for red LED
int greenPin = 7;  // Pin for green LED
int yellowPin = 9;  // Pin for yellow LED

void setup(){
  pinMode(redPin, OUTPUT);  // Set red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set yellow LED pin as output
  pinMode(greenPin, OUTPUT);  // Set green LED pin as output
}

void loop(){
  digitalWrite(redPin, HIGH);  // Turn on red LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(redPin, LOW);  // Turn off red LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(greenPin, HIGH);  // Turn on green LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(greenPin, LOW);  // Turn off green LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED again
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds
}