#include <Adafruit_NeoPixel.h>

const int kPin = 4; // Pin connected to the LED strip
const int kNumberOfLed = 1
; // Number of LEDs

const int kSwitchPinForward = 45;  // White wire (switch signal)
const int kSwitchPinBackward = 47;  // Brown wire (switch signal)

int kUpdateSpeed = 8; //increase for faster rainbow
uint8_t kHue = 0;  // it will store the hue value when switch is in neutral position


Adafruit_NeoPixel pixels(kNumberOfLed, kPin, NEO_GRB + NEO_KHZ800); //create an object (instance of a class) named pixels of type Adafruit_NeoPixel.
//third argument is the pixel type. You choose it from a list furnished by Adafruit_NeoPixel.h

#define DELAYVAL 1000 //the keyword #define is not a type such as int. 
//It tells to replace every instances of DELAYVAL (a name we choose) by 1000 before the code is compiled. 
//Advantage: it don't take memory as a variable of type int would.

void setup() { //this is a mandatory function of type void that runs once before loops and set things up
  if (kUpdateSpeed == 0) { //avoid a division by 0
  kUpdateSpeed++;
  
  }
  pinMode(kSwitchPinForward, INPUT_PULLUP);  // Enable internal pull-up resistor on given pin. the pin will read HIGH it avoid floating issue.
  pinMode(kSwitchPinBackward, INPUT_PULLUP);   
  Serial.begin(9600); // Set baud rate. this allows debugging message to be send to the serial monitor.
  delay(1000); // Give Serial Monitor time to connect
  Serial.println("Starting LED debug...");
  
  //good practice to run those 3 functions
  pixels.begin(); // set the pin given in pixels argument as an output.
  pixels.clear(); // Clear all pixels 
  pixels.show();  // update the pixel state.
  InitializePixelRed(); //set pixel red to begin
}

// Print pixel rgb value for debugging
void printPixelData() {
  Serial.print("Pixel Data: ");
  uint8_t* ledData = pixels.getPixels(); //this function return a pointer of type uint8_t that we named ledData
  
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
  for(int i = 0; i < kNumberOfLed; i++){ //set each led in the chain to red
  pixels.setPixelColor(i, pixels.Color(150, 0, 0)); //first argument = number of led in the chain, second argument = rgb value.
  }
  pixels.show();  // Update LED strip
  printPixelData(); // Debug output
  delay(DELAYVAL);
}


void showRainbow() {
  for (int i = 0; i < 256; i++) {
    kHue = kHue + 256 % 65536; //modulo (what remains after division) to loop hue back to 0 when it reach 65536. adding 256 each step because I want a full loop in 256 step. 256*256 = 65536
    pixels.rainbow(kHue); // Start rainbow effect based on paused hue. Increase value
    pixels.show();  // Update LED strip
    delay(10); // Small delay to slow down the rainbow effect
  }
}


void showRainbowReverse() {
  for (int i = 0; i < 256; i++) {
    kHue = kHue - 256 % 65536;
    pixels.rainbow(kHue); // Start rainbow effect based on paused hue. Decrease value
    pixels.show();  // Update LED strip
    delay(10); // Small delay to slow down the rainbow effect
  }
}

void loop() {  

const bool switchStateLeft = digitalRead(kSwitchPinForward) == LOW;  // determine the position of the button by reading the state of the pin is LOW when switch connect it to gnd
const bool switchStateRight = digitalRead(kSwitchPinBackward) == LOW;

  if (switchStateLeft) { // If the switch is in Left position kpin 45 reads LOW 

    showRainbow();
    pixels.show();  // Update LED strip
    Serial.println("reverse Rainbow activated");
    printPixelData();  // Debug output
    delay(DELAYVAL/kUpdateSpeed);
  } else if (switchStateRight) { // If the switch is in Right position kpin 47 reads LOW
 
    showRainbowReverse();
    pixels.show();  // Update LED strip
    Serial.println("reverse Rainbow activated");
    printPixelData();  // Debug output
    delay(DELAYVAL/kUpdateSpeed);
  } else {

    delay(DELAYVAL); //do nothing
  }
}
