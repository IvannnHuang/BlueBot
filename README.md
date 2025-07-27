# BluBop: Joystick-Driven Earthquake Response Robot

**BluBop** is a two-wheeled robot designed to navigate using joystick input—unless interrupted by earthquake-like vibrations. When the vibration sensor detects high activity, BluBop halts and signals that movement is unsafe. The system combines analog and digital signal processing, PWM motor control, and vibration safety logic.
> ![View Full Project Report and Demo] (https://pages.github.coecis.cornell.edu/ece3140-sp2024/atu2-qh229-tc543/)

---

## Project Goal

To build a mobile robot that:
- Responds to **joystick movement**
- Prioritizes **vibration detection**
- Halts during simulated earthquake events to prevent motion
- Uses **PWM-controlled servo motors** for movement

---

## Hardware Overview

- **FRDM-KL46Z Microcontroller Board**
- **Joystick**:  
  - X-axis → `PTE0` (analog)  
  - Y-axis → `PTE1` (analog)
- **Vibration Sensor**:  
  - Digital input → `PTE31` (`HIGH` = vibration detected)
- **Two Servo Motors**:  
  - Controlled via PWM:  
    - Motor 1 → `PTB0`  
    - Motor 2 → `PTB1`
- **Power Wiring**:  
  All components powered through a single 5V and GND pin via soldered connections.

---

## Software Components

### `analog.h`
- `PWM_init()` — Initializes ADC channels on `PTE0` and `PTE1`.
- `analogRead(channel)` — Returns 10-bit analog value from joystick (0–1023).

### `pwm.h`
- `PWM_init()` — Sets up PWM on TPM channels for motors (`PTB0`, `PTB1`).
- `set_PWM(channel, dutyCycle)` — Sends PWM signal with 0–100% duty cycle.

### `vibration_handler`
- Vibration signal is monitored via digital input.
- When active for multiple cycles, it overrides joystick control to halt the robot.
- Loop counter debounces false triggers due to robot wobble.

---

## Testing & Debugging

### Physical Testing
- Verified pin mappings using the **FRDM-KL46Z datasheet**.
- Adjusted soldered connections and support legs to stabilize robot during motion.
- Tested servo responses with joystick in all 9 cardinal directions.
- Simulated vibrations by shaking/hitting the table and observed motor shutdown behavior.

### Code Debugging
- Used serial print statements to validate:
  - ADC values from joystick
  - Vibration detection logic
  - PWM duty cycle settings
- Tuned motor response ranges using a custom `map()` function.
- Debugged ADC and TPM configurations (clock, channel mapping, calibration).

---

## Key Challenges

- Balancing robot support to prevent false vibration triggers.
- Managing ADC channels and clock setup for joystick input.
- Fine-tuning PWM signals for smooth motor control.

---

## Demo & Images

> Add a GIF or video of BluBop in action here (e.g. `img/blubop_demo.gif`)

```markdown
![BluBop Demo](img/blubop_demo.gif)
