void setup(){
  pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED as output
}

void loop(){
  digitalWrite(LED_BUILTIN, HIGH);  // Turn LED on
  delay(1000);  // Wait for 1 second
  digitalWrite(LED_BUILTIN, LOW);  // Turn LED off
  delay(1000);  // Wait for 1 second
}