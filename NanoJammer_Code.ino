#include "RF24.h" // Adding RF24 Library

RF24 radioModule(5, 2, 16000000); // CE = 5 | CSN = 2 | SPI = 16MHz

const byte frequencyPattern[] = {  
  32, 34, 46, 48, 50, 52,      // High Frequency Channels
  0, 1, 2, 4, 6, 8,            // Low Frequency Channels
  22, 24, 26, 28, 30,          // Mid-Range Channels
  74, 76, 78, 80, 82, 84, 86   // Bluetooth Channels
};

byte patternIndex = 0;
const size_t patternSize = sizeof(frequencyPattern);

void initializeTransmitter() {
  radioModule.begin();
  radioModule.startConstCarrier(RF24_PA_MAX, 45); // Start continuous carrier wave transmission at maximum power on channel 45!
  radioModule.setDataRate(RF24_2MBPS); // Data to 2MBPS to get full power!
}

void setup() {
  initializeTransmitter();
}

void loop() {
  patternIndex = (patternIndex + 1) % patternSize;
  radioModule.setChannel(frequencyPattern[patternIndex]);
  // Optional: Add a small delay if needed for stability:
  // delayMicroseconds(100);
}
