# Transmission Line Fault Detection System

An embedded real-time monitoring and protection system designed to detect, classify, locate, and isolate electrical transmission line faults using microcontroller technology and wireless communication[cite: 1, 3].

## 📌 Project Overview
Transmission line faults such as short circuits, line-to-ground, line-to-line, and three-phase faults interrupt power supply and risk severe equipment damage. Traditional manual inspection methods are slow and expensive, especially in developing regions like Ethiopia. 

This project provides an automated, low-cost solution using an **Arduino** microcontroller, **ACS712 current sensors**, and **ZMPT101B voltage sensors** to monitor transmission line status in real time[cite: 1, 3]. Upon detecting an abnormality, the system calculates the approximate fault distance using line parameters, isolates the affected section via relays, displays details on a local LCD/OLED, and dispatches SMS alerts via a GSM module (or transmits telemetry data over serial JSON via NodeMCU)[cite: 1, 3].

---

## ✨ Key Features
* **Real-time Monitoring:** Continuous sampling of voltage and current signals across phases to compute RMS values.
* **Fault Classification:** Automatically identifies line-to-ground (LG), line-to-line (LL), double line-to-ground (LLG), and three-phase ($3\Phi$) faults[cite: 1, 3].
* **Fault Distance Estimation:** Calculates approximate distance to the fault using line impedance characteristics[cite: 1, 3, 4].
* **Automated Isolation:** Controls trip relays to quickly isolate faulty segments and prevent broader grid damage[cite: 1, 3].
* **Multi-Channel Alerts:**
  * **Local:** LCD/OLED visual readout with an audible buzzer alert[cite: 1, 3, 4].
  * **Remote:** GSM module SMS notifications and NodeMCU JSON telemetry for remote monitoring[cite: 1, 3].

---

## 📁 Repository Structure

.
├── Three phase transmission line project/
│   ├── 3 phase detection system.ino   # Main firmware for 3-phase current/voltage monitoring & classification
│   └── Three Phase project.pdsprj     # Proteus schematic simulation project file
├── Transmission-Line_Fault_Detection.../
│   ├── fault detector.ino            # Alternative/modular fault detection firmware implementation
│   └── main                          # Compiled binary / secondary source file
└── README.md                          # Repository documentation

## 🛠️ System Architecture & Hardware Components

| Component | Description / Specification | Qty |
| :--- | :--- | :---: |
| **Arduino Uno** | ATmega328P main controller board | 1 |
| **GSM Module** | SIM800L / SIM900 for SMS alerts | 1 |
| **Current Sensors** | ACS712 (20A/30A) module | 2 |
| **Voltage Sensors** | ZMPT101B voltage sensor module | 2 |
| **Display** | 16x2 LCD or 0.96" I2C SSD1306 OLED | 1 |
| **Relay Module** | 2-Channel 5V relay module for line isolation | 1 |
| **Indicators** | Buzzer + LED array for local status alerts | 1 set |
| **Power Supply** | Regulated 12V to 5V (7805 regulator) circuit | 1 |

---

## 💻 Software & Firmware Flow

The firmware executes through the following operational pipeline:

1. **Peripheral Setup:** Initializes LCD display, NodeMCU/GSM serial communications (`SoftwareSerial`), and configures sensor pin modes[cite: 3].
2. **Data Acquisition:** Samples analog inputs ($A0$–$A3$) across a $1\text{ second}$ window to compute peak-to-peak and RMS current/voltage readings[cite: 3, 4].
3. **Threshold Comparison:** Evaluates computed RMS values against configured `pickup_current` safety limits[cite: 3].
4. **Fault Processing:**
   * Classifies the fault condition ($3\Phi$, LL, LG, or LLG)[cite: 3].
   * Maps current thresholds to calculate estimated fault distance ($2\text{ km}$, $4\text{ km}$, $6\text{ km}$, $8\text{ km}$)[cite: 3].
   * Triggers the isolation relay (Digital Pin 7) and local alarms (Buzzer/LED)[cite: 3, 4].
5. **Telemetry Dispatch:** Encapsulates live readings and fault status into JSON format via `StaticJsonBuffer` and streams data over serial to NodeMCU/GSM[cite: 3].

---

## 🧪 Simulation & Development Tools

* **IDE:** Arduino IDE (C/C++ embedded programming)
* **Compiler:** AVR-GCC
* **Circuit Simulation:** Proteus Design Suite (`Three Phase project.pdsprj`)
* **Communication Protocols:** UART (GSM/NodeMCU serial), I2C (OLED/LCD display interface)

---

## 🚀 How to Try It Out

### Option 1: Simulation via Proteus (Recommended)
1. Install **Proteus Design Suite** on your system.
2. Open the project file: `Three phase transmission line project/Three Phase project.pdsprj`.
3. Open **Arduino IDE**, load `3 phase detection system.ino`[cite: 3], and make sure you have the required libraries installed (`SoftwareSerial`, `ArduinoJson`, `LiquidCrystal`)[cite: 3].
4. In Arduino IDE, go to **Sketch > Export compiled Binary** to generate the `.hex` file.
5. In Proteus, double-click the **Arduino Uno** component and set the Program File path to the generated `.hex` file.
6. Click **Play** in Proteus to run the interactive circuit simulation.

### Option 2: Physical Hardware Setup
1. Wire the components according to the pin configuration defined in the source code:
   * **LCD Display:** Pins 12, 11, 5, 4, 3, 2[cite: 3]
   * **NodeMCU / Serial:** Pins 9 (RX), 10 (TX)[cite: 3]
   * **Sensors:** Analog pins `A0`, `A1`, `A2`, `A3`[cite: 3]
   * **Relay Output:** Pin 7[cite: 3]
   * **Buzzer:** Pin 13[cite: 3]
2. Connect your Arduino Uno to your PC via USB.
3. Open `3 phase detection system.ino`[cite: 3] in Arduino IDE, select your board and serial port, and click **Upload**.
4. Open the Serial Monitor (set to 9600 baud) to view real-time RMS current logs and fault alerts[cite: 3].

---

## 📜 References

* **Arduino:** [Arduino Uno Rev3 Documentation](https://store.arduino.cc/products/arduino-uno-rev3)
* **SIMCom:** SIM800L GSM/GPRS Module Datasheet
* **Adafruit:** SSD1306 OLED Display Datasheet
* **Literature:** R. C. Dorf & J. A. Svoboda, *Introduction to Electric Circuits*, 9th ed.
