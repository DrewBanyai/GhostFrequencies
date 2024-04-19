#include <FastLED.h>

#include "Patterns.h"

//  The basic colors
#define OUTER_RING_COLOR_COUNT    15
const byte OUTER_RING_COLORS[OUTER_RING_COLOR_COUNT][3] = 
{
	{ 0, 0, 0 },		//  Black
	{ 147, 112, 219 },	//  Medium Purple
	{ 199, 21, 133 },	//  Medium Violet Red
	{ 255, 20, 147 },	//  Deep Pink
	{ 255, 0, 0 },		//  Red
	{ 255, 140, 0 },	//  Dark Orange
	{ 255, 69, 0 },		//  Orange Red
	{ 255, 165, 0 },	//  Orange
	{ 200, 200, 0 },	//  Yellow
	{ 034, 139, 034 },	//  Forest Green
	{ 0, 250, 154 },	//  Medium Spring Green
	{ 032, 178, 170 },  //  Light Sea Green
	{ 0, 100, 0 },  	//  Dark Green
	{ 0, 255, 255 },  	//  Cyan
	{ 070, 130, 180 },  //  Steel Blue
};

class OuterRing {
  public:
    inline void SetScreen(CRGB color) { fill_solid(LEDs, LED_COUNT, color); }
    inline void ClearScreen() { SetScreen(CRGB::Black); }

    static const int LED_COUNT = 76;
    const int VIRTUAL_LED_COUNT = LED_COUNT + 10; //  The number of Virtual LEDs to travel (AKA the loop will continue until the position passes this number, causing a delay before restarting)
    CRGB LEDs[LED_COUNT];

    const int PATTERN_SWITCH_BUTTON_DELAY = 10000;
    unsigned long PatternSwitchTimer = PATTERN_SWITCH_BUTTON_DELAY;
    int PatternIndex = 0;
    inline void SetPatternIndex(int newIndex) { PatternIndex = newIndex; }
    inline bool SwitchPatterns() {
      if (millis() < PatternSwitchTimer) return false;
      else {
        PatternSwitchTimer = millis() + PATTERN_SWITCH_BUTTON_DELAY;
        Serial.println("Outer Ring: Iterating to next pattern...");

        ClearScreen();
        UpdateMillisOffset();
        ++PatternIndex;
        FrameAnimation.ResetAnimation();

        return true;
      }
    }

    void Render() {
        switch (PatternIndex)
        {
          case 0:   /*Serial.println("PacmanChase()");*/                        PacmanChase();                                                              break;
          case 1:   /*Serial.println("RainbowFlow1()");*/                       RainbowFlow1(LEDs, LED_COUNT, FrameAnimation.IterateFrame(65535, 5));                                              break;
          case 2:   /*Serial.println("RainbowFlow2()");*/                       RainbowFlow2(10, false);                                                    break;
          default:  PatternIndex = 0;                                       break;
        }
    }

  private:
    FrameAnimationManager FrameAnimation;

    enum LightGroupName { LG_TOP, LG_RIGHT, LG_BOTTOM, LG_LEFT, LIGHT_GROUP_COUNT };

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
    
    inline int LoopedLEDIndex(int index)
    {
	    index = index % LED_COUNT;
	    while (index < 0) index = (LED_COUNT + index) % LED_COUNT;
      return index;
    }

    //  Fireworks() values
    static const int FIREWORK_DELAY = 500;
    static const int FIREWORK_SIZE = 6;

  public:
    //////////////////////////////
    //  PATTERN FUNCTIONS
    //////////////////////////////
    void PacmanChase(unsigned int frameLength = 25)
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

    void RainbowFlow2(int speed = 1, bool berzerk = false)
    {
      static int rainbowPosition = 0;
      for (int i = 0; i < LED_COUNT; ++i)
        {
          LEDs[i] = Wheel(((i * 256 / LED_COUNT) + rainbowPosition) & 255);
          if (berzerk) rainbowPosition++;
        }
        
        if (!berzerk) rainbowPosition += speed;
        delay(50);
      FastLED.show();
    }

    void Fire()
    {
      int r = 255;
      int g = r - 80;
      int b = 40;

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
      delay(random(50,150));
    }

    void GlowFlow()
    {
      static Color colorCurrent(0, 0, 0);
      static Color colorDelta(0, 0, 0);
      static bool colorDisplay = true;
      static unsigned long nextChangeTime = 0;
      static bool adding = false;
      const int glowFlowDelay = 15;
      
      adding = false;
      if (colorDelta.R > 0) { colorDelta.R -= 1; colorCurrent.R = min(255, colorCurrent.R + 1); delay(glowFlowDelay); adding = true; }
      if (colorDelta.G > 0) { colorDelta.G -= 1; colorCurrent.G = min(255, colorCurrent.G + 1); delay(glowFlowDelay); adding = true; }
      if (colorDelta.B > 0) { colorDelta.B -= 1; colorCurrent.B = min(255, colorCurrent.B + 1); delay(glowFlowDelay); adding = true; }
      if (adding == false)
      {
        if (colorDelta.R < 0) { colorDelta.R += 1; colorCurrent.R = max(0,   colorCurrent.R - 1); delay(glowFlowDelay); }
        if (colorDelta.G < 0) { colorDelta.G += 1; colorCurrent.G = max(0,   colorCurrent.G - 1); delay(glowFlowDelay); }
        if (colorDelta.B < 0) { colorDelta.B += 1; colorCurrent.B = max(0,   colorCurrent.B - 1); delay(glowFlowDelay); }
      }
      
      CRGB currentCRGB(colorCurrent.R, colorCurrent.G, colorCurrent.B);
      fill_solid(LEDs, LED_COUNT, currentCRGB);
      FastLED.show();
        
      if (colorDelta.isZero() && nextChangeTime < millis())
      {
        int newColorIndex = 0;
        do
        {
          newColorIndex = 1 + random(OUTER_RING_COLOR_COUNT - 1);
          
          colorDelta.R = OUTER_RING_COLORS[newColorIndex][0] - colorCurrent.R;
          colorDelta.G = OUTER_RING_COLORS[newColorIndex][1] - colorCurrent.G;
          colorDelta.B = OUTER_RING_COLORS[newColorIndex][2] - colorCurrent.B;
          
        } while (colorDelta.isZero());
        
        const int glowFlowColorTime = 3000;
        nextChangeTime = millis() + glowFlowColorTime;
      }
    }

    void GroupTest()
    {
      LightGroupName group = LightGroupName((millis() / 250) % LIGHT_GROUP_COUNT);
      
      ClearScreen();
      SetGroupColor(group, CRGB::Red);
      FastLED.show();
    }

    void MsPacmanRedWhite(unsigned int frameLength = 25)
    {
      static int whitePosition = 0;
      static const int redToWhiteRatio = 6;
      static const int slowdown = 3;
      
      ClearScreen();
      
      for (int i = 0; i < LED_COUNT; i++)
      {
        LEDs[i] = ((((whitePosition / slowdown) + i) % (redToWhiteRatio + 1)) == 0) ? CRGB::White : CRGB::Red;
      }
      
      FastLED.show();
      whitePosition += 1;
      if (whitePosition == ((redToWhiteRatio + 1) * slowdown)) whitePosition = 0;
      
      delay(frameLength);
    }

    void VegasMarquee(unsigned int frameLength = 25)
    {
      static int redPosition = 0;
      const int blankToRedRatio = 1;
      static const int slowdown = 5;
      
      ClearScreen();
      
      for (int i = 0; i < LED_COUNT; i++)
      {
        LEDs[i] = ((((redPosition / slowdown) + i) % (blankToRedRatio + 1)) == 0) ? CRGB::Red : CRGB::Black;
      }
      
      FastLED.show();
      redPosition += 1;
      if (redPosition == ((blankToRedRatio + 1) * slowdown)) redPosition = 0;
      
      delay(frameLength);
    }

    void FireworksSetup()
    {
      for (int i = 0; i < LED_COUNT; ++i)
      {
        int colorIndex = 1 + random(COMMON_COLOR_COUNT - 1);
        LEDs[i] = CRGB(OUTER_RING_COLORS[colorIndex][0], OUTER_RING_COLORS[colorIndex][1], OUTER_RING_COLORS[colorIndex][2]);
      }
      FastLED.show();
    }

    void Fireworks()
    {
      static unsigned long lastFireworkTime = 0;

      unsigned long currentTime = millis();
      
      //  Create a new firework if enough time has passed
      if (currentTime > lastFireworkTime + FIREWORK_DELAY)
      {
        int position = random(LED_COUNT);
        int colorIndex = 1 + random(COMMON_COLOR_COUNT - 1);
        for (int i = 0; i < FIREWORK_SIZE; ++i) LEDs[LoopedLEDIndex(position + i)] = CRGB(OUTER_RING_COLORS[colorIndex][0], OUTER_RING_COLORS[colorIndex][1], OUTER_RING_COLORS[colorIndex][2]);
        lastFireworkTime = currentTime;
      }
      
      //  Render the fireworks
      FastLED.show();
    }
};