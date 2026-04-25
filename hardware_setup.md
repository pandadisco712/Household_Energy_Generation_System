# Hardware Setup

## Power Configuration

### Motor Power (LiPo Battery)
- Battery **+** → Motor Driver **VIN+**
- Battery **-** → Motor Driver **VIN- (GND)**

### Arduino Power
- Arduino powered via **USB**

### Common Ground (IMPORTANT)
- Arduino **GND** → Motor Driver **GND (VIN-)**

---

## Motor Driver Connections

| Motor Driver Pin | Arduino Pin |
|----------------|------------|
| IN1            | D8         |
| IN2            | D9         |
| ENA            | D10 (PWM)  |

> Ensure ENA is connected to D10 and **no jumper** is present on ENA.

---

## Motors

### Motor 1 (Drive Motor / Fan Simulation)
- Connected to **Motor Driver Output (MOTOUT1)**
- Responsible for rotating the wheel

### Motor 2 (Generator Motor)
- Connected via **wheel-to-wheel contact**
- Generates electrical energy

| Motor 2 Wire | Connection |
|-------------|-----------|
| Red         | LED positive |
| Black       | GND |

---

## LEDs (Household Simulation)

Two LEDs connected **in parallel**, each with its own resistor.

### LED 1 – Lighting
- Long leg → Generator motor red wire  
- Short leg → 220Ω resistor → GND  

> If adding multiple LEDS (max 3), each LED must have its **own resistor**

---

## LCD (16x2)

| LCD Pin | Connection |
|--------|-----------|
| VSS    | GND       |
| VDD    | 5V        |
| V0     | GND (fixed contrast) |
| RS     | D7        |
| RW     | GND       |
| E      | D6        |
| D4     | D5        |
| D5     | D4        |
| D6     | D11       |
| D7     | D12       |
| A      | 5V        |
| K      | GND       |

---

## Potentiometer (Speed Control)

| Pin | Connection |
|----|-----------|
| Left | GND |
| Right | 5V |
| Middle | A2 |

---

## Push Button

| Pin | Connection |
|----|-----------|
| One side | D2 |
| Other side | GND |

> Uses `INPUT_PULLUP` in code

---

## Voltage Sensing

- Generator output → **A0**
- Used to display generated voltage on LCD

---

## Mechanical Setup

- Two motors placed **side by side**
- Wheels are **glued to eachother/connected by an axle**

---

## 🔁 System Flow
- LiPo Battery → Motor Driver → Motor 1 (Fan)
- Motor 1 → Mechanical Rotation → Motor 2 (Generator)
- Motor 2 → Electrical Output → LEDs + Arduino (A0 sensing)

---

## ⚠️ Important Notes

- All grounds must be **common**
- ENA must be connected to **PWM pin (D10)**
- LCD contrast is fixed by connecting **V0 → GND**
- Wheels should have **firm but light contact**
- Use **red LEDs** for better visibility at low voltage

---

## 🧠 Summary

This system demonstrates a **household energy generation concept**, where rotational motion (simulated fan)<br>
is converted into electrical energy and used to power small loads like lights, reducing dependency on external electricity.