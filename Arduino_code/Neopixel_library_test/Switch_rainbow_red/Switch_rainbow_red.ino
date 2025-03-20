#include <Adafruit_NeoPixel.h>

const int kPin = 4; // Pin connected to the LED strip
const int kNumberOfLed = 2; // Number of LEDs

const int kSwitchPin = 47;  // Brown wire (switch signal)

Adafruit_NeoPixel pixels(kNumberOfLed, kPin, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) between updates

bool switchState = false;

void setup() {
  pinMode(kSwitchPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  Serial.begin(9600); // Start serial communication
  delay(1000); // Give Serial Monitor time to connect
  Serial.println("Starting LED debug...");
  
  pixels.begin(); // Initialize NeoPixel strip object
  pixels.clear(); // Clear all pixels initially
  pixels.show();  // Send update to turn off all LEDs
}

// Print pixel rgb value for debugging
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

// Set all LEDs Red
void InitializePixelRed() {
  pixels.setPixelColor(0, pixels.Color(150, 0, 0)); 
  pixels.setPixelColor(1, pixels.Color(150, 0, 0)); 
  pixels.show();  // Update LED strip
  printPixelData(); // Debug output
  delay(DELAYVAL);
}

// Function to display the rainbow effect
void showRainbow() {
  for (int i = 0; i < 256; i++) {
    pixels.rainbow(i); // Start rainbow effect with changing hue
    pixels.show();  // Update LED strip
    delay(10); // Small delay to slow down the rainbow effect
  }
}

void loop() {  
  // Read the state of the switch pin (whether it's HIGH or LOW)
  switchState = digitalRead(kSwitchPin) == HIGH;  // Switch is active (LOW) when pressed
  static uint16_t first_hue = 0;  // Start hue value

  if (switchState) {
    // If the switch is in Left or Right position (LOW state)
    pixels.clear();
    InitializePixelRed();  // Display Red LED
  } else {
    // If the switch is in Center position (HIGH state)
    pixels.rainbow(first_hue, 1, 255, 255, true);
    pixels.show();  // Update LED strip
    first_hue += 256;  // Increase hue for next cycle
    Serial.println("Rainbow activated");
    printPixelData();  // Debug output
    delay(DELAYVAL/8);
  }
}
