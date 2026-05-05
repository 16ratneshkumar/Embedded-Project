// Segment pins (a-g)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // Pin numbers for 7-segment display
const int buttonPin = 9;  // Pin for the button

bool buttonPressed = false;  // Track button press state

// Digits 0-9 for 7-segment display (a-g) segments
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);  // Set segment pins as outputs
  }
  pinMode(buttonPin, INPUT);  // Set button pin as input
  randomSeed(analogRead(A0));  // Use analog noise for randomness
  displayDigit(0);             // Initialize display with 0
  Serial.begin(9600);          // Initialize Serial
  Serial.println("7-Segment Random Digit Ready!");
}



void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);  // Set segment states based on the digit
  }
}

void loop() {
  int reading = digitalRead(buttonPin);  // Read button state

  if (reading == HIGH && !buttonPressed) {  // Button pressed
    buttonPressed = true;
    int randNum = random(0, 10);  // Generate a random digit between 0 and 9
    Serial.print("Random Digit: ");
    Serial.println(randNum);
    displayDigit(randNum);  // Display the random digit on the 7-segment display
    delay(200);  // Debounce delay to avoid multiple triggers

  }

  if (reading == LOW) {  // Button released
    buttonPressed = false;
  }
}
