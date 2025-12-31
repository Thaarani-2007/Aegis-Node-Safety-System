# Aegis Node – Safety Alert System

Aegis Node is an ESP32-based safety alert system designed to visually and audibly indicate emergency states such as **crash alerts** and **siren alerts** using a NeoPixel LED ring, buzzer, and push buttons.  
This project is simulated using **Wokwi Online Simulator**.

---

project link: https://wokwi.com/projects/451762073397044225

## 🚀 Features
- 🔴 Crash Mode: Red LED ring with buzzer alert
- 🔵 Siren Mode: Blue LED ring (silent)
- 🟢 Normal Mode: Green LED ring
- 🧠 Button-controlled logic using internal pull-up resistors
- 🔊 Audible alerts using a buzzer
- 🖥️ Serial monitor logs for debugging and status updates

---

## 🧰 Components Used
- ESP32
- NeoPixel LED Ring (16 LEDs)
- Buzzer
- 2 Push Buttons (Crash & Siren)
- Wokwi Online Simulator

---

## 🔌 Pin Configuration

| Component        | ESP32 Pin |
|------------------|----------|
| NeoPixel Ring    | GPIO 15  |
| Buzzer           | GPIO 2   |
| Crash Button     | GPIO 12  |
| Siren Button     | GPIO 14  |

---

## ⚙️ Working Logic

- **Crash Button Pressed**
  - LED Ring turns **Red**
  - Buzzer sounds
  - Serial message: `ALERT: CRASH DETECTED`

- **Siren Button Pressed**
  - LED Ring turns **Blue**
  - Buzzer OFF
  - Serial message: `ALERT: SIREN DETECTED`

- **No Button Pressed**
  - LED Ring turns **Green**
  - System stays in normal mode

---

## ▶️ How to Run the Simulation

1. Open https://wokwi.com
2. Create a new ESP32 project
3. Upload:
   - `sketch.ino`
   - `diagram.json`
4. Click **Run**
5. Use the buttons to trigger different alert modes

---

## 🧪 Simulation Platform
- **Wokwi – Online ESP32 & Arduino Simulator**

 

