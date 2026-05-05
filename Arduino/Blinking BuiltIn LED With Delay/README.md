# **Blinking BuiltIn LED With Delay Project**

## **Description**

This Arduino project demonstrates how to blink the built-in LED (usually connected to pin 13 on most Arduino boards). The LED blinks on and off at 1-second intervals. This is an excellent beginner project that teaches how to control the built-in LED and use the **`LED_BUILTIN`** constant to refer to the built-in LED pin.

## **Features**

* Blinks the **built-in LED** on the Arduino board at a 1-second interval.
* No external components are needed (except for the Arduino itself).
* The project can be easily replicated both in **Tinkercad** and on **real hardware**.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or any Arduino with a built-in LED)
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**
   >![Circuit Diagram](<../../assets/images/Blinking BuiltIn LED With Delay.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Add the **Arduino Uno** to your workspace.
4. The **built-in LED** on the Arduino board is already connected to pin 13 by default, so no external components are required for this project in Tinkercad.

### **For Hardware Setup**

* The **built-in LED** on the Arduino is typically connected to **pin 13** by default. Therefore, no external components are necessary unless you plan to use an external LED.
* This project uses **`LED_BUILTIN`** to reference the built-in LED pin (which is usually pin 13 on most Arduino boards).

## **Connection**

| Arduino Pin      | Component                     |
| ---------------- | ----------------------------- |
| **LED\_BUILTIN** | Built-in LED (usually pin 13) |

### **Note**:

* Most Arduino boards have a built-in LED connected to pin 13. If you're using a board that doesn't have a built-in LED, you would need to connect an external LED to pin 13 and use the same code.

## **Code Explanation**

This code blinks the **built-in LED** on the Arduino at a 1-second interval. The **`LED_BUILTIN`** constant is used to reference the built-in LED pin, which eliminates the need for a hardcoded pin number.

### **Code:**

```cpp
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED as output
}

void loop(){
  digitalWrite(LED_BUILTIN, HIGH);  // Turn LED on
  delay(1000);  // Wait for 1 second
  digitalWrite(LED_BUILTIN, LOW);  // Turn LED off
  delay(1000);  // Wait for 1 second
}
```

* **`pinMode(LED_BUILTIN, OUTPUT)`**: Sets the built-in LED as an output.
* **`digitalWrite(LED_BUILTIN, HIGH)`**: Turns the built-in LED on by sending a HIGH signal (5V).
* **`delay(1000)`**: Pauses the program for 1000 milliseconds (1 second).
* **`digitalWrite(LED_BUILTIN, LOW)`**: Turns the built-in LED off by sending a LOW signal (0V).

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project.
   * Add an **Arduino Uno** to the workspace. No additional components are required, as the built-in LED is connected by default to pin 13 on the Arduino.
2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Blocks** or **Text** (either works, but text is easier for this example).
   * Copy and paste the provided code into the editor.
   * Press **Start Simulation** to see the built-in LED blink.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * If you're using an Arduino board with a built-in LED (such as Arduino Uno), you don't need to connect anything to pin 13. The LED is already wired to that pin.
2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect the **Arduino Uno** to your computer via a **USB cable**.
   * Select the correct **board** and **port** under **Tools**.
   * Copy and paste the provided code into the Arduino IDE.
   * Click **Upload** to send the code to your Arduino.
3. **Verify the Output**:

   * Once the code is uploaded, the built-in LED on pin 13 should blink on and off at 1-second intervals.

## **Demo Video**
   > https://github.com/user-attachments/assets/282fc4fe-26c1-473d-9f8d-b3b6fe9020b3



## **Troubleshooting**

* **LED not blinking in Tinkercad?**

  * Make sure you've connected the **Arduino Uno** and selected **Start Simulation**.
  * Ensure the correct code is uploaded into Tinkercad.

* **LED not blinking in hardware setup?**

  * Ensure you're using a board with a built-in LED (like the Arduino Uno).
  * Verify that the **correct board and port** are selected in the Arduino IDE.

* **Arduino not powering?**

  * Make sure the Arduino is connected via USB or an external power supply.
