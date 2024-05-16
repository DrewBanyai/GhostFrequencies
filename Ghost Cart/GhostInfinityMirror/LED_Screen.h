#pragma once

#include "FrameAnimation.h"
#include "Helper.h"

class LED_Screen {
  public:
    unsigned int LED_COUNT = 0;

    unsigned int SCREEN_WIDTH = 1;
    unsigned int SCREEN_HEIGHT = 1;
    unsigned int VIRTUAL_LED_COUNT = 1;
    int* ScreenIndexTranslated;
    bool Chutes = false;

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

    inline void SetVirtualScreenSize(unsigned int width, unsigned int height, int* screenIndexTranslations, bool chutes = true) {
      SCREEN_WIDTH = width;
      SCREEN_HEIGHT = height;
      VIRTUAL_LED_COUNT = width * height;
      Chutes = chutes;
    }

    inline void SetScreenIndexTranslations(int* screenIndexTranslations) { ScreenIndexTranslated = screenIndexTranslations; }

    inline int PositionToIndex(int x, int y) {
      int vIndex = (y * SCREEN_WIDTH + x);
      return (vIndex >= 0 && vIndex <= VIRTUAL_LED_COUNT) ? ScreenIndexTranslated[(y * SCREEN_WIDTH + x)] : -1;
    }
    
    inline bool IsPosOnScreen(int x, int y) {
      if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) return false;
      return (PositionToIndex(x, y) != -1);
    }

    //  NOTE: The "Chutes" alternate is for when the LED screen goes left to right on odd rows, but right to left on even rows (like a chute going back and forth)
    inline int VirtualIndexTranslate(int vIndex) { return Chutes ? VirtualIndexTranslate_Chutes(vIndex) : vIndex; }
    inline int VirtualIndexTranslate_Chutes(int vIndex) { return (((vIndex / SCREEN_WIDTH) & 1) ? (((vIndex / SCREEN_WIDTH + 1) * SCREEN_WIDTH) - 1 - (vIndex % SCREEN_WIDTH)) : vIndex); }

    inline bool IsVirtualIndexOnScreen(int vIndex) { return (vIndex >= 0 && vIndex < VIRTUAL_LED_COUNT) ? (ScreenIndexTranslated[vIndex] != -1) : false; }

    inline bool IsPixelBlack(int x, int y) { int index = PositionToIndex(x, y); return (index != -1) ? (LEDs[index].r == 0 && LEDs[index].g == 0 && LEDs[index].b == 0) : false; }
    inline const CRGB& GetPixel(int x, int y) { return (IsPosOnScreen(x, y)) ? LEDs[PositionToIndex(x, y)] : CRGB::Black; }

    inline void SetLEDByColorRef(int x, int y, const CRGB& color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDByColor(int x, int y, const CRGB color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDIndexByColor(int index, CRGB color) { if (IsIndexOnScreen(index) == true) LEDs[index] = color; }
    inline void SetLightsByColorRef(int x, int y, int count, const CRGB& color) { for (int i = 0; i < count; ++i) SetLEDByColorRef(x + i, y, color); }

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
};