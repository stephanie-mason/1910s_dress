/* DONE IN A RUSH, COULD BE MUCH MORE DRY */
/*** LIBRARIES ***/
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/*** CONSTANTS ***/
#define NUM_STRIPS 7
#define COLOR_ORDER GRB
#define NUM_TAIL_LEDS 107
#define NUM_BODY_LEDS 34
#define NUM_NECK_LEDS 24
#define BRIGHTNESS 40
#define SATURATION 255

/*** FASTLED SETUP ***/
CRGB tail_leds[NUM_TAIL_LEDS];
CRGB body_leds[NUM_BODY_LEDS];
CRGB neck_leds[NUM_NECK_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

/*** VARIABLES ***/
uint16_t animationSpeed = 30;
int animationMode = 9;
uint8_t numAnimations = 9;
uint8_t startIndex = 0;
uint8_t steps = 10;
uint8_t gHue = 0; 

/*** STRIPS ***/
/** Pin 0, Tail **/
uint8_t stripOne[9] = {8,7,6,5,4,3,2,1,0};
uint8_t stripTwo[17] = {9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
uint8_t stripThree[18] = {43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26};
uint8_t stripFour[19] = {44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62};
uint8_t stripFive[18] = {80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63};
uint8_t stripSix[17] = {81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97};
uint8_t stripSeven[9] = {106,105,104,103,102,101,100,99,98};

/** Pin 1, Beaded Body Pieces **/
/* Back */
uint8_t stripEight[5] = {4,3,2,1,0};
uint8_t stripNine[10] = {5,6,7,8,9,10,11,12,14};
uint8_t stripTen[5] = {19,18,17,16,15};
/*Front*/
uint8_t stripEleven[4] = {23,22,21,20};
uint8_t stripTwelve[6] = {24,25,26,27,28,29};
uint8_t stripThirteen[4] = {33,32,31,30};

/** Pin 2, Neck **/
uint8_t stripFourteen[12] = {11,10,9,8,7,6,5,4,3,2,1};
uint8_t stripFifteen[12] = {12,13,14,15,16,17,18,19,20,21,22,23};

/*** PALETTE FUNCTION DECLARATIONS ***/
extern const TProgmemPalette16 BriteNoBlack_p PROGMEM;
extern const TProgmemPalette16 BriteWithBlack_p PROGMEM;
extern const TProgmemPalette16 Love_p PROGMEM;
extern const TProgmemPalette16 RedTeal_p PROGMEM;
extern const TProgmemPalette16 PewPew_p PROGMEM;
extern const TProgmemPalette16 Vaporwave_p PROGMEM;
extern const TProgmemPalette16 Purple_p PROGMEM;
extern const TProgmemPalette16 Pink_p PROGMEM;
extern const TProgmemPalette16 White_p PROGMEM;

/*** SETUP ***/
void setup() {
  // Trinket 5V 16MHz, do not remove
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  // Safety Delay
  delay(3000);

  // FastLED Setup
  FastLED.addLeds<WS2812B, 0, COLOR_ORDER>(tail_leds, NUM_TAIL_LEDS).setCorrection( TypicalLEDStrip ); /* Pin 0 - Tail */
  FastLED.addLeds<WS2812B, 1, COLOR_ORDER>(body_leds, NUM_BODY_LEDS).setCorrection( TypicalLEDStrip ); /* Pin 1, Beaded Body Pieces */
  FastLED.addLeds<WS2812B, 2, COLOR_ORDER>(neck_leds, NUM_NECK_LEDS).setCorrection( TypicalLEDStrip ); /* Pin 2, Neck */
  FastLED.setBrightness(BRIGHTNESS);
  currentBlending = LINEARBLEND;
  currentPalette = Vaporwave_p;
}
