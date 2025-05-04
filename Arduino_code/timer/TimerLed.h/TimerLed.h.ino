#include <Adafruit_NeoPixel.h> //librairie neopixel LS2812
#include <Adafruit_NeoPixel.h>

const int kPin = 4; // Pin connected to the LED strip
const int kNumberOfLed = 2; // Number of LEDs

const int kSwitchPinForward = 45;  // use to detect 3 point switch position
const int kSwitchPinBackward = 47;  // use to detect 3 point switch position

int kLightTrailSpeed = 50; //increase for faster rainbow
uint8_t kHue = 0;  // it will store the hue value when switch is in neutral position

Adafruit_NeoPixel pixels(kNumberOfLed, kPin, NEO_GRB + NEO_KHZ800); //create an object (instance of a class) named pixels of type Adafruit_NeoPixel.
//third argument is the pixel type. You choose it from a list furnished by Adafruit_NeoPixel.h