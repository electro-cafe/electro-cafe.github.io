#include <Adafruit_NeoPixel.h>

const int kPin = 4; // Pin connected to the LED strip
const int kNumberOfLed = 2; // Number of LEDs

Adafruit_NeoPixel pixels(kNumberOfLed, kPin, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) between updates

void setup() {
  Serial.begin(9600); // Start serial communication
  delay(1000); // Give Serial Monitor time to connect
  Serial.println("Starting LED debug...");
  
  pixels.begin(); // Initialize NeoPixel strip object
  pixels.clear(); // Clear all pixels initially
  pixels.show();  // Send update to turn off all LEDs
}

void printPixelData() {
  Serial.print("Pixel Data: ");
  uint8_t* ledData = pixels.getPixels();
  
  for (int i = 0; i < kNumberOfLed; i++) {
    int r = ledData[i * 3];     // Red
    int g = ledData[i * 3 + 1]; // Green
    int b = ledData[i * 3 + 2]; // Blue

    Serial.print("[");
    Serial.print(r); Serial.print(", ");
    Serial.print(g); Serial.print(", ");
    Serial.print(b);
    Serial.print("] ");
  }
  Serial.println(); // New line for readability
}

void loop() {
  
  pixels.setPixelColor(0, pixels.Color(0, 150, 0)); 
  pixels.setPixelColor(1, pixels.Color(0, 0, 150)); 
  pixels.show();  // Update LED strip
  printPixelData(); // Debug output
  delay(DELAYVAL);

  // All LEDs Red
  pixels.setPixelColor(0, pixels.Color(80, 14, 150));
  pixels.setPixelColor(1, pixels.Color(150, 200, 60));
  pixels.show();
  printPixelData(); // Debug output
  delay(DELAYVAL);

  // Clear LEDs
  pixels.clear();
  pixels.show();
  Serial.println("Clearing LEDs...");
  delay(DELAYVAL);
}
