#pragma once

#include "Helper.h"
#include "FrameAnimation.h"

void RainbowFlow1(CRGB* leds, const int ledCount, bool nextFrameReady)
{
  static int delayTime = 5;
  static int hueChange = 5;

  if (nextFrameReady)
  {
    static int hue = 0;
    hue += hueChange;
    fill_rainbow(leds, ledCount, hue, -3);
    FastLED.show();
    nextFrameMillis += delayTime;
  }
}

void Fire(CRGB* leds, const int ledCount, byte R, byte G, byte B, bool nextFrameReady)
{
  static int delayTime = 25;
  static int hueChange = 15;

  if (nextFrameReady)
  {
    int r = R;
    int g = G;
    int b = B;
  
    for (int i = 0; i < ledCount; i++)
    {
      byte flicker = random(0,150);
      byte r1 = r - flicker;
      byte g1 = g - flicker;
      byte b1 = b - flicker;
      if (g1 < 0) g1 = 0;
      if (r1 < 0) r1 = 0;
      if (b1 < 0) b1 = 0;
      leds[i] = CRGB(r1, g1, b1);
    }
    FastLED.show();
    nextFrameMillis += random(delayTime * 2, delayTime * 6);
  }
}

void ColorFire(CRGB* leds, const int ledCount, bool nextFrameReady = false)
{
  static int colorChangeSpeed = 5;

  static byte R = random(0, 256);
  static byte G = random(0, 256);
  static byte B = random(0, 256);
    
  R += random(1, (colorChangeSpeed + 1) * 1);
  G += random(1, (colorChangeSpeed + 1) * 2);
  B += random(1, (colorChangeSpeed + 1) * 3);

  Fire(leds, ledCount, R, G, B, nextFrameReady);
}

void GlowFlow(CRGB* leds, const int ledCount, const int colorChangeSpeed = 1, const unsigned long changeDelay = 1000)
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
  fill_solid(leds, ledCount, currentCRGB);
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