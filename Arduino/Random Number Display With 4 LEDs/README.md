# **Random Binary Number Display with Button**

## **Description**

This Arduino project displays the binary representation of a random number (between 0 and 9) on 4 LEDs. A button is used to trigger the display of a new random number each time it is pressed. The project demonstrates how to use buttons and LEDs to represent numbers in binary.

## **Features**

* **4 LEDs** to display the binary representation of numbers between 0 and 9.
* **Button-controlled random number generation**.
* Simple and interactive way to learn about binary numbers and bitwise operations.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **4 LEDs**
* **4 x 220-ohm Resistors**
* **Push button**
* **10kΩ Pull-up Resistor** (for the button)
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**

  > ![Circuit Diagram](<../../assets/images/Random Number Display With 4 LEDs.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the following components:

   * **Arduino Uno**
   * **4 LEDs** (with 220-ohm resistors)
   * **Push button**
   * **Wires** to connect components.

### **For Hardware Setup**

* **LEDs**: Connect each LED to **Pins 2, 3, 4, and 5** on the Arduino, each through a **220-ohm resistor**.
* **Button**: Connect the button to **Pin 9** on the Arduino with an external pull-up resistor to **5V**.

## **Connection**

| Arduino Pin | Component                                          |
| ----------- | -------------------------------------------------- |
| 2           | LED 1 (with 220-ohm resistor)                      |
| 3           | LED 2 (with 220-ohm resistor)                      |
| 4           | LED 3 (with 220-ohm resistor)                      |
| 5           | LED 4 (with 220-ohm resistor)                      |
| 9           | Push Button (with external pull-up resistor to 5V) |

### **Note**:

* Each LED is controlled by a digital pin (2 to 5).
* The button is connected to **Pin 9** and uses an **external pull-up resistor** to keep it HIGH when not pressed.

## **Code Explanation**

This code generates a random number between 0 and 9 whenever the button is pressed and displays its binary representation on 4 LEDs. The button’s state is read, and if it is pressed, a random number is generated and converted to binary.

### **Code:**

```cpp
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
  randomSeed(analogRead(A0));  // Seed RNG so numbers don't repeat on reset
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

  // Check if button is pressed (LOW because of external pull-up)
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
```


* **`Serial.println()`**: Useful for checking the generated random number in the Serial Monitor.
* **`pinMode()`**: Sets the LED pins as outputs and the button pin as input.
* **`digitalRead(buttonPin)`**: Reads the state of the button (LOW when pressed).
* **`randomSeed(analogRead(A0))`**: Seeds the random generator to avoid repeating the same sequence after reset.
* **`random(0, 10)`**: Generates a random number between 0 and 9.
* **`displayBinary(num)`**: Displays the binary representation of the number using the LEDs. It shifts the bits of the number and turns LEDs on or off accordingly.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project and drag the following components:

     * **Arduino Uno**
     * **4 LEDs** (with 220-ohm resistors)
     * **Push button**
   * Make the connections according to the table above.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Text** and paste the provided code into the editor.
   * Press **Start Simulation** to see the LEDs display the random binary number when the button is pressed.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Connect **LEDs** to **Pins 2, 3, 4, and 5** through **220-ohm resistors**.
   * Connect the **push button** to **Pin 9** and to **GND**. Ensure you have an **external pull-up resistor** connected to **5V** for the button.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Select the correct **board** and **port** under the **Tools** menu.
   * Copy and paste the provided code into the IDE.
   * Click **Upload** to send the code to your Arduino.

3. **Verify the Output**:

   * After uploading the code, pressing the button will generate a random number between 0 and 9 and display its binary equivalent on the 4 LEDs. Open the **Serial Monitor** to see the values.

## **Demo Video**
  > https://github.com/user-attachments/assets/90132d44-8492-4b15-a3a4-e897c306eca8


  
  
 

## **Troubleshooting**

* **LEDs not displaying binary numbers correctly?**

  * Double-check the wiring of the LEDs and the button. Ensure that the LEDs are connected to the correct pins and are oriented properly.

* **Button not working?**

  * Make sure the button has an **external pull-up resistor** to pull the pin to **5V** when the button is not pressed.

* **Arduino not powering?**

  * Ensure the Arduino is connected properly via the USB or an external power source.
