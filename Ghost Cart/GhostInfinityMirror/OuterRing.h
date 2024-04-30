#include <FastLED.h>

#include "LED_Screen.h"

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

class OuterRing : public LED_Screen {
  public:
    static const unsigned int OUTER_RING_LED_COUNT = 76;
    static const unsigned int VIRTUAL_LEDS_ADDITION = 10;
    CRGB OuterRingLEDs[OUTER_RING_LED_COUNT];
    OuterRing() : LED_Screen(OUTER_RING_LED_COUNT, OuterRingLEDs, "Outer Ring", 5) {}

    const int VIRTUAL_LED_COUNT = LED_COUNT + 10; //  The number of Virtual LEDs to travel (AKA the loop will continue until the position passes this number, causing a delay before restarting)

    void Render() {
        switch (PatternIndex)
        {
          case 0:   GlowFlow();                                               break;
          case 1:   RainbowFlow1(5);                                          break;
          case 2:   RainbowFlow2_1D(10, false);                               break;
          case 3:   Fire(10);                                                 break;
          case 4:   PacmanChase(VIRTUAL_LED_COUNT);                           break;
          default:  PatternIndex = 0;                                         break;
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

    inline bool IsIndexOnScreen(int position) { return ((position >= 0) && (position < LED_COUNT)); }
    
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