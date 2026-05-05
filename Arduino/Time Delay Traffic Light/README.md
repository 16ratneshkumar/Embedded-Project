# **Traffic Light Simulation (Indian Standard)**

## **Description**

This project simulates a traffic light using three **LEDs**: red, yellow, and green. The LEDs follow the **Indian Standard sequence**, which includes a yellow light phase before both green and red signals to alert drivers. This project demonstrates basic digital output, timing, and logical state transitions in Arduino.

## **Features**

* **Red, Yellow, Green LEDs**: Simulates a standard traffic light cycle.
* **Indian Standard Sequence**: Red → Yellow (Ready) → Green → Yellow (Caution) → Red.
* **Timed intervals**: Each phase has a specific duration with a small gap for clarity.
* **Clear Transitions**: Uses short delays between light changes to clearly demarcate each phase.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Sign up for a free account at [Tinkercad](https://www.tinkercad.com/).
* **Internet Connection**: Required to access the Tinkercad Circuits platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **3 x LEDs** (Red, Yellow, Green)
* **3 x 220Ω Resistors**
* **Jumper wires**
* **Breadboard** (optional)
* **Arduino IDE** installed on your computer
* **USB cable** to connect the Arduino to your computer

## **Circuit Diagram**

  > ![Circuit Diagram](<../../assets/images/Time Delay Traffic Light.png>)

### **For Tinkercad Simulation**

1. Open [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project and drag the following components:

   * **Arduino Uno**
   * **3 LEDs** (Red, Yellow, Green)
   * **Resistors** (220Ω)
3. Make the necessary connections using the provided **connection table**.

### **For Hardware Setup**

* **Red LED**: Connect the long leg (anode) to **Pin 13**, the short leg (cathode) to **GND** through a 220Ω resistor.
* **Yellow LED**: Connect the long leg (anode) to **Pin 9**, the short leg (cathode) to **GND** through a 220Ω resistor.
* **Green LED**: Connect the long leg (anode) to **Pin 7**, the short leg (cathode) to **GND** through a 220Ω resistor.

## **Connection**

| Arduino Pin | Component     |
| ----------- | ------------- |
| 13          | Red LED       |
| 9           | Yellow LED    |
| 7           | Green LED     |
| GND         | Common ground |

## **Code Explanation**

This code controls the LEDs to simulate an Indian traffic light sequence. It includes "READY" and "CAUTION" phases using the yellow LED to provide a realistic simulation.

### **Code:**

```cpp
int redPin = 13;  // Pin for red LED
int greenPin = 7;  // Pin for green LED
int yellowPin = 9;  // Pin for yellow LED

void setup(){
  pinMode(redPin, OUTPUT);  // Set red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set yellow LED pin as output
  pinMode(greenPin, OUTPUT);  // Set green LED pin as output
}

void loop(){
  // PHASE 1: RED (Stop)
  digitalWrite(redPin, HIGH);  // Turn on red LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(redPin, LOW);  // Turn off red LED
  delay(500);  // Wait for 0.5 seconds

  // PHASE 2: YELLOW (Ready to Start)
  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds

  // PHASE 3: GREEN (Go)
  digitalWrite(greenPin, HIGH);  // Turn on green LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(greenPin, LOW);  // Turn off green LED
  delay(500);  // Wait for 0.5 seconds

  // PHASE 4: YELLOW (Caution/Prepare to Stop)
  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED again
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds
}
```

* **`digitalWrite()`**: Controls whether the LED is turned on (`HIGH`) or off (`LOW`).
* **`delay()`**: Pauses the program for a specified number of milliseconds.
* The sequence follows a continuous loop: **Red (3s) → Yellow (1s) → Green (3s) → Yellow (1s)**.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Visit [Tinkercad Circuits](https://www.tinkercad.com/circuits) and create a new project.
   * Add an **Arduino Uno** and the three LEDs (red, yellow, green), along with **resistors** (220Ω).
   * Connect the components based on the provided **connection table**.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button to open the editor.
   * Select **Text** and paste the provided code.
   * Press **Start Simulation** to watch the LEDs follow the traffic light pattern.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Wire the **LEDs** to the appropriate **pins** (13, 9, 7) on the Arduino.
   * Ensure each LED is connected to **GND** through a **220Ω resistor**.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE**.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Choose the appropriate **board** and **port** from the **Tools** menu.
   * Copy the provided code into the IDE and press **Upload**.

3. **Observe the Traffic Light**:

   * Once the code is uploaded, the **LEDs** will cycle through the Indian Standard phases with clear separation.

## **Demo Video**
  > https://github.com/user-attachments/assets/10a74431-fc48-4172-bae7-f992444d014c
  
  
 

## **Troubleshooting**

* **LED not turning on?**

  * Check the wiring and ensure the LEDs have the correct polarity (long leg to the pin).
  * Ensure the **220Ω resistor** is connected in series.

* **Sequence looking weird?**

  * Verify the pin numbers in the code (13, 9, 7) match your physical wiring.
  * Check the `digitalWrite` calls in each phase of the `loop()`.
