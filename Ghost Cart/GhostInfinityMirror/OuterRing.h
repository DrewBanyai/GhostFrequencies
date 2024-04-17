#include <FastLED.h>

#include "Patterns.h"

class OuterRing {
  public:
    inline void SetScreen(CRGB color) { fill_solid(LEDs, LED_COUNT, color); }
    inline void ClearScreen() { SetScreen(CRGB::Black); }

    static const int LED_COUNT = 76;
    const int VIRTUAL_LED_COUNT = LED_COUNT + 10; //  The number of Virtual LEDs to travel (AKA the loop will continue until the position passes this number, causing a delay before restarting)
    CRGB LEDs[LED_COUNT];

  private:
    enum LightGroupName
    {
      LG_TOP,
      LG_RIGHT,
      LG_BOTTOM,
      LG_LEFT,
      LIGHT_GROUP_COUNT
    };

    inline void GetGroupData(LightGroupName group, int& groupStart, int& groupEnd) {
      switch (group) {
        case LG_TOP:      groupStart = 0;     groupEnd = 23;      break;
        case LG_RIGHT:    groupStart = 24;    groupEnd = 37;      break;
        case LG_BOTTOM:   groupStart = 38;    groupEnd = 61;      break;
        case LG_LEFT:     groupStart = 62;    groupEnd = 75;      break;
        default:          groupStart = -1;    groupEnd = -1;      break;
      }
    }

    inline void SetGroupColor(LightGroupName group, CRGB color) {
      int start;
      int end;
      GetGroupData(group, start, end);
      for (int i = start; i <= end; ++i) { LEDs[i] = color; }
      FastLED.show();
    }

    inline bool IsPositionOnStrip(int position) { return ((position >= 0) && (position < LED_COUNT)); }

    //  Fireworks() values
    static const int FIREWORK_DELAY = 500;
    static const int FIREWORK_SIZE = 6;

  public:
    //////////////////////////////
    //  PATTERN FUNCTIONS
    //////////////////////////////
    void Pacman(unsigned int frameLength = 25)
    {
      static int pacmanPosition = 0;
      
      ClearScreen();
      int P1 = ((pacmanPosition >= VIRTUAL_LED_COUNT) ? 0 : pacmanPosition);
      int P2 = (((P1 - 3) < 0) ? (VIRTUAL_LED_COUNT + P1 - 3) : (P1 - 3));
      int P3 = (((P1 - 5) < 0) ? (VIRTUAL_LED_COUNT + P1 - 5) : (P1 - 5));
      int P4 = (((P1 - 7) < 0) ? (VIRTUAL_LED_COUNT + P1 - 7) : (P1 - 7));
      int P5 = (((P1 - 9) < 0) ? (VIRTUAL_LED_COUNT + P1 - 9) : (P1 - 9));
      
      if (IsPositionOnStrip(P1)) LEDs[P1] = CRGB::Yellow;
      if (IsPositionOnStrip(P2)) LEDs[P2] = CRGB::Red;
      if (IsPositionOnStrip(P3)) LEDs[P3] = CRGB::Cyan;
      if (IsPositionOnStrip(P4)) LEDs[P4] = CRGB::Orange;
      if (IsPositionOnStrip(P5)) LEDs[P5] = CRGB::Magenta;
      
      FastLED.show();
      pacmanPosition = P1 + 1;
      delay(frameLength);
    }
};