  

#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h> 


#define NUMPIXELS 60 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    9
#define CLOCKPIN   8
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup() {


  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  strip.setBrightness(255);
}


// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int currentLED = random(0,60); 
int lastLED = 0;
int blue=0;
int red=255;
int green=40;

void loop() {
  strip.setPixelColor(currentLED, green, red, blue); 
  strip.setPixelColor(lastLED, 0);     
  strip.show();                     
  delay(10);                        
  lastLED = currentLED;
  currentLED = random(0,60);
}
