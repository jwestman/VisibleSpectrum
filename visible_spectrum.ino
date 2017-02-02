#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);

int delayval = 500; // delay for half a second


// http://stackoverflow.com/questions/3407942/rgb-values-of-visible-spectrum

const int rgbs[101][3] = {
  {97,0,97},
  {109,0,115},
  {118,0,132},
  {124,0,149},
  {129,0,165},
  {131,0,181},
  {130,0,196},
  {128,0,211},
  {123,0,226},
  {116,0,241},
  {106,0,255},
  {89,0,255},
  {70,0,255},
  {51,0,255},
  {29,0,255},
  {0,0,255},
  {0,34,255},
  {0,59,255},
  {0,81,255},
  {0,102,255},
  {0,123,255},
  {0,142,255},
  {0,160,255},
  {0,178,255},
  {0,196,255},
  {0,213,255},
  {0,230,255},
  {0,247,255},
  {0,255,234},
  {0,255,192},
  {0,255,146},
  {0,255,97},
  {0,255,40},
  {15,255,0},
  {36,255,0},
  {54,255,0},
  {70,255,0},
  {86,255,0},
  {101,255,0},
  {115,255,0},
  {129,255,0},
  {143,255,0},
  {156,255,0},
  {169,255,0},
  {182,255,0},
  {195,255,0},
  {207,255,0},
  {219,255,0},
  {231,255,0},
  {243,255,0},
  {255,255,0},
  {255,242,0},
  {255,230,0},
  {255,217,0},
  {255,203,0},
  {255,190,0},
  {255,176,0},
  {255,162,0},
  {255,148,0},
  {255,134,0},
  {255,119,0},
  {255,103,0},
  {255,87,0},
  {255,70,0},
  {255,52,0},
  {255,33,0},
  {255,9,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {248,0,0},
  {241,0,0},
  {233,0,0},
  {226,0,0},
  {219,0,0},
  {211,0,0},
  {204,0,0},
  {196,0,0},
  {188,0,0},
  {181,0,0},
  {173,0,0},
  {165,0,0},
  {157,0,0},
  {149,0,0},
  {141,0,0},
  {132,0,0},
  {124,0,0},
  {115,0,0},
  {106,0,0},
  {97,0,0}
};


void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // put current color in bin-1, previous bin-0, next bin-2
  int delta = 5; // positive
  
  for (int idx=0+delta; idx<101-delta; idx++) {
    pixels.setPixelColor(0, pixels.Color(rgbs[idx-delta][0], rgbs[idx-1][1], rgbs[idx-1][2]));
    pixels.setPixelColor(1, pixels.Color(rgbs[idx][0], rgbs[idx][1], rgbs[idx][2]));
    pixels.setPixelColor(2, pixels.Color(rgbs[idx+delta][0], rgbs[idx+1][1], rgbs[idx+1][2]));
    pixels.show();
    delay(100);
  }

  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.show();
  
  delay(2000);

}
