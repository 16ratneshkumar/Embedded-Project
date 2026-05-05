# **Servo Motor Controlled by Potentiometer**

## **Description**

This project allows you to control the angle of a **servo motor** using a **potentiometer**. The potentiometer adjusts the servo angle, which ranges from 0 to 180 degrees, providing smooth and continuous movement. This project is perfect for learning about **analog sensors** and **servo motor control** using the Arduino.

## **Features**

* **Servo motor control**: The servo motor angle is controlled by a potentiometer.
* **Smooth movement**: The potentiometer value is mapped to the servo angle, providing smooth motion.
* **Simple and easy to set up**: Perfect for beginners.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **Servo motor**
* **Potentiometer**
* **Jumper wires**
* **Breadboard** (optional)
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**

   > ![Circuit Diagram](<../../assets/images/Servo Motor Control With Potentiometer.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the following components:

   * **Arduino Uno**
   * **Servo motor**
   * **Potentiometer**
   * **Wires** to make the necessary connections.

### **For Hardware Setup**

* **Servo Motor**: Connect the **control pin** of the servo to **Pin 6** on the Arduino. Connect the **VCC pin** to **5V** and the **GND pin** to **GND**.
* **Potentiometer**: Connect one end to **5V** and the other end to **GND**. Connect the **wiper (middle pin)** to **Pin A0** on the Arduino to read its value.

## **Connection**

| Arduino Pin | Component                |
| ----------- | ------------------------ |
| 6           | Servo control pin        |
| A0          | Potentiometer middle pin |
| 5V          | Potentiometer VCC        |
| GND         | Potentiometer GND        |
| 5V          | Servo VCC                |
| GND         | Servo GND                |

## **Code Explanation**

This code reads the potentiometer's analog value (between 0 and 1023), maps it to a servo angle (between 0 and 180 degrees), and writes the corresponding angle to the servo motor. The servo rotates smoothly based on the potentiometer's position.

### **Code:**

```cpp
#include <Servo.h>  // Include Servo library

Servo myServo;  // Create Servo object

int servoPin = 6;  // Pin connected to the servo
int potValue;  // Variable to store potentiometer value
int potPin = A0;  // Pin connected to the potentiometer

void setup(){
  myServo.attach(servoPin);  // Attach the servo to the specified pin
  Serial.begin(9600);        // Initialize serial communication
}

void loop(){
  potValue = analogRead(potPin);  // Read the potentiometer value (0-1023)
  int servoAngle = map(potValue, 0, 1023, 0, 180);  // Map potentiometer value to servo angle (0-180)
  myServo.write(servoAngle);  // Set the servo angle based on the potentiometer value
  
  // Print values to Serial Monitor
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(" -> Angle: ");
  Serial.println(servoAngle);
  
  delay(15);  // Short delay to smooth movement
}
```

* **`Serial.begin(9600)`**: Enables communication to see the servo angle on your screen.
* **`Servo.h`**: This library allows easy control of servo motors.
* **`analogRead(potPin)`**: Reads the analog value from the potentiometer (0-1023).
* **`map()`**: Maps the potentiometer value (0-1023) to a servo angle (0-180 degrees).
* **`myServo.write()`**: Sets the angle of the servo motor.
* **`delay(15)`**: Introduces a small delay to make the movement smoother.



## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project and drag the following components:

     * **Arduino Uno**
     * **Servo motor**
     * **Potentiometer**
   * Connect the components based on the provided **connection table**.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Text** and paste the provided code into the editor.
   * Press **Start Simulation** to see the servo rotate based on the potentiometer's position.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Connect the **servo motor** to **Pin 6** for control, **5V** for power, and **GND** for ground.
   * Connect the **potentiometer** to **A0** for reading its analog value, with one side connected to **5V** and the other to **GND**.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Select the correct **board** and **port** under the **Tools** menu.
   * Copy and paste the provided code into the IDE.
   * Click **Upload** to send the code to your Arduino.

3. **Verify the Output**:

   * After uploading the code, turning the potentiometer will rotate the servo motor between 0 and 180 degrees based on the potentiometer's position.

## **Demo Video**
  > https://github.com/user-attachments/assets/8c270b35-36bd-4ed9-8412-7742ff2423ed


  
  

## **Troubleshooting**

* **Servo not responding?**

  * Check the power supply to the servo and ensure it’s correctly connected to **5V** and **GND**.
  * Ensure that the **control pin (Pin 6)** is properly connected to the servo's control wire.

* **Potentiometer not working?**

  * Verify the wiring of the potentiometer. The middle pin should be connected to **Pin A0** on the Arduino.
  * Ensure the **5V** and **GND** pins are connected correctly.

* **Servo moving erratically?**

  * If using a physical setup, make sure the servo has enough power (consider using an external power source for the servo if needed).
  * Ensure that the delay in the code is long enough to prevent erratic movements.
