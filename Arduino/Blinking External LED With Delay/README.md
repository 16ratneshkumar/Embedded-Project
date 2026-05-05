# **Blinking External LED With Delay Project**

## **Description**

This Arduino project demonstrates how to blink an LED using simple code. The LED turns on and off at 1-second intervals. The project is suitable for beginners and serves as a foundation for understanding pin control, delays, and simple circuit assembly.

## **Features**

* Blinks an LED connected to pin 8 on the Arduino board.
* Simple code that is easy to modify and expand.
* Can be easily replicated both virtually (using Tinkercad) and physically (on real hardware).

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad account**: You need to create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: To use the Tinkercad platform for simulation.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or any other compatible board)
* **LED**
* **220-ohm Resistor**
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** to connect Arduino to the computer

## **Circuit Diagram**
   > ![Circuit Diagram](<../../assets/images/Blinking External LED With Delay.png>)
### **Tinkercad**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new circuit and add the following components:

   * **Arduino Uno**.
   * **LED** with a **220-ohm resistor** connected in series.
   * **Wires** to connect the LED to pin 8 and ground (GND).

### **Hardware Setup**

* **LED** is connected to **pin 8** through a **220-ohm resistor** (positive leg to pin 8, negative to ground).
* **Arduino Pin 8** -> **Resistor** -> **LED Anode (+)**
* **LED Cathode (-)** -> **Ground (GND)**

## **Connection**

| Arduino Pin | Component                             |
| ----------- | ------------------------------------- |
| 8           | LED (with 220-ohm resistor)           |
| GND         | Ground (connected to the LED cathode) |

## **Code Explanation**

The code below makes the LED blink at a 1-second interval. It sets pin 8 as an output pin and then uses the `digitalWrite()` function to turn the LED on and off.

### **Code:**

```cpp
const int ledPin = 8;  // LED connected to digital pin 8

void setup(){
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop(){
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(1000);  // Wait for 1 second
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(1000);  // Wait for 1 second
}
```

* **`pinMode(ledPin, OUTPUT)`**: Configures pin 8 as an output pin.
* **`digitalWrite(ledPin, HIGH)`**: Sends HIGH (5V) to pin 8, turning the LED on.
* **`delay(1000)`**: Pauses for 1000 milliseconds (1 second).
* **`digitalWrite(ledPin, LOW)`**: Sends LOW (0V) to pin 8, turning the LED off.


## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up Circuit in Tinkercad**:

   * Go to [Tinkercad](https://www.tinkercad.com) and sign in or create an account.
   * Navigate to **Circuits** and create a new circuit.
   * Add an **Arduino Uno**, **LED**, **Resistor**, and connect them as per the circuit diagram.
2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Copy and paste the provided code into the Tinkercad editor.
   * Click **Start Simulation** to see the LED blink in the virtual environment.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Use a breadboard and connect the LED to pin 8 on the Arduino through a **220-ohm resistor**.
   * Connect the negative leg (cathode) of the LED to **ground (GND)**.

2. **Upload the Code to Arduino**:

   * Open Arduino IDE on your computer.
   * Connect the Arduino Uno to your PC via a USB cable.
   * Open the **Arduino Blink code** in the IDE.
   * Select the correct board and port under **Tools** > **Board** and **Port**.
   * Click the **Upload** button to upload the code to your Arduino board.

3. **Verify the Output**:

   * Once the code is uploaded, the LED should blink on and off at 1-second intervals.

## **Demo Video**
   > https://github.com/user-attachments/assets/9c814a57-2f94-4c24-ac42-04021c0e2d5b


   
## **Troubleshooting**

* **LED not blinking in Tinkercad?**

  * Double-check the wiring and ensure that the correct components are used in the virtual setup.
  * Ensure the code is properly uploaded to the simulation environment.

* **LED not blinking in hardware setup?**

  * Check the wiring for correctness and verify the LED's polarity.
  * Make sure the **220-ohm resistor** is connected in series with the LED to avoid damaging it.
  * Verify that the correct **Arduino board and COM port** are selected in the Arduino IDE.

* **Arduino not powering?**

  * Ensure that your Arduino is connected to the PC or an external power source (such as a 9V battery or power adapter).

