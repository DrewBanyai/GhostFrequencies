#include <FastLED.h>

#include "LED_Screen.h"
#include "Animations_1D.h"
#include "Animations_2D.h"
#include "FrameAnimation.h"

class GhostScreen : public LED_Screen{
  private:
    static const int SCREEN_WIDTH = 14;
    static const int SCREEN_HEIGHT = 14;
    static const int VIRTUAL_LED_COUNT = SCREEN_WIDTH * SCREEN_HEIGHT; //  The number of Virtual LEDs when X,Y positions are translated
    int ScreenIndexTranslated[VIRTUAL_LED_COUNT];

  public:
    static const unsigned int GHOST_SCREEN_LED_COUNT = 158;
    static const unsigned int VIRTUAL_LEDS_ADDITION = 0;
    CRGB GhostScreenLEDs[GHOST_SCREEN_LED_COUNT];
    GhostScreen() : LED_Screen(GHOST_SCREEN_LED_COUNT, GhostScreenLEDs, "Ghost Screen", 11) {}


    void Initialize(bool ledChutesLayout) {
      //  NOTE: Because we translate the screen virtual indices prior to passing them in, we must set the Chutes value here as well before passing it in
      LED_Screen::SetVirtualScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT, ScreenIndexTranslated, ledChutesLayout);

      TranslateScreenVirtualIndices();
      LED_Screen::SetScreenIndexTranslations(ScreenIndexTranslated);
    }

    inline void Render() {
      switch (PatternIndex)
      {
        case 0:   Anim1D_GlowFlow((LED_Screen*)this, 2, 1000);                                            break;
        case 1:   Anim1D_RainbowFlow1((LED_Screen*)this, 5);                                              break;
        case 2:   Anim2D_RainbowFlow2((LED_Screen*)this, 10, false);                                      break;
        case 3:   Anim1D_ColorFire((LED_Screen*)this, 1, 25);                                             break;
        case 4:   ClearScreen(); Anim2D_PacManChompDanceThrough((LED_Screen*)this);                       break;
        case 5:   ClearScreen(); Anim2D_PacManChompDanceThroughPlusGhost((LED_Screen*)this);              break;
        case 6:   ClearScreen(); Anim2D_MsPacManChompDanceThrough((LED_Screen*)this);                     break;
        case 7:   ClearScreen(); Anim2D_SpaceInvaderDanceThrough((LED_Screen*)this);                      break;
        case 8:   ClearScreen(); Anim2D_LetterMoveThrough_BRC((LED_Screen*)this);                         break;
        case 9:   ClearScreen(); Anim2D_SimpleFlame((LED_Screen*)this);                                   break;
        case 10:  ClearScreen(); Anim2D_PacManGhostEyesOnly((LED_Screen*)this);                           break;
        default:    PatternIndex = 0;                                             break;
      }
    }

  private:
    //  Convert the 158-light ghost screen shape into a string
    //  "_____OOOO_____" + 
    //  "___OOOOOOOO___" + 
    //  "__OOOOOOOOOO__" + 
    //  "_OOOOOOOOOOOO_" + 
    //  "_OOOOOOOOOOOO_" + 
    //  "_OOOOOOOOOOOO_" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OOOOOOOOOOOOOO" + 
    //  "OO_OOO__OOO_OO" + 
    //  "O___OO__OO___O";
    String ScreenShape = "_____OOOO________OOOOOOOO_____OOOOOOOOOO___OOOOOOOOOOOO__OOOOOOOOOOOO__OOOOOOOOOOOO_OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO_OOO__OOO_OOO___OO__OO___O";

    //  Call this when the screen class is created
    void TranslateScreenVirtualIndices() {
      int emptySpaceCount = 0;
      for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); ++i) {
        if (ScreenShape[i] == 'O') {
          ScreenIndexTranslated[VirtualIndexTranslate(i)] = i - emptySpaceCount;
        }
        else {
          emptySpaceCount += 1;
          ScreenIndexTranslated[i] = -1;
        }
      }
    }
};