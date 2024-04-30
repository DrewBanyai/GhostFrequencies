#pragma once

#include "FrameAnimation.h"
#include "Helper.h"

class LED_Screen {
  public:
    unsigned int LED_COUNT = 0;
    CRGB* LEDs;
    String ScreenName;
    int PatternCount;
    FrameAnimationManager FrameAnimation;

    LED_Screen(int ledCount, CRGB* leds, String screenName, int patternCount = 1) {
      LED_COUNT = ledCount;
      LEDs = leds;
      ScreenName = screenName;
      PatternCount = patternCount;
    }

    inline bool IsIndexOnScreen(int index) { return ((index >= 0) && (index < LED_COUNT)); }
    inline void SetScreen(CRGB color) { fill_solid(LEDs, LED_COUNT, color); }
    inline void ClearScreen() { SetScreen(CRGB::Black); }

    const int PATTERN_SWITCH_BUTTON_DELAY = 400;
    unsigned long PatternSwitchTimer = PATTERN_SWITCH_BUTTON_DELAY;
    int PatternIndex = 0;

    inline void SetPatternIndex(int newIndex) { PatternIndex = newIndex; }
    inline bool SwitchPatterns() {
      if (millis() >= PatternSwitchTimer) {
        PatternSwitchTimer = millis() + PATTERN_SWITCH_BUTTON_DELAY;
        ClearScreen();
        ++PatternIndex;
        if (PatternIndex >= PatternCount) PatternIndex = 0;
        Serial.print("Switching Pattern to index ");
        Serial.println(PatternIndex);
        FrameAnimation.ResetAnimation();
        return true;
      }
      return false;
    }

    // 1D Patterns
    void PacmanChase(unsigned int virtualLEDCount, unsigned int frameLengthMillis = 60);
    void RainbowFlow1(unsigned long frameLengthMillis = 5);
    void RainbowFlow2_1D(int speed = 1, bool berzerk = false);
    void Fire(unsigned long frameLengthMillis, byte r = 255, byte g = 175, byte b = 40);
    void ColorFire(unsigned long frameLengthMillis);
    void GlowFlow(const int colorChangeSpeed = 1, const unsigned long changeDelay = 1000);
};


///////////////
// 1D Patterns
///////////////
void LED_Screen::PacmanChase(unsigned int virtualLEDCount, unsigned int frameLengthMillis = 60)
{
  if (FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int pacmanPosition = 0;

    ClearScreen();
    int P1 = ((pacmanPosition >= virtualLEDCount) ? 0 : pacmanPosition);
    int P2 = (((P1 - 3) < 0) ? (virtualLEDCount + P1 - 3) : (P1 - 3));
    int P3 = (((P1 - 5) < 0) ? (virtualLEDCount + P1 - 5) : (P1 - 5));
    int P4 = (((P1 - 7) < 0) ? (virtualLEDCount + P1 - 7) : (P1 - 7));
    int P5 = (((P1 - 9) < 0) ? (virtualLEDCount + P1 - 9) : (P1 - 9));
    
    if (IsIndexOnScreen(P1)) LEDs[P1] = CRGB::Yellow;
    if (IsIndexOnScreen(P2)) LEDs[P2] = CRGB::Red;
    if (IsIndexOnScreen(P3)) LEDs[P3] = CRGB::Cyan;
    if (IsIndexOnScreen(P4)) LEDs[P4] = CRGB::Orange;
    if (IsIndexOnScreen(P5)) LEDs[P5] = CRGB::Magenta;
    
    FastLED.show();
    pacmanPosition = P1 + 1;
  }
}


void LED_Screen::RainbowFlow1(unsigned long frameLengthMillis)
{
  if (FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int delayTime = 5;
    static int hueChange = 5;

    static int hue = 0;
    hue += hueChange;
    fill_rainbow(LEDs, LED_COUNT, hue, -3);
    FastLED.show();
  }
}

void LED_Screen::RainbowFlow2_1D(int speed, bool berzerk)
{
  if (FrameAnimation.IterateFrame(50)) {
    static int rainbowPosition = 0;
    for (int i = 0; i < LED_COUNT; ++i)
    {
      LEDs[i] = Wheel(((i * 256 / LED_COUNT) + rainbowPosition) & 255);
      if (berzerk) rainbowPosition++;
    }
    
    if (!berzerk) rainbowPosition += speed;
    FastLED.show();
  }
}

void LED_Screen::Fire(unsigned long frameLengthMillis, byte r, byte g, byte b)
{
  if (FrameAnimation.IterateFrame(frameLengthMillis)) {
    for (int i = 0; i < LED_COUNT; i++)
    {
      int flicker = random(0,150);
      int r1 = r - flicker;
      int g1 = g - flicker;
      int b1 = b - flicker;
      if (g1 < 0) g1 = 0;
      if (r1 < 0) r1 = 0;
      if (b1 < 0) b1 = 0;
      LEDs[i] = CRGB(r1, g1, b1);
    }
    FastLED.show();
  }
}

void LED_Screen::ColorFire(unsigned long frameLengthMillis)
{
  static int colorChangeSpeed = 5;

  static byte R = random(0, 256);
  static byte G = random(0, 256);
  static byte B = random(0, 256);
    
  R += random(1, (colorChangeSpeed + 1) * 1);
  G += random(1, (colorChangeSpeed + 1) * 2);
  B += random(1, (colorChangeSpeed + 1) * 3);

  Fire(frameLengthMillis, R, G, B);
}


void LED_Screen::GlowFlow(const int colorChangeSpeed, const unsigned long changeDelay)
{
  static Color colorCurrent(0, 0, 0);
  static Color colorDelta(0, 0, 0);
  static bool colorDisplay = true;
  static unsigned long nextChangeTime = 0;
  static bool adding = false;
  
  adding = false;
  if (colorDelta.R > 0) { colorDelta.R -= colorChangeSpeed; colorCurrent.R = min(255, colorCurrent.R + colorChangeSpeed); adding = true; }
  if (colorDelta.G > 0) { colorDelta.G -= colorChangeSpeed; colorCurrent.G = min(255, colorCurrent.G + colorChangeSpeed); adding = true; }
  if (colorDelta.B > 0) { colorDelta.B -= colorChangeSpeed; colorCurrent.B = min(255, colorCurrent.B + colorChangeSpeed); adding = true; }
  if (adding == false)
  {
    if (colorDelta.R < 0) { colorDelta.R += colorChangeSpeed; colorCurrent.R = max(0,   colorCurrent.R - colorChangeSpeed); }
    if (colorDelta.G < 0) { colorDelta.G += colorChangeSpeed; colorCurrent.G = max(0,   colorCurrent.G - colorChangeSpeed); }
    if (colorDelta.B < 0) { colorDelta.B += colorChangeSpeed; colorCurrent.B = max(0,   colorCurrent.B - colorChangeSpeed); }
  }
  
  CRGB currentCRGB(colorCurrent.R, colorCurrent.G, colorCurrent.B);
  fill_solid(LEDs, LED_COUNT, currentCRGB);
  FastLED.show();
    
  if (colorDelta.isLessThan(colorChangeSpeed) && (millis() >= nextChangeTime))
  {
    int newColorIndex = 0;
    do
    {
      newColorIndex = GetRandomVibrantColorIndex();
      
      colorDelta.R = int(COMMON_COLORS[newColorIndex][0]) - colorCurrent.R;
      colorDelta.G = int(COMMON_COLORS[newColorIndex][1]) - colorCurrent.G;
      colorDelta.B = int(COMMON_COLORS[newColorIndex][2]) - colorCurrent.B;
      
    } while (colorDelta.isLessThan(colorChangeSpeed));
    
    nextChangeTime = millis() + (changeDelay);
  }
}