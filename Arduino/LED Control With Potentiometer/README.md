# **LED Brightness Control with Potentiometer**

## **Description**

This Arduino project uses a potentiometer to control the brightness of an LED. The potentiometer acts as an analog input device that adjusts the LED's brightness by varying the PWM signal sent to the LED. The project demonstrates how to use **analogRead()** and **analogWrite()** functions to read and modify input/output on an Arduino board.

## **Features**

* **Adjustable LED brightness** using a potentiometer.
* Simple, easy-to-understand code for controlling analog values.
* Ideal for learning about **PWM** (Pulse Width Modulation) and analog inputs.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **LED**
* **220-ohm Resistor**
* **Potentiometer**
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**
   > ![Circuit Diagram](<../../assets/images/LED Control With Potentiometer.png>)
### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the following components:

   * **Arduino Uno**
   * **LED** (with a 220-ohm resistor)
   * **Potentiometer**
   * **Wires** to connect components.

### **For Hardware Setup**

* **LED**: The **anode (+)** of the LED connects to **Pin 9** on the Arduino. The **cathode (-)** connects to **Ground (GND)** through a **220-ohm resistor**.
* **Potentiometer**: The **middle pin** (wiper) of the potentiometer connects to **Pin A0**. The **other two pins** connect to **5V** and **Ground**.

## **Connection**

| Arduino Pin | Component                   |
| ----------- | --------------------------- |
| A0          | Potentiometer (middle pin)  |
| 9           | LED (with 220-ohm resistor) |

### **Note**:

* Make sure the potentiometer is wired correctly to get varying analog values on Pin A0.
* The LED must be connected to a **PWM pin** (in this case, Pin 9) to control its brightness.

## **Code Explanation**

The provided code reads the potentiometer value, maps it to the PWM range (0-255), and adjusts the LED brightness accordingly using **analogWrite()**.

### **Code:**

```cpp
const int potPin = A0;                // Potentiometer pin
const int ledPin = 9;                 // PWM pin for LED
int ledValue, potValue;               // Variables to store brightness value (0-255), potentiometer value

void setup(){
    pinMode(ledPin, OUTPUT);          // Set LED pin as output
    Serial.begin(9600);               // Initialize serial communication at 9600 baud
}

void loop(){
    potValue = analogRead(potPin);   // Read potentiometer value (0 to 1023)
    ledValue = map(potValue, 0, 1023, 0, 255); // Map to PWM range (0-255)
    analogWrite(ledPin, ledValue);   // Set LED brightness using PWM
    
    // Print values to Serial Monitor for debugging
    Serial.print("Potentiometer: ");
    Serial.print(potValue);
    Serial.print(" | LED Brightness: ");
    Serial.println(ledValue);
    
    delay(50);                       // Small delay for stability
}
```

* **`Serial.begin(9600)`**: Opens a communication channel between the Arduino and your computer.
* **`Serial.print()` / `Serial.println()`**: Sends the current values to your computer screen.
* **`analogRead(potPin)`**: Reads the analog value from the potentiometer, ranging from 0 to 1023.
* **`map(potValue, 0, 1023, 0, 255)`**: Maps the potentiometer value to the PWM range of 0 to 255.
* **`analogWrite(ledPin, ledValue)`**: Sends a PWM signal to pin 9 to control the brightness of the LED.


## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project and drag the components:

     * **Arduino Uno**
     * **LED** (with a 220-ohm resistor)
     * **Potentiometer**
   * Make the connections according to the table above.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Text** and paste the provided code into the editor.
   * Press **Start Simulation** to see the LED brightness change as you rotate the potentiometer.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Connect the **middle pin** of the potentiometer to **Pin A0** on the Arduino.
   * Connect one side pin of the potentiometer to **5V** and the other side pin to **Ground (GND)**.
   * Connect the **anode (+)** of the **LED** to **Pin 9**.
   * Connect the **cathode (-)** of the **LED** to **Ground (GND)** through a **220-ohm resistor**.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect your **Arduino Uno** to your computer via the **USB cable**.
   * Select the correct **board** and **port** in the **Tools** menu.
   * Copy and paste the provided code into the Arduino IDE.
   * Click **Upload** to send the code to your Arduino.

3. **Verify the Output**:

   * After uploading the code, rotate the potentiometer to adjust the brightness of the LED. The LED should become brighter or dimmer depending on the potentiometer's position.

## **Demo Video**
   > https://github.com/user-attachments/assets/6e5cf04b-e891-4d56-86be-40a25be21ade

   
   

## **Troubleshooting**

* **LED not changing brightness?**

  * Ensure the potentiometer is correctly wired to Pin A0 and the LED is connected to Pin 9.
  * Make sure the potentiometer is not stuck at a single position.

* **Arduino not powering?**

  * Verify that the Arduino is correctly connected to the computer via USB or external power supply.

* **No changes in brightness in Tinkercad?**

  * Double-check the Tinkercad simulation connections.
  * Ensure you're using the **analogWrite()** function to control the LED on a PWM-capable pin.
