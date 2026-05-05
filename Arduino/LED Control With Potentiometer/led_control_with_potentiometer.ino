const int potPin = A0;              // Potentiometer pin
const int ledPin = 9;               // PWM pin for LED
int ledValue, potValue;             // Variables to store brightness and potentiometer values

void setup(){
    pinMode(ledPin, OUTPUT);        // Set LED pin as output
    Serial.begin(9600);             // Initialize serial communication at 9600 baud
}

void loop(){
    potValue = analogRead(potPin);   // Read Potentiometer value (0 to 1023)
    ledValue = map(potValue, 0, 1023, 0, 255);  // Map to PWM range
    analogWrite(ledPin, ledValue);   // Set LED brightness
    
    // Print values to Serial Monitor for debugging
    Serial.print("Potentiometer: ");
    Serial.print(potValue);
    Serial.print(" | LED Brightness: ");
    Serial.println(ledValue);
    
    delay(50);                      // Small delay for stability
}

