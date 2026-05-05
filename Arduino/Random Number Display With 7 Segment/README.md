# **Random Number Display with 7-Segment Display**

## **Description**

This project demonstrates how to generate a random number (between 0 and 9) and display it on a **7-segment display** using an **Arduino**. A **push button** is used to trigger the generation of a new random number each time it is pressed. This is a fun and interactive project for learning about random numbers and 7-segment display control.

## **Features**

* **Random number generation** (0-9).
* **7-segment display** output.
* **Button-controlled** interaction.
* Clear and simple code for educational purposes.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account at [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible board)
* **Common Cathode 7-segment display**
* **7 x 220-ohm Resistors**
* **Push button**
* **10kΩ Pull-down Resistor** (for the button)
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** to connect the Arduino to your computer

## **Circuit Diagram**

   > ![Circuit Diagram](<../../assets/images/Random Number Display With 7 Segment.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the following components:

   * **Arduino Uno**
   * **7-segment display** (Common Cathode)
   * **7 Resistors** (220-ohm)
   * **Push button**
   * **Wires** to connect components.

### **For Hardware Setup**

* **7-segment Display**: Connect each segment (a-g) to **Pins 2, 3, 4, 5, 6, 7, and 8** on the Arduino, each through a **220-ohm resistor**.
* **Button**: Connect the push button to **Pin 9** on the Arduino with a **10kΩ pull-down resistor** to **GND**.

## **Connection**

| Arduino Pin | Component                         |
| ----------- | --------------------------------- |
| 2           | Segment a (with 220-ohm resistor) |
| 3           | Segment b (with 220-ohm resistor) |
| 4           | Segment c (with 220-ohm resistor) |
| 5           | Segment d (with 220-ohm resistor) |
| 6           | Segment e (with 220-ohm resistor) |
| 7           | Segment f (with 220-ohm resistor) |
| 8           | Segment g (with 220-ohm resistor) |
| 9           | Push button (with 10kΩ pull-down) |
| GND         | Common Cathode of the display     |

### **Note**:

* The **Common Cathode** pin of the 7-segment display must be connected to **GND**.
* Each segment of the 7-segment display is connected to a digital pin through a resistor to prevent damage.

## **Code Explanation**

This code uses a button to trigger a random number generation. Once the button is pressed, the Arduino picks a number between 0 and 9 and sends the corresponding signals to the 7-segment display to show that number.

### **Code:**

```cpp
// Segment pins (a-g)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // Pin numbers for 7-segment display
int buttonPin = 9;  // Pin for the push button
bool buttonPressed = false;  // State to track if button is currently pressed

// Digit patterns for common cathode 7-segment display
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
  // Set segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
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

  // Check if button is pressed
  if (reading == HIGH && !buttonPressed) {
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
```


* **`digits[10][7]`**: A 2D array that stores the state (HIGH/LOW) of each segment for each digit from 0 to 9.
* **`random(0, 10)`**: Generates a random integer between 0 and 9.
* **`displayDigit(int num)`**: A custom function that takes a number and lights up the appropriate segments to display that number.
* **`randomSeed(analogRead(A0))`**: Ensures that each time the Arduino starts, the random numbers are different.
* **`Serial.println()`**: Helpful for verifying the chosen number in the Serial Monitor.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Open [Tinkercad Circuits](https://www.tinkercad.com/circuits) and create a new project.
   * Add the **Arduino Uno**, **7-segment display**, **push button**, and **resistors** (220-ohm).
   * Connect the components based on the provided **connection table**.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button and open the text editor.
   * Paste the provided code and click **Start Simulation**.
   * Press the **push button** in the simulation to see random digits displayed.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Place the **7-segment display** and the **push button** on the breadboard.
   * Wire the **7 segments** to **Pins 2-8** on the Arduino through **220-ohm resistors**.
   * Connect the **push button** to **Pin 9** and to **5V**. Ensure you have a **10kΩ pull-down resistor** connected to **GND** for the button.
   * Connect the **Common Cathode** of the display to **GND**.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE**.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Select the correct **board** and **port** under the **Tools** menu.
   * Copy and paste the provided code into the IDE and click **Upload**.

3. **Verify the Output**:

   * Once the code is uploaded, each time you press the button, a random number between 0 and 9 will be shown on the 7-segment display. Open the **Serial Monitor** to see the values.

## **Demo Video**
   > https://github.com/user-attachments/assets/c0cd4f79-2c9d-4052-b866-8f3214daa31c



   
   

## **Troubleshooting**

* **Display not turning on?**

  * Check the wiring of the 7-segment display. Ensure the **Common Cathode** is connected to **GND**.
  * Verify that each segment is connected to the correct pin on the Arduino.

* **Incorrect digit displayed?**

  * Ensure that the segments are connected in the correct order (a, b, c, d, e, f, g).
  * Double-check the **`digits`** array in the code for any errors.

* **Button not working?**

  * Make sure the button has a **pull-down resistor** to pull the pin to **GND** when it’s not pressed.
  * Verify that the button is connected to **5V** when pressed.
