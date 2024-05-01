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
};