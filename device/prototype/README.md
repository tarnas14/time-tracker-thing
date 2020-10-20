# ESP32-based Prototype

## Hardware

### Nodemcu ESP32 WROOM

These are ESP32-D0WD-based modules with integrated flash. These modules are well suited for Wi-Fi and Bluetooth/Bluetooth LE-based connectivity applications and provide a solid dual-core performance.

### GY-521

GY-521 is module with accelerometer, gyroscope and even a thermomether on-board! All this data is accessible via `I2S` protocol (aka `TWI` aka `I2C`).

### Setup

| ESP Pin | GY-521 Pin | Description      |
| ------- | ---------- | ---------------- |
| D21     | SDA        | `I2S` data line  |
| D23     | SCL        | `I2S` clock line |
| 3V3     | VCC        | Power supply +   |
| GND     | GND        | Power supply -   |

## Development

1. Install Arduino studio and drivers for ESP32.
1. Connect ESP32 board to USB port, make sure it's accessible via `COM` port.
1. Open the project in Arduino studio.
1. Change some code
1. Upload it to the device!
