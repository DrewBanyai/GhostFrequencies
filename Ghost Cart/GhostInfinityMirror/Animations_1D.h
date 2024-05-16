#pragma once

#include "LED_Screen.h"

///////////////
// 1D Patterns
///////////////
void Anim1D_GlowFlow(LED_Screen* screen, const int colorChangeSpeed = 1, const unsigned long changeDelay = 1000)
{
  static Color colorCurrent(0, 0, 0);
  colorCurrent.ColorShift(colorChangeSpeed, changeDelay);
  CRGB currentCRGB(colorCurrent.R, colorCurrent.G, colorCurrent.B);
  fill_solid(screen->LEDs, screen->LED_COUNT, currentCRGB);
  FastLED.show();
}


void Anim1D_RainbowFlow1(LED_Screen* screen, unsigned long frameLengthMillis = 60)
{
  if (screen->FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int delayTime = 5;
    static int hueChange = 5;

    static int hue = 0;
    hue += hueChange;
    fill_rainbow(screen->LEDs, screen->LED_COUNT, hue, -3);
    FastLED.show();
  }
}


void Anim1D_RainbowFlow2(LED_Screen* screen, int speed, bool berzerk)
{
  if (screen->FrameAnimation.IterateFrame(50)) {
    static int rainbowPosition = 0;
    for (int i = 0; i < screen->LED_COUNT; ++i)
    {
      screen->LEDs[i] = Wheel(((i * 256 / screen->LED_COUNT) + rainbowPosition) & 255);
      if (berzerk) rainbowPosition++;
    }
    
    if (!berzerk) rainbowPosition += speed;
    FastLED.show();
  }
}


void Anim1D_Fire(LED_Screen* screen, unsigned long frameLengthMillis, byte r = 255, byte g = 175, byte b = 40)
{
  if (screen->FrameAnimation.IterateFrame(frameLengthMillis)) {
    for (int i = 0; i < screen->LED_COUNT; i++)
    {
      int flicker = random(0,150);
      int r1 = r - flicker;
      int g1 = g - flicker;
      int b1 = b - flicker;
      if (g1 < 0) g1 = 0;
      if (r1 < 0) r1 = 0;
      if (b1 < 0) b1 = 0;
      screen->LEDs[i] = CRGB(r1, g1, b1);
    }
    FastLED.show();
  }
}


void Anim1D_ColorFire(LED_Screen* screen, const int colorChangeSpeed = 1, unsigned long frameLengthMillis = 1000)
{
  static Color colorCurrent(0, 0, 0);
  colorCurrent.ColorShift(colorChangeSpeed, frameLengthMillis);
  CRGB currentCRGB(colorCurrent.R, colorCurrent.G, colorCurrent.B);
  Anim1D_Fire(screen, frameLengthMillis, colorCurrent.R, colorCurrent.G, colorCurrent.B);
}


void Anim1D_PacmanChase(LED_Screen* screen, unsigned int animVirtualLEDCount, unsigned int frameLengthMillis = 60)
{
  if (screen->FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int pacmanPosition = 0;

    screen->ClearScreen();
    int P1 = ((pacmanPosition >= animVirtualLEDCount) ? 0 : pacmanPosition);
    int P2 = (((P1 - 3) < 0) ? (animVirtualLEDCount + P1 - 3) : (P1 - 3));
    int P3 = (((P1 - 5) < 0) ? (animVirtualLEDCount + P1 - 5) : (P1 - 5));
    int P4 = (((P1 - 7) < 0) ? (animVirtualLEDCount + P1 - 7) : (P1 - 7));
    int P5 = (((P1 - 9) < 0) ? (animVirtualLEDCount + P1 - 9) : (P1 - 9));
    
    if (screen->IsIndexOnScreen(P1)) screen->LEDs[P1] = CRGB::Yellow;
    if (screen->IsIndexOnScreen(P2)) screen->LEDs[P2] = CRGB::Red;
    if (screen->IsIndexOnScreen(P3)) screen->LEDs[P3] = CRGB::Cyan;
    if (screen->IsIndexOnScreen(P4)) screen->LEDs[P4] = CRGB::Orange;
    if (screen->IsIndexOnScreen(P5)) screen->LEDs[P5] = CRGB::Magenta;
    
    FastLED.show();
    pacmanPosition = P1 + 1;
  }
}


void Anim1D_MsPacmanRedWhite(LED_Screen* screen, unsigned int frameLengthMillis = 25)
{
  if (screen->FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int whitePosition = 0;
    static const int redToWhiteRatio = 6;
    static const int slowdown = 3;
    
    screen->ClearScreen();
    
    for (int i = 0; i < screen->LED_COUNT; i++)
    {
      screen->LEDs[i] = ((((whitePosition / slowdown) + i) % (redToWhiteRatio + 1)) == 0) ? CRGB::White : CRGB::Red;
    }
    
    FastLED.show();
    whitePosition += 1;
    if (whitePosition == ((redToWhiteRatio + 1) * slowdown)) whitePosition = 0;
  }
}


void Anim1D_VegasMarquee(LED_Screen* screen, unsigned int frameLengthMillis = 25)
{
  if (screen->FrameAnimation.IterateFrame(frameLengthMillis)) {
    static int redPosition = 0;
    const int blankToRedRatio = 1;
    static const int slowdown = 5;
    
    screen->ClearScreen();
    
    for (int i = 0; i < screen->LED_COUNT; i++)
    {
      screen->LEDs[i] = ((((redPosition / slowdown) + i) % (blankToRedRatio + 1)) == 0) ? CRGB::Red : CRGB::Black;
    }
    
    FastLED.show();
    redPosition += 1;
    if (redPosition == ((blankToRedRatio + 1) * slowdown)) redPosition = 0;
  }
}