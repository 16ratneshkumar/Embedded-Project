const int ledPins[4] = {2, 3, 4, 5};  // LED pins
const int buttonPin = 9;  // Button pin
bool buttonPressed = false;  // Track button press state

void setup() {
  // Set LED pins as output
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Set button pin as input
  pinMode(buttonPin, INPUT);  // No internal pull-up, external pull-up used
  randomSeed(analogRead(A0));  // Seed RNG so numbers don't repeat on every reset
  displayBinary(0);            // Start with all LEDs OFF
  Serial.begin(9600);          // Initialize Serial
  Serial.println("Random Binary Generator Ready!");
}



void displayBinary(int num) {
  // Display the 4 least significant bits of 'num' on the LEDs
  for (int i = 0; i < 4; i++) {
    int bitValue = (num >> i) & 1;  // Get the i-th bit
    digitalWrite(ledPins[i], bitValue ? HIGH : LOW);  // Set LED based on bit value
  }
}

void loop() {
  int reading = digitalRead(buttonPin);  // Read button state

  if (reading == LOW && !buttonPressed) {  // Button pressed (active LOW)
    buttonPressed = true;
    int randomNumber = random(0, 10);  // Generate random number between 0 and 9
    Serial.print("Generated Number: ");
    Serial.println(randomNumber);
    displayBinary(randomNumber);  // Display the binary representation on LEDs
    delay(500);  // Debounce delay to avoid multiple triggers from a single press

  }

  if (reading == HIGH) {  // Button released
    buttonPressed = false;
  }
}
