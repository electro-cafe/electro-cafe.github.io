//9.4.25 
//I struggled with the hue parameter of the rainbow method. turns out I can find it's imblementation body on my computer
// under Documents\Arduino\libraries\Adafruit_NeoPixel\Adafruit_NeoPixel.cpp or on github also in Adafruit_NeoPixel.cpp

//void Adafruit_NeoPixel::rainbow(uint16_t first_hue, int8_t reps,
//  uint8_t saturation, uint8_t brightness, bool gammify) {
//  for (uint16_t i=0; i<numLEDs; i++) {
//    uint16_t hue = first_hue + (i * reps * 65536) / numLEDs;
//    uint32_t color = ColorHSV(hue, saturation, brightness);
//    if (gammify) color = gamma32(color);
//    setPixelColor(i, color);
//  }
//}

//turns out it only asign a gradient of color along the pixel chain x amount of time, there is no animation
//we trick the animation by calling rainbow in a loop and ofseting each time the first_hue

//22.4.25 
//I'll add the stepper code from exemple and adapt it

#include <Adafruit_NeoPixel.h>
#include <Stepper.h>

const int kPin = 4; // Pin connected to the LED strip
const int kNumberOfLed = 2
; // Number of LEDs

const int kSwitchPinForward = 45;  // White wire (switch signal)
const int kSwitchPinBackward = 47;  // Brown wire (switch signal)

int kUpdateSpeed = 50; //increase for faster rainbow
uint8_t kHue = 0;  // it will store the hue value when switch is in neutral position

const int kStepsPerRevolution = 400;  // change this to fit the number of steps per revolution of motor
const int kStepIncrement = 60;
int kMotorSpeed = 60;



Adafruit_NeoPixel pixels(kNumberOfLed, kPin, NEO_GRB + NEO_KHZ800); //create an object (instance of a class) named pixels of type Adafruit_NeoPixel.
//third argument is the pixel type. You choose it from a list furnished by Adafruit_NeoPixel.h

Stepper myStepper(kStepsPerRevolution, 15, 17, 16, 18); // initialize the stepper library on pins 15 through 18. Important note :
//the argument order doesn't match the pin order, this is because inside the steper the 4 coil are not wired in a logical order.
//to gain space they wire in order 1 3 2 4 so we have to give the argument following this order or cross the wires

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
  pixels.setBrightness(5); // dim the light, scale 0 to 255.
  pixels.clear(); // Clear all pixels 
  pixels.show();  // update the pixel state.
  InitializePixelRed(); //set pixel red to begin

  myStepper.setSpeed(kMotorSpeed);
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
  Serial.print("set led red");
  printPixelData(); // Debug output
  delay(DELAYVAL);
}


void showRainbow() {
  
    kHue++;//increment hue
    pixels.rainbow(kHue*256); // Start rainbow effect based on paused hue. 
    pixels.show();  // Update LED strip
    delay(DELAYVAL/kUpdateSpeed); // Small delay to slow down the rainbow effect
}


void showRainbowReverse() {
  
  
    kHue--;
    pixels.rainbow(kHue*256); // Start rainbow effect based on paused hue. we have to multiply by 256 as it expect a 
    pixels.show();  // Update LED strip
    delay(DELAYVAL/kUpdateSpeed); // Small delay to slow down the rainbow effect
}

void loop() {  

const bool switchStateLeft = digitalRead(kSwitchPinForward) == LOW;  // determine the position of the button by reading the state of the pin is LOW when switch connect it to gnd
const bool switchStateRight = digitalRead(kSwitchPinBackward) == LOW;

  if (switchStateLeft) { // If the switch is in Left position kpin 47 reads LOW 

    showRainbow();
    pixels.show();  // Update LED strip
    Serial.println("reverse Rainbow activated");
    printPixelData();  // Debug output
    delay(DELAYVAL/kUpdateSpeed);
    myStepper.step(kStepIncrement);
  } else if (switchStateRight) { // If the switch is in Right position kpin 45 (white thread) reads LOW
 
    showRainbowReverse();
    pixels.show();  // Update LED strip
    Serial.println("reverse Rainbow activated");
    printPixelData();  // Debug output
    delay(DELAYVAL/kUpdateSpeed);
    myStepper.step(-kStepIncrement);
  } else {

    delay(DELAYVAL); //do nothing
  }
}