#include <FastLED.h>

#include "LED_Screen.h"
#include "Animations_1D.h"
#include "FrameAnimation.h"

class GhostScreen : public LED_Screen{
  public:
    static const unsigned int GHOST_SCREEN_LED_COUNT = 158;
    static const unsigned int VIRTUAL_LEDS_ADDITION = 0;
    CRGB GhostScreenLEDs[GHOST_SCREEN_LED_COUNT];
    GhostScreen() : LED_Screen(GHOST_SCREEN_LED_COUNT, GhostScreenLEDs, "Ghost Screen", 9) {}


    void Initialize(bool ledChutesLayout) {
      Chutes = ledChutesLayout;

      TranslateScreenVirtualIndices();
    }

    inline bool IsPixelBlack(int x, int y) { int index = PositionToIndex(x, y); return (index != -1) ? (LEDs[index].r == 0 && LEDs[index].g == 0 && LEDs[index].b == 0) : false; }
    inline const CRGB& GetPixel(int x, int y) { return (IsPosOnScreen(x, y)) ? LEDs[PositionToIndex(x, y)] : CRGB::Black; }

    inline void SetLEDByColorRef(int x, int y, const CRGB& color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDByColor(int x, int y, const CRGB color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDIndexByColor(int index, CRGB color) { if (IsIndexOnScreen(index) == true) LEDs[index] = color; }
    inline void SetLightsByColorRef(int x, int y, int count, const CRGB& color) { for (int i = 0; i < count; ++i) SetLEDByColorRef(x + i, y, color); }

    //  14x14 Images
    void DrawPacManChomp01(int x, int y, CRGB& color);
    void DrawPacManChomp02(int x, int y, CRGB& color);
    void DrawPacManChomp03(int x, int y, CRGB& color);
    void DrawPacManGhostWalk01(int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall);
    void DrawPacManGhostWalk02(int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall);
    void DrawMsPacManChomp01(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3);
    void DrawMsPacManChomp02(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3);
    void DrawMsPacManChomp03(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3);
    void DrawSpaceInvader01(int x, int y, CRGB& color1, CRGB& color2);
    void DrawSpaceInvader02(int x, int y, CRGB& color1, CRGB& color2);
    void DrawLetter_A(int x, int y, CRGB& color);
    void DrawLetter_B(int x, int y, CRGB& color);
    void DrawLetter_C(int x, int y, CRGB& color);
    void DrawLetter_R(int x, int y, CRGB& color);

    //  14x14 Image Animations
    void PacManChompDanceThrough(int x = -6, int y = 7, int frameLengthMillis = 150, int animationFrameCount = 46, int frame = 255);
    void PacManChompDanceThroughPlusGhost(int frameLength = 100, int animationFrameCount = 140, int frame = 255);
    void PacManGhostDanceThrough(int x, int y, int frameLength, int body, int eyeWhite, int eyeBall, int animationTime, int frame);
    void MsPacManChompDanceThrough(int frameLength = 100, int animationFrameCount = 48, int frame = 255);
    void SpaceInvaderDanceThrough(byte color1 = 7, byte color2 = 7, int frame = 255);
    void LetterMoveThrough_BRC(int x = 21, int y = 6, int frameLengthMillis = 60, int animationFrameCount = 90);

    inline void Render() {
      switch (PatternIndex)
      {
        case 0:   Anim1D_GlowFlow((LED_Screen*)this, 2, 1000);                    break;
        case 1:   Anim1D_RainbowFlow1((LED_Screen*)this, 5);                      break;
        case 2:   RainbowFlow2_2D(10, false);                                     break;
        case 3:   Anim1D_ColorFire((LED_Screen*)this, 1, 25);                     break;
        case 4:   ClearScreen(); PacManChompDanceThrough();                       break;
        case 5:   ClearScreen(); PacManChompDanceThroughPlusGhost();              break;
        case 6:   ClearScreen(); MsPacManChompDanceThrough();                     break;
        case 7:   ClearScreen(); SpaceInvaderDanceThrough();                      break;
        case 8:   ClearScreen(); LetterMoveThrough_BRC();                         break;
        //case 9:   ClearScreen(); MegaManRunThrough();                             break;
        //case 10:  ClearScreen(); MarioWarpThrough();                              break;
        //case 11:  ClearScreen(); Tetris();                                        break;
        default:    PatternIndex = 0;                                             break;
      }
    }

    static const int SCREEN_WIDTH = 14;
    static const int SCREEN_HEIGHT = 14;

    void RainbowFlow2_2D(int hueChangeSpeed, bool berzerk);

  private:
    static const int VIRTUAL_LED_COUNT = SCREEN_WIDTH * SCREEN_HEIGHT; //  The number of Virtual LEDs when X,Y positions are translated

    bool Chutes = false;

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
    int ScreenIndexTranslated[VIRTUAL_LED_COUNT];

    //  Call this when the screen class is created
    void TranslateScreenVirtualIndices() {
      int emptySpaceCount = 0;
      for (int i = 0; i < VIRTUAL_LED_COUNT; ++i) {
        if (ScreenShape[i] == 'O') {
          ScreenIndexTranslated[VirtualIndexTranslate(i)] = i - emptySpaceCount;
        }
        else {
          emptySpaceCount += 1;
          ScreenIndexTranslated[i] = -1;
        }
      }
    }

    inline bool IsPosOnScreen(int x, int y) {
      if (x < 0) return false;
      if (y < 0) return false;
      if (x >= SCREEN_WIDTH) return false;
      if (y >= SCREEN_HEIGHT) return false;
      return (PositionToIndex(x, y) != -1);
    }

    inline int PositionToIndex(int x, int y) { int vIndex = (y * SCREEN_WIDTH + x); return (vIndex >= 0 && vIndex <= VIRTUAL_LED_COUNT) ? ScreenIndexTranslated[(y * SCREEN_WIDTH + x)] : -1; }
    inline bool IsIndexOnScreen(int index) { return (index >= 0 && index < LED_COUNT); }
    inline bool IsVirtualIndexOnScreen(int vIndex) { return (vIndex >= 0 && vIndex < VIRTUAL_LED_COUNT) ? (ScreenIndexTranslated[vIndex] != -1) : false; }

    //  NOTE: The "Chutes" alternate is for when the LED screen goes left to right on odd rows, but right to left on even rows (like a chute going back and forth)
    inline int VirtualIndexTranslate(int virtualIndex) { return Chutes ? (((virtualIndex / SCREEN_WIDTH) & 1) ? (((virtualIndex / SCREEN_WIDTH + 1) * SCREEN_WIDTH) - 1 - (virtualIndex % SCREEN_WIDTH)) : virtualIndex) : virtualIndex; }
};


void GhostScreen::PacManChompDanceThrough(int x, int y, int frameLengthMillis, int animationFrameCount, int frame)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);
  
  CRGB color1 = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));

  if (frame % 8 == 0)       DrawPacManChomp01(frame + x, y, color1);
  else if (frame % 8 == 1)  DrawPacManChomp02(frame + x, y, color1);
  else if (frame % 8 == 2)  DrawPacManChomp03(frame + x, y, color1);
  else if (frame % 8 == 3)  DrawPacManChomp02(frame + x, y, color1);
  else if (frame % 8 == 4)  DrawPacManChomp01(frame + x, y, color1);
  else if (frame % 8 == 5)  DrawPacManChomp02(frame + x, y, color1);
  else if (frame % 8 == 6)  DrawPacManChomp03(frame + x, y, color1);
  else                      DrawPacManChomp02(frame + x, y, color1);
}

void GhostScreen::DrawPacManChomp01(int x, int y, CRGB& color)
{
/*
 *     XXXXX
 *   XXXXXXXXX
 *  XXXXXXXXXXX
 *  XXXXXXXXXXX
 * XXXXXXXXXXXXX
 * XXXXXXXXXXXXX
 * XXXXXXXXXXXXX
 * XXXXXXXXXXXXX
 * XXXXXXXXXXXXX
 *  XXXXXXXXXXX
 *  XXXXXXXXXXX
 *   XXXXXXXXX
 *     XXXXX
 */
 
  SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorRef(x - 4, y - 5, 9, color); //  START ROW -5
  SetLightsByColorRef(x - 5, y - 4, 11, color); //  START ROW -4
  SetLightsByColorRef(x - 5, y - 3, 11, color); //  START ROW -3
  SetLightsByColorRef(x - 6, y - 2, 13, color); //  START ROW -2
  SetLightsByColorRef(x - 6, y - 1, 13, color); //  START ROW -1
  SetLightsByColorRef(x - 6, y + 0, 13, color); //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 13, color); //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 13, color); //  START ROW +2
  SetLightsByColorRef(x - 5, y + 3, 11, color); //  START ROW +3
  SetLightsByColorRef(x - 5, y + 4, 11, color); //  START ROW +4
  SetLightsByColorRef(x - 4, y + 5, 9, color); //  START ROW +5
  SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::DrawPacManChomp02(int x, int y, CRGB& color)
{
/*
 *     XXXXX
 *   XXXXXXXXX
 *  XXXXXXXXXXX
 *  XXXXXXXXXXX
 * XXXXXXXXXX
 * XXXXXXX
 * XXXX
 * XXXXXXX
 * XXXXXXXXXX
 *  XXXXXXXXXXX
 *  XXXXXXXXXXX
 *   XXXXXXXXX
 *     XXXXX
 */
 
  SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorRef(x - 4, y - 5, 9, color); //  START ROW -5
  SetLightsByColorRef(x - 5, y - 4, 11, color); //  START ROW -4
  SetLightsByColorRef(x - 5, y - 3, 11, color); //  START ROW -3
  SetLightsByColorRef(x - 6, y - 2, 10, color); //  START ROW -2
  SetLightsByColorRef(x - 6, y - 1, 7, color); //  START ROW -1
  SetLightsByColorRef(x - 6, y + 0, 4, color); //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 7, color); //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 10, color); //  START ROW +2
  SetLightsByColorRef(x - 5, y + 3, 11, color); //  START ROW +3
  SetLightsByColorRef(x - 5, y + 4, 11, color); //  START ROW +4
  SetLightsByColorRef(x - 4, y + 5, 9, color); //  START ROW +5
  SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::DrawPacManChomp03(int x, int y, CRGB& color)
{
/*
 *     XXXXX
 *   XXXXXXX
 *  XXXXXXX
 *  XXXXXX
 * XXXXXX
 * XXXXX
 * XXXX
 * XXXXX
 * XXXXXX
 *  XXXXXX
 *  XXXXXXX
 *   XXXXXXX
 *     XXXXX
 */
 
  SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorRef(x - 4, y - 5, 7, color); //  START ROW -5
  SetLightsByColorRef(x - 5, y - 4, 7, color); //  START ROW -4
  SetLightsByColorRef(x - 5, y - 3, 6, color); //  START ROW -3
  SetLightsByColorRef(x - 6, y - 2, 6, color); //  START ROW -2
  SetLightsByColorRef(x - 6, y - 1, 5, color); //  START ROW -1
  SetLightsByColorRef(x - 6, y + 0, 4, color); //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 5, color); //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 6, color); //  START ROW +2
  SetLightsByColorRef(x - 5, y + 3, 6, color); //  START ROW +3
  SetLightsByColorRef(x - 5, y + 4, 7, color); //  START ROW +4
  SetLightsByColorRef(x - 4, y + 5, 7, color); //  START ROW +5
  SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::PacManChompDanceThroughPlusGhost(int frameLengthMillis, int animationFrameCount, int frame = 255)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  PacManChompDanceThrough(-6, 7, frameLengthMillis, animationFrameCount, frame);
  PacManGhostDanceThrough(-26, 7, frameLengthMillis, 50, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-46, 7, frameLengthMillis, 51, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-66, 7, frameLengthMillis, 52, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-86, 7, frameLengthMillis, 53, 7, 0, animationFrameCount, frame);
}


void GhostScreen::PacManGhostDanceThrough(int x = 6, int y = 14, int frameLengthMillis = 48, int body = 50, int eyeWhite = 7, int eyeBall = 0, int animationFrameCount = 100, int frame = 255)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  CRGB bodyColor = CRGB(GetColor(body, 0), GetColor(body, 1), GetColor(body, 2));
  CRGB eyeWhiteColor = CRGB(GetColor(eyeWhite, 0), GetColor(eyeWhite, 1), GetColor(eyeWhite, 2));
  CRGB eyeBallColor = CRGB(GetColor(eyeBall, 0), GetColor(eyeBall, 1), GetColor(eyeBall, 2));
  
  if (frame % 4 == 0)       DrawPacManGhostWalk01(frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 1)  DrawPacManGhostWalk01(frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 2)  DrawPacManGhostWalk02(frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 3)  DrawPacManGhostWalk02(frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
}

void GhostScreen::DrawPacManGhostWalk01(int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall)
{
  SetLightsByColorRef(x - 2, y - 7, 4, bodyColor); // START ROW -7
  SetLightsByColorRef(x - 4, y - 6, 8, bodyColor); // START ROW -6
  SetLightsByColorRef(x - 5, y - 5, 10, bodyColor); // START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 3, bodyColor); // START ROW -4
  SetLightsByColorRef(x - 3, y - 4, 2, eyeWhite);
  SetLightsByColorRef(x - 1, y - 4, 4, bodyColor);
  SetLightsByColorRef(x + 3, y - 4, 2, eyeWhite);
  SetLEDByColorRef(x + 5, y - 4, bodyColor);
  SetLightsByColorRef(x - 6, y - 3, 2, bodyColor); // START ROW -3
  SetLightsByColorRef(x - 4, y - 3, 4, eyeWhite);
  SetLightsByColorRef(x + 0, y - 3, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 3, 4, eyeWhite);
  SetLightsByColorRef(x - 6, y - 2, 2, bodyColor); // START ROW -2
  SetLightsByColorRef(x - 4, y - 2, 2, eyeWhite);
  SetLightsByColorRef(x - 2, y - 2, 2, eyeBall);
  SetLightsByColorRef(x + 0, y - 2, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 2, 2, eyeWhite);
  SetLightsByColorRef(x + 4, y - 2, 2, eyeBall);
  SetLightsByColorRef(x - 7, y - 1, 3, bodyColor); // START ROW -1
  SetLightsByColorRef(x - 4, y - 1, 2, eyeWhite);
  SetLightsByColorRef(x - 2, y - 1, 2, eyeBall);
  SetLightsByColorRef(x + 0, y - 1, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 1, 2, eyeWhite);
  SetLightsByColorRef(x + 4, y - 1, 2, eyeBall);
  SetLEDByColorRef(x + 6, y - 1, bodyColor);
  SetLightsByColorRef(x - 7, y + 0, 4, bodyColor); // START ROW +0
  SetLightsByColorRef(x - 3, y + 0, 2, eyeWhite);
  SetLightsByColorRef(x - 1, y + 0, 4, bodyColor);
  SetLightsByColorRef(x + 3, y + 0, 2, eyeWhite);
  SetLightsByColorRef(x + 5, y + 0, 2, bodyColor);
  SetLightsByColorRef(x - 7, y + 1, 14, bodyColor); // START ROW +1
  SetLightsByColorRef(x - 7, y + 2, 14, bodyColor); // START ROW +2
  SetLightsByColorRef(x - 7, y + 3, 14, bodyColor); // START ROW +3
  SetLightsByColorRef(x - 7, y + 4, 14, bodyColor); // START ROW +4
  SetLightsByColorRef(x - 7, y + 5, 4, bodyColor); // START ROW +5
  SetLightsByColorRef(x - 2, y + 5, 4, bodyColor);
  SetLightsByColorRef(x + 3, y + 5, 4, bodyColor);
  SetLightsByColorRef(x - 6, y + 6, 2, bodyColor); // START ROW +6
  SetLightsByColorRef(x - 1, y + 6, 2, bodyColor);
  SetLightsByColorRef(x + 4, y + 6, 2, bodyColor);
}

void GhostScreen::DrawPacManGhostWalk02(int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall)
{
  SetLightsByColorRef(x - 2, y - 7, 4, bodyColor); // START ROW -7
  SetLightsByColorRef(x - 4, y - 6, 8, bodyColor); // START ROW -6
  SetLightsByColorRef(x - 5, y - 5, 10, bodyColor); // START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 3, bodyColor); // START ROW -4
  SetLightsByColorRef(x - 3, y - 4, 2, eyeWhite);
  SetLightsByColorRef(x - 1, y - 4, 4, bodyColor);
  SetLightsByColorRef(x + 3, y - 4, 2, eyeWhite);
  SetLEDByColorRef(x + 5, y - 4, bodyColor);
  SetLightsByColorRef(x - 6, y - 3, 2, bodyColor); // START ROW -3
  SetLightsByColorRef(x - 4, y - 3, 4, eyeWhite);
  SetLightsByColorRef(x + 0, y - 3, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 3, 4, eyeWhite);
  SetLightsByColorRef(x - 6, y - 2, 2, bodyColor); // START ROW -2
  SetLightsByColorRef(x - 4, y - 2, 2, eyeWhite);
  SetLightsByColorRef(x - 2, y - 2, 2, eyeBall);
  SetLightsByColorRef(x + 0, y - 2, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 2, 2, eyeWhite);
  SetLightsByColorRef(x + 4, y - 2, 2, eyeBall);
  SetLightsByColorRef(x - 7, y - 1, 3, bodyColor); // START ROW -1
  SetLightsByColorRef(x - 4, y - 1, 2, eyeWhite);
  SetLightsByColorRef(x - 2, y - 1, 2, eyeBall);
  SetLightsByColorRef(x + 0, y - 1, 2, bodyColor);
  SetLightsByColorRef(x + 2, y - 1, 2, eyeWhite);
  SetLightsByColorRef(x + 4, y - 1, 2, eyeBall);
  SetLEDByColorRef(x + 6, y - 1, bodyColor);
  SetLightsByColorRef(x - 7, y + 0, 4, bodyColor); // START ROW +0
  SetLightsByColorRef(x - 3, y + 0, 2, eyeWhite);
  SetLightsByColorRef(x - 1, y + 0, 4, bodyColor);
  SetLightsByColorRef(x + 3, y + 0, 2, eyeWhite);
  SetLightsByColorRef(x + 5, y + 0, 2, bodyColor);
  SetLightsByColorRef(x - 7, y + 1, 14, bodyColor); // START ROW +1
  SetLightsByColorRef(x - 7, y + 2, 14, bodyColor); // START ROW +2
  SetLightsByColorRef(x - 7, y + 3, 14, bodyColor); // START ROW +3
  SetLightsByColorRef(x - 7, y + 4, 14, bodyColor); // START ROW +4
  SetLightsByColorRef(x - 7, y + 5, 2, bodyColor); // START ROW +5
  SetLightsByColorRef(x - 4, y + 5, 3, bodyColor);
  SetLightsByColorRef(x + 1, y + 5, 3, bodyColor);
  SetLightsByColorRef(x + 5, y + 5, 2, bodyColor);
  SetLEDByColorRef(x - 7, y + 6, bodyColor); // START ROW +6
  SetLightsByColorRef(x - 3, y + 6, 2, bodyColor);
  SetLightsByColorRef(x + 1, y + 6, 2, bodyColor);
  SetLEDByColorRef(x + 6, y + 6, bodyColor);
}


void GhostScreen::DrawMsPacManChomp01(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
{
/*
 *           OO
 *      XXXXOOO
 *    XXXXXXOOMO
 *   XXXXXXXXXOMOO
 *   XXXXXXXXXXOOO
 *  XXXXXX    XOO
 * MXXXXXXXXXXXXX
 * MMXXXXXXXXXXXX
 * MXXXXXXXXXXXXX
 *  XXXXXXXXX XXX
 *   XXXXXXXXXXX
 *   XXXXXXXXXXX
 *    XXXXXXXXX
 *      XXXXX
 */

  SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  SetLightsByColorRef(x - 2, y - 6, 4, color1); //  START ROW -6 
  SetLightsByColorRef(x + 2, y - 6, 3, color2);
  SetLightsByColorRef(x - 4, y - 5, 6, color1); //  START ROW -5
  SetLightsByColorRef(x + 2, y - 5, 2, color2);
  SetLEDByColorRef(x + 4, y - 5, color3);
  SetLEDByColorRef(x + 5, y - 5, color2);
  SetLightsByColorRef(x - 5, y - 4, 9, color1); //  START ROW -4
  SetLEDByColorRef(x + 4, y - 4, color2);
  SetLEDByColorRef(x + 5, y - 4, color3);
  SetLightsByColorRef(x + 6, y - 4, 2, color2);
  SetLightsByColorRef(x - 5, y - 3, 10, color1); //  START ROW -3
  SetLightsByColorRef(x + 5, y - 3, 3, color2);
  SetLightsByColorRef(x - 6, y - 2, 5, color1); //  START ROW -2
  SetLEDByColorRef(x + 4, y - 2, color1);
  SetLightsByColorRef(x + 5, y - 2, 2, color2);
  SetLEDByColorRef(x - 7, y - 1, color2); //  START ROW -1
  SetLightsByColorRef(x - 6, y - 1, 13, color1);
  SetLightsByColorRef(x - 7, y + 0, 2, color2); //  START ROW +0
  SetLightsByColorRef(x - 5, y + 0, 12, color1);
  SetLEDByColorRef(x - 7, y + 1, color2); //  START ROW +1
  SetLightsByColorRef(x - 6, y + 1, 13, color1);
  SetLightsByColorRef(x - 6, y + 2, 9, color1); //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 3, color1);
  SetLightsByColorRef(x - 5, y + 3, 11, color1); //  START ROW +3
  SetLightsByColorRef(x - 5, y + 4, 11, color1); //  START ROW +4
  SetLightsByColorRef(x - 4, y + 5, 9, color1); //  START ROW +5
  SetLightsByColorRef(x - 2, y + 6, 5, color1); //  START ROW +6
}

void GhostScreen::DrawMsPacManChomp02(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
{
/*
 *           OO
 *      XXXXOOO
 *    XXXXXXOOMO
 *   XXXXXXXXXOMOO
 *   MMXXX  XXXOOO
 *       XXM XXOO
 *         XXXXXX
 *           XXXX
 *         XXXXXX
 *       XXXX XXX
 *   MMXXXXXXXXX
 *   XXXXXXXXXXX
 *    XXXXXXXXX
 *      XXXXX
 */

  SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  SetLightsByColorRef(x - 2, y - 6, 4, color2); //  START ROW -6 
  SetLightsByColorRef(x + 2, y - 6, 3, color2);
  SetLightsByColorRef(x - 4, y - 5, 4, color1); //  START ROW -5
  SetLightsByColorRef(x + 2, y - 5, 2, color2);
  SetLEDByColorRef(x + 4, y - 5, color3);
  SetLEDByColorRef(x + 5, y - 5, color2);
  SetLightsByColorRef(x - 5, y - 4, 9, color1); //  START ROW -4
  SetLEDByColorRef(x + 4, y - 4, color2);
  SetLEDByColorRef(x + 5, y - 4, color3);
  SetLightsByColorRef(x + 6, y - 4, 2, color2);
  SetLightsByColorRef(x - 5, y - 3, 2, color2); //  START ROW -3
  SetLightsByColorRef(x - 3, y - 3, 3, color1);
  SetLightsByColorRef(x + 2, y - 3, 3, color1);
  SetLightsByColorRef(x + 5, y - 3, 3, color2);
  SetLightsByColorRef(x - 1, y - 2, 2, color1); //  START ROW -2
  SetLEDByColorRef(x + 1, y - 2, color3);
  SetLightsByColorRef(x + 3, y - 2, 2, color1);
  SetLightsByColorRef(x + 5, y - 2, 2, color2);
  SetLightsByColorRef(x + 1, y - 1, 6, color1); //  START ROW -1
  SetLightsByColorRef(x + 3, y + 0, 4, color1); //  START ROW +0
  SetLightsByColorRef(x + 1, y + 1, 6, color1); //  START ROW +1
  SetLightsByColorRef(x - 1, y + 2, 4, color1); //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 3, color1);
  SetLightsByColorRef(x - 5, y + 3, 2, color2); //  START ROW +3
  SetLightsByColorRef(x - 3, y + 3, 9, color1);
  SetLightsByColorRef(x - 5, y + 4, 11, color1); //  START ROW +4
  SetLightsByColorRef(x - 4, y + 5, 9, color1); //  START ROW +5
  SetLightsByColorRef(x - 2, y + 6, 5, color1); //  START ROW +6
}

void GhostScreen::DrawMsPacManChomp03(int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
{
/*
 *           OO
 *     MXXXXOOO
 *      MXXXOOMO
 *       XX XXOMOO
 *        X  XXOOO
 *         XM XOO
 *          XXXXX
 *           XXXX
 *          XXXXX
 *         XX XXX
 *        XXXXXX
 *       XXXXXXX
 *      MXXXXXX
 *     MXXXXX
 */

  SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  SetLEDByColorRef(x - 3, y - 6, color2); //  START ROW -6 
  SetLightsByColorRef(x - 2, y - 6, 4, color1);
  SetLightsByColorRef(x + 2, y - 6, 3, color2);
  SetLEDByColorRef(x - 2, y - 5, color2); //  START ROW -5
  SetLightsByColorRef(x - 1, y - 5, 3, color1);
  SetLightsByColorRef(x + 2, y - 5, 2, color2);
  SetLEDByColorRef(x + 4, y - 5, color3);
  SetLEDByColorRef(x + 5, y - 5, color2);
  SetLightsByColorRef(x - 1, y - 4, 2, color1); //  START ROW -4
  SetLightsByColorRef(x + 2, y - 4, 2, color1);
  SetLEDByColorRef(x + 4, y - 4, color2);
  SetLEDByColorRef(x + 5, y - 4, color3);
  SetLightsByColorRef(x + 6, y - 4, 2, color2);
  SetLEDByColorRef(x + 0, y - 3, color1); //  START ROW -3
  SetLightsByColorRef(x + 3, y - 3, 2, color1);
  SetLightsByColorRef(x + 5, y - 3, 3, color2);
  SetLEDByColorRef(x + 1, y - 2, color1); //  START ROW -2
  SetLEDByColorRef(x + 2, y - 2, color3);
  SetLEDByColorRef(x + 4, y - 2, color1);
  SetLightsByColorRef(x + 5, y - 2, 2, color2);
  SetLightsByColorRef(x + 2, y - 1, 5, color1); //  START ROW -1
  SetLightsByColorRef(x + 3, y + 0, 4, color1); //  START ROW +0
  SetLightsByColorRef(x + 2, y + 1, 5, color1); //  START ROW +1
  SetLightsByColorRef(x + 1, y + 2, 2, color1); //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 3, color1);
  SetLightsByColorRef(x + 0, y + 3, 6, color1); //  START ROW +3
  SetLightsByColorRef(x - 1, y + 4, 7, color1); //  START ROW +4
  SetLEDByColorRef(x - 2, y + 5, color2); //  START ROW +5
  SetLightsByColorRef(x - 1, y + 5, 6, color1);
  SetLEDByColorRef(x - 3, y + 6, color2);  //  START ROW +6
  SetLightsByColorRef(x - 2, y + 6, 5, color1);
}

void GhostScreen::MsPacManChompDanceThrough(int frameLengthMillis = 100, int animationFrameCount = 48, int frame = 255)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);
  
  CRGB body = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));
  CRGB bow = CRGB(GetColor(1, 0), GetColor(1, 1), GetColor(1, 2));
  CRGB eye = CRGB(GetColor(3, 0), GetColor(3, 1), GetColor(3, 2));

  if (frame % 8 == 0)       DrawMsPacManChomp01(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 1)  DrawMsPacManChomp01(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 2)  DrawMsPacManChomp02(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 3)  DrawMsPacManChomp02(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 4)  DrawMsPacManChomp03(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 5)  DrawMsPacManChomp03(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 6)  DrawMsPacManChomp02(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else                      DrawMsPacManChomp02(SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
}

void GhostScreen::DrawSpaceInvader01(int x, int y, CRGB& color1, CRGB& color2)
{
/*
 *   X     X
 *    X   X
 *   OOOOOOO 
 *  OO OOO OO
 * XXXXXXXXXXX
 * X XXXXXXX X
 * X X     X X
 *    XX XX
 */
 
  SetLEDByColorRef(x - 3, y - 4, color1); // START ROW -4
  SetLEDByColorRef(x + 3, y - 4, color1);
  SetLEDByColorRef(x - 2, y - 3, color1); // START ROW -3
  SetLEDByColorRef(x + 2, y - 3, color1);
  SetLightsByColorRef(x - 3, y - 2, 7, color2); // START ROW -2
  SetLightsByColorRef(x - 4, y - 1, 2, color2); //  START ROW -1
  SetLightsByColorRef(x - 1, y - 1, 3, color2);
  SetLightsByColorRef(x + 3, y - 1, 2, color2);
  SetLightsByColorRef(x - 5, y, 11, color1); //  START ROW +0
  SetLEDByColorRef(x - 5, y + 1, color1); //  START ROW +1
  SetLightsByColorRef(x - 3, y + 1, 7, color1);
  SetLEDByColorRef(x + 5, y + 1, color1);
  SetLEDByColorRef(x - 5, y + 2, color1); //  START ROW +2
  SetLEDByColorRef(x - 3, y + 2, color1);
  SetLEDByColorRef(x + 3, y + 2, color1);
  SetLEDByColorRef(x + 5, y + 2, color1);
  SetLightsByColorRef(x - 2, y + 3, 2, color1); //  START ROW +3
  SetLightsByColorRef(x + 1, y + 3, 2, color1);
}

void GhostScreen::DrawSpaceInvader02(int x, int y, CRGB& color1, CRGB& color2)
{
/*
 *   X     X
 *    X   X
 * O OOOOOOO O
 * OOO OOO OOO
 * XXXXXXXXXXX
 *   XXXXXXX 
 *   X     X 
 *  X       X
 */
 
  SetLEDByColorRef(x - 3, y - 4, color1); // START ROW -4
  SetLEDByColorRef(x + 3, y - 4, color1);
  SetLEDByColorRef(x - 2, y - 3, color1); // START ROW -3
  SetLEDByColorRef(x + 2, y - 3, color1);
  SetLEDByColorRef(x - 5, y - 2, color2); // START ROW -2
  SetLightsByColorRef(x - 3, y - 2, 7, color2);
  SetLEDByColorRef(x + 5, y - 2, color2);
  SetLightsByColorRef(x - 5, y - 1, 3, color2); //  START ROW -1
  SetLightsByColorRef(x - 1, y - 1, 3, color2);
  SetLightsByColorRef(x + 3, y - 1, 3, color2);
  SetLightsByColorRef(x - 5, y, 11, color1); //  START ROW +0
  SetLightsByColorRef(x - 3, y + 1, 7, color1); //  START ROW +1
  SetLEDByColorRef(x - 3, y + 2, color1); //  START ROW +2
  SetLEDByColorRef(x + 3, y + 2, color1);
  SetLEDByColorRef(x - 4, y + 3, color1); //  START ROW +3
  SetLEDByColorRef(x + 4, y + 3, color1);
}

void GhostScreen::SpaceInvaderDanceThrough(byte body = 7, byte mask = 7, int frame = 255)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(333, 40);

  CRGB color1 = CRGB(GetColor(body, 0), GetColor(body, 1), GetColor(body, 2));
  CRGB color2 = CRGB(GetColor(mask, 0), GetColor(mask, 1), GetColor(mask, 2));
  
  if (frame & 1)  DrawSpaceInvader01(frame - 6, 7, color1, color2);
  else            DrawSpaceInvader02(frame - 6, 7, color1, color2);
}


void GhostScreen::DrawLetter_A(int x, int y, CRGB& color)
{
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX

  SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  SetLightsByColorRef(x + 4, y - 3, 4, color);
  SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  SetLightsByColorRef(x + 4, y - 2, 4, color);
  SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  SetLightsByColorRef(x + 4, y - 1, 4, color);
  SetLightsByColorRef(x - 6, y + 0, 14, color);   //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 14, color);   //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 4, color);
  SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  SetLightsByColorRef(x + 4, y + 3, 4, color);
  SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  SetLightsByColorRef(x + 4, y + 4, 4, color);
  SetLightsByColorRef(x - 6, y + 5, 4, color);    //  START ROW +5
  SetLightsByColorRef(x + 4, y + 5, 4, color);
  SetLightsByColorRef(x - 6, y + 6, 4, color);    //  START ROW +6
  SetLightsByColorRef(x + 4, y + 6, 4, color);
}

void GhostScreen::DrawLetter_B(int x, int y, CRGB& color)
{
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXXXXXXXXXX
  // * XXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX

  SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  SetLightsByColorRef(x + 4, y - 3, 4, color);
  SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  SetLightsByColorRef(x + 4, y - 2, 4, color);
  SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  SetLightsByColorRef(x + 4, y - 1, 4, color);
  SetLightsByColorRef(x - 6, y + 0, 12, color);   //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 12, color);   //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 4, color);
  SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  SetLightsByColorRef(x + 4, y + 3, 4, color);
  SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  SetLightsByColorRef(x + 4, y + 4, 4, color);
  SetLightsByColorRef(x - 6, y + 5, 14, color);   //  START ROW +5
  SetLightsByColorRef(x - 6, y + 6, 14, color);   //  START ROW +6
}

void GhostScreen::DrawLetter_C(int x, int y, CRGB& color)
{
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXX
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX

  SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  SetLightsByColorRef(x - 6, y + 0, 4, color);    //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 4, color);    //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  SetLightsByColorRef(x - 6, y + 5, 14, color);   //  START ROW +5
  SetLightsByColorRef(x - 6, y + 6, 14, color);   //  START ROW +6
}

void GhostScreen::DrawLetter_R(int x, int y, CRGB& color)
{
  // * XXXXXXXXXXXXXX
  // * XXXXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXXXXXXXXXX
  // * XXXXXXXXXXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX
  // * XXXX      XXXX

  SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  SetLightsByColorRef(x + 4, y - 3, 4, color);
  SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  SetLightsByColorRef(x + 4, y - 2, 4, color);
  SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  SetLightsByColorRef(x + 4, y - 1, 4, color);
  SetLightsByColorRef(x - 6, y + 0, 12, color);   //  START ROW +0
  SetLightsByColorRef(x - 6, y + 1, 12, color);   //  START ROW +1
  SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  SetLightsByColorRef(x + 4, y + 2, 4, color);
  SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  SetLightsByColorRef(x + 4, y + 3, 4, color);
  SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  SetLightsByColorRef(x + 4, y + 4, 4, color);
  SetLightsByColorRef(x - 6, y + 5, 4, color);    //  START ROW +5
  SetLightsByColorRef(x + 4, y + 5, 4, color);
  SetLightsByColorRef(x - 6, y + 6, 4, color);    //  START ROW +6
  SetLightsByColorRef(x + 4, y + 6, 4, color);
}

void GhostScreen::LetterMoveThrough_BRC(int x = 21, int y = 6, int frameLengthMillis = 60, int animationFrameCount = 90)
{
  int frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  CRGB yellow = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));
  
  DrawLetter_B(x - frame, y, yellow);
  DrawLetter_R(x + 16 - frame, y, yellow);
  DrawLetter_C(x + 32 - frame, y, yellow);
}



//  NOTE: This is a 2D matrix screen animation that plays a diagonal flow of rainbow colors. Do not use this on 1D strip screens.
void GhostScreen::RainbowFlow2_2D(int hueChangeSpeed = 1, bool berzerk = false)
{
  static int delayTime = 125;
  
  if (FrameAnimation.IterateFrame(50))
  {
    static int rainbowPosition = 0;
    for (int i = 0; i < SCREEN_WIDTH * 2; ++i)
    {
      CRGB color = Wheel(((i * 1024 / LED_COUNT) + rainbowPosition) & 255);
      for (int j = 0; j < SCREEN_HEIGHT; ++j)
      {
        if (j < 0 || j >= SCREEN_WIDTH) continue;
        if ((i - j) < 0 || (i - j) >= SCREEN_WIDTH) continue;

        SetLEDByColorRef(i - j, j, color);
        if (berzerk) rainbowPosition += hueChangeSpeed;
      }
    }
    
    if (!berzerk) rainbowPosition += hueChangeSpeed;
    FastLED.show();
  }
}