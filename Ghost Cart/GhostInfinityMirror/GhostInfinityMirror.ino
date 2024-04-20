#include <FastLED.h>

#include "NES_Controller.h"
#include "GhostScreen.h"
#include "OuterRing.h"

#define GHOST_SCREEN_DATA_PIN         2         //  The WS2801 string data pin for the inner ghost screen
#define GHOST_SCREEN_CLOCK_PIN        4         //  The WS2801 string clock pin for the inner ghost screen
#define OUTER_RING_DATA_PIN           6         //  The WS2801 string data pin for the outer ring lights
#define OUTER_RING_CLOCK_PIN          8         //  The WS2801 string clock pin for the outer ring lights
#define NES_DATA_PIN                  10        //  The Data pin for the NES Controller
#define NES_CLOCK_PIN                 11        //  The Clock pin for the NES Controller
#define NES_LATCH_PIN                 12        //  The Latch pin for the NES Controller

#define LED_BRIGHTNESS                20         //  The number (0 to 200) for the brightness setting)

#define TEST_BED_HARDWARE             true

GhostScreen ghostScreen;
OuterRing outerRing;
NES_Controller nesController(NES_DATA_PIN, NES_CLOCK_PIN, NES_LATCH_PIN);

void SerialProgramInit() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("Program START!");
}

void setup()
{
  //  Initialize the Serial connection for debug output
  if (TEST_BED_HARDWARE) SerialProgramInit();
  
  //  Seed the random number generator
  randomSeed(analogRead(0));

  //  Setup the LED strips up for both Ghost Screen and Outer Ring
  if (TEST_BED_HARDWARE) {
    FastLED.addLeds<WS2812B, GHOST_SCREEN_DATA_PIN, GRB>(ghostScreen.LEDs, ghostScreen.LED_COUNT).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<WS2812B, OUTER_RING_DATA_PIN, GRB>(outerRing.LEDs, outerRing.LED_COUNT).setCorrection( TypicalLEDStrip );
  }
  else {
    FastLED.addLeds<WS2801, GHOST_SCREEN_DATA_PIN, GHOST_SCREEN_CLOCK_PIN, RGB>(ghostScreen.LEDs, ghostScreen.LED_COUNT).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<WS2801, OUTER_RING_DATA_PIN, OUTER_RING_CLOCK_PIN, RGB>(outerRing.LEDs, outerRing.LED_COUNT).setCorrection( TypicalLEDStrip );
  }

  //  Set all LED brightness, then initialize and clear all strips
  FastLED.setBrightness(LED_BRIGHTNESS);
  ghostScreen.Initialize(true);
  ghostScreen.ClearScreen();
  outerRing.ClearScreen();
  FastLED.show();
}

void loop()
{
  //nesController.ReadController();
  /*if (nesController.CheckButton(NES_A_BUTTON)) */outerRing.SwitchPatterns();
  /*if (nesController.CheckButton(NES_B_BUTTON)) */ghostScreen.SwitchPatterns();

  ghostScreen.Render();
  outerRing.Render();

  FastLED.show();
}