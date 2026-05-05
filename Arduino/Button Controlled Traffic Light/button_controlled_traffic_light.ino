int redPin = 13;  // Pin for red LED
int greenPin = 7;  // Pin for green LED
int yellowPin = 9;  // Pin for yellow LED
int pushButtonPin = 2;  // Pin for the push button

int ledTurn = 0;  // 0-Red, 1-Yellow, 2-Green
bool buttonPressed = false;  // Track button press state
void updateLed(int ledTurn);

void setup(){
  pinMode(redPin, OUTPUT);  // Set red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set yellow LED pin as output
  pinMode(greenPin, OUTPUT);  // Set green LED pin as output
  pinMode(pushButtonPin, INPUT);  // Set button pin as input
  
  updateLed(ledTurn);  // Initialize LEDs based on starting turn
}

void loop(){
  int pushButtonValue = digitalRead(pushButtonPin);  // Read button state

  if (pushButtonValue == HIGH && !buttonPressed){  // Button pressed
    buttonPressed = true;
    ledTurn = (ledTurn + 1) % 3;  // Cycle through 0, 1, 2
    updateLed(ledTurn);  // Update the LEDs based on the value
    delay(200);  // Debounce delay
  }

  if (pushButtonValue == LOW){  // Button released
    buttonPressed = false;
  }
}

void updateLed(int ledTurn){
  digitalWrite(redPin, LOW);  // Turn off red LED
  digitalWrite(greenPin, LOW);  // Turn off green LED
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  
  if (ledTurn == 0){  // If red is selected
    digitalWrite(redPin, HIGH);  // Turn on red LED
  } else if (ledTurn == 1){  // If yellow is selected
    digitalWrite(yellowPin, HIGH);  // Turn on yellow LED
  } else if (ledTurn == 2){  // If green is selected
    digitalWrite(greenPin, HIGH);  // Turn on green LED
  }
}

