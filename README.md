# BlackJam | Arduino Jamming

## Overview

**BlackJam** is a **Bluetooth jammer** built for the **Arduino Uno** and **Arduino Nano** using the **nRF24L01+** module. It was created by **Zorikos3** on Discord! The primary function of **BlackJam** is to **disrupt Bluetooth and BLE signals** by flooding channels with random data and hopping through frequencies, creating interference within the 2.4 GHz ISM band.

> ⚠️ **Disclaimer**: **Jamming** is illegal in many countries and can cause serious disruptions to communication systems. **BlackJam** is intended for **educational purposes only** and should not be used to interfere with legal or protected communication networks. Use responsibly and within the limits of the law.

---

## Features

- **Channel Hopping**: Changes frequencies quickly within the 2.4 GHz ISM band to simulate interference.
- **Garbage Data Flooding**: Sends random data to flood the selected channels, potentially disrupting communication.
- **High Power Transmission**: Uses the `RF24_PA_HIGH` setting for maximum power output (be cautious of potential overheating).
- **Compact Design**: Easy to implement on both **Arduino Uno** and **Arduino Nano** platforms with the **nRF24L01+**.

---

## Hardware Requirements

- **Arduino Uno** or **Arduino Nano**
- **nRF24L01+ Module**
- **10µF Capacitor** (optional, for stabilizing power)
- **Wires for Connections**

---

## Pin Connections

### nRF24L01+ → Arduino Connections:
| **nRF24L01+ Pin** | **Arduino Pin** |
|-------------------|-----------------|
| GND               | GND             |
| VCC               | 3.3V            |
| CE                | D9              |
| CSN               | D10             |
| SCK               | D13             |
| MOSI              | D11             |
| MISO              | D12             |
| IRQ               | Not used        |

---

## Software Requirements

- **Arduino IDE**: Install the latest version of the Arduino IDE.
- **RF24 Library**: Install the **RF24** library for communicating with the **nRF24L01+** module.

---

## Installation Instructions

1. **Set up the Hardware**:
   - Connect the **nRF24L01+** module to the **Arduino** as per the pin connections above.
   - Optionally, add a **10µF capacitor** between **VCC** and **GND** to stabilize the power supply.

2. **Install the Arduino IDE**:
   - Download and install the latest version of the [Arduino IDE](https://www.arduino.cc/en/software).

3. **Install the RF24 Library**:
   - Open the Arduino IDE and go to **Sketch** > **Include Library** > **Manage Libraries**.
   - Search for **RF24** and click **Install** on the **RF24 by TMRh20** library.

4. **Upload the Code**:
   - Open the provided `BlackJam` code in the Arduino IDE.
   - Select the correct **Arduino board** (Uno or Nano) and the appropriate **port** under **Tools**.
   - Click the **Upload** button to upload the code to your Arduino.

---

## Usage

Once the code is uploaded, **BlackJam** will:

1. **Start hopping** through predefined channels in the **2.4 GHz ISM band**.
2. **Send random data packets** across those channels to disrupt devices that are using the same frequencies.
3. **Flood** the frequencies with interference in an attempt to jam nearby Bluetooth or BLE signals.

The module will continue to operate, causing interference until you turn off the Arduino.

---

## Important Notes

- **Legal Warning**: The use of signal jammers is illegal in most countries and can interfere with communication systems. **BlackJam** is for **educational purposes** only, and you should ensure you're following local laws and regulations.
- **Overheating**: Running the **nRF24L01+** at high power settings for extended periods can cause the module to overheat. Consider adding a **capacitor** for better stability.
- **Not So Powerful**: While **BlackJam** can cause interference in the 2.4 GHz band, it is not a specialized Bluetooth or BLE jammer at full jamming because its based on Arduino and a Single NRF24.

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## Credits

- Created by **Zorikos3** on Discord.
- Based on the **nRF24L01+** library by **TMRh20**.
