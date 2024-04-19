#include <FastLED.h>

#include "FrameAnimation.h"

class GhostScreen {
  public:
    void Initialize(bool ledChutesLayout) {
      Chutes = ledChutesLayout;

      TranslateScreenVirtualIndices();
    }

    FrameAnimationManager FrameAnimation;

    inline void SetScreen(CRGB color) { fill_solid(LEDs, LED_COUNT, color); }
    inline void ClearScreen() { SetScreen(CRGB::Black); }
    

    inline bool IsPixelBlack(int x, int y) { int index = PositionToIndex(x, y); return (index != -1) ? (LEDs[index].r == 0 && LEDs[index].g == 0 && LEDs[index].b == 0) : false; }
    inline const CRGB& GetPixel(int x, int y) { return (IsPosOnScreen(x, y)) ? LEDs[PositionToIndex(x, y)] : CRGB::Black; }

    inline void SetLEDByColorIndex(int x, int y, byte colorIndex) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = CRGB(GetColor(colorIndex, 0), GetColor(colorIndex, 1), GetColor(colorIndex, 2)); }
    inline void SetLEDByColorRef(int x, int y, const CRGB& color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDByColor(int x, int y, const CRGB color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDIndexByColor(int index, CRGB color) { if (IsIndexOnScreen(index) == true) LEDs[index] = color; }
    inline void SetLightsByColorIndex(int x, int y, int count, byte colorIndex) { CRGB color = CRGB(GetColor(colorIndex, 0), GetColor(colorIndex, 1), GetColor(colorIndex, 2)); for (int i = 0; i < count; ++i) SetLEDByColorRef(x + i, y, color); }

    void ResetTetris(int x = (SCREEN_WIDTH / 2), int y = (SCREEN_HEIGHT / 2), byte colorIndex = 54);

    void DrawPacManChomp01(int x, int y, byte color);
    void DrawPacManChomp02(int x, int y, byte color);
    void DrawPacManChomp03(int x, int y, byte color);
    void DrawPacManGhostWalk01(int x, int y, byte bodyColor, byte eyeWhite, byte eyeBall);
    void DrawPacManGhostWalk02(int x, int y, byte bodyColor, byte eyeWhite, byte eyeBall);

    void PacManChompDanceThrough(int x, int y, int frameLength, int animationFrameCount, int frame);
    void PacManChompDanceThroughPlusGhost(int frameLength, int animationFrameCount);
    void PacManGhostDanceThrough(int x, int y, int frameLength, int body, int eyeWhite, int eyeBall, int animationTime, int frame);

    const int PATTERN_SWITCH_BUTTON_DELAY = 10000;
    unsigned long PatternSwitchTimer = PATTERN_SWITCH_BUTTON_DELAY;
    int PatternIndex = 0;
    inline void SetPatternIndex(int newIndex) { PatternIndex = newIndex; }
    inline bool SwitchPatterns() {
      if (millis() < PatternSwitchTimer) return false;
      else {
        PatternSwitchTimer = millis() + PATTERN_SWITCH_BUTTON_DELAY;
        Serial.println("Ghost Screen: Iterating to next pattern...");

        ClearScreen();
        UpdateMillisOffset();
        ++PatternIndex;
        if (PatternIndex == 0) ResetTetris();
        FrameAnimation.ResetAnimation();

        return true;
      }
    }

    static const int LED_COUNT = 158;
    static const int SCREEN_WIDTH = 14;
    static const int SCREEN_HEIGHT = 14;
    CRGB LEDs[LED_COUNT];

    void RainbowFlow2(int hueChangeSpeed, bool berzerk, bool nextFrameReady);

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

void GhostScreen::ResetTetris(int x = (SCREEN_WIDTH / 2), int y = (SCREEN_HEIGHT / 2), byte colorIndex = 54)
{
  ClearStrip(LEDs, LED_COUNT);
  SetLightsByColorIndex(x - 7, y - 7, 14, colorIndex); // START ROW -7
  SetLightsByColorIndex(x - 7, y - 6, 14, colorIndex); // START ROW -6
  SetLightsByColorIndex(x - 7, y - 5, 2, colorIndex); // START ROW -5
  SetLightsByColorIndex(x + 5, y - 5, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y - 4, 2, colorIndex); // START ROW -4
  SetLightsByColorIndex(x + 5, y - 4, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y - 3, 2, colorIndex); // START ROW -3
  SetLightsByColorIndex(x + 5, y - 3, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y - 2, 2, colorIndex); // START ROW -2
  SetLightsByColorIndex(x + 5, y - 2, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y - 1, 2, colorIndex); // START ROW -1
  SetLightsByColorIndex(x + 5, y - 1, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 0, 2, colorIndex); // START ROW +0
  SetLightsByColorIndex(x + 5, y + 0, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 1, 2, colorIndex); // START ROW +1
  SetLightsByColorIndex(x + 5, y + 1, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 2, 2, colorIndex); // START ROW +2
  SetLightsByColorIndex(x + 5, y + 2, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 3, 2, colorIndex); // START ROW +3
  SetLightsByColorIndex(x + 5, y + 3, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 4, 2, colorIndex); // START ROW +4
  SetLightsByColorIndex(x + 5, y + 4, 2, colorIndex);
  SetLightsByColorIndex(x - 7, y + 5, 14, colorIndex); // START ROW +5
  SetLightsByColorIndex(x - 7, y + 6, 14, colorIndex); // START ROW +6
}


void GhostScreen::PacManChompDanceThrough(int x = -6, int y = 7, int frameLengthMillis = 150, int animationFrameCount = 46, int frame = 255)
{
  if (frame == 255) frame = FrameAnimation.GetCurrentFrameIndex(animationFrameCount, frameLengthMillis);
  
  if (frame % 8 == 0)       DrawPacManChomp01(frame + x, y, 4);
  else if (frame % 8 == 1)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 2)  DrawPacManChomp03(frame + x, y, 4);
  else if (frame % 8 == 3)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 4)  DrawPacManChomp01(frame + x, y, 4);
  else if (frame % 8 == 5)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 6)  DrawPacManChomp03(frame + x, y, 4);
  else                      DrawPacManChomp02(frame + x, y, 4);
}

void GhostScreen::DrawPacManChomp01(int x, int y, byte color)
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
 
  SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorIndex(x - 4, y - 5, 9, color); //  START ROW -5
  SetLightsByColorIndex(x - 5, y - 4, 11, color); //  START ROW -4
  SetLightsByColorIndex(x - 5, y - 3, 11, color); //  START ROW -3
  SetLightsByColorIndex(x - 6, y - 2, 13, color); //  START ROW -2
  SetLightsByColorIndex(x - 6, y - 1, 13, color); //  START ROW -1
  SetLightsByColorIndex(x - 6, y + 0, 13, color); //  START ROW +0
  SetLightsByColorIndex(x - 6, y + 1, 13, color); //  START ROW +1
  SetLightsByColorIndex(x - 6, y + 2, 13, color); //  START ROW +2
  SetLightsByColorIndex(x - 5, y + 3, 11, color); //  START ROW +3
  SetLightsByColorIndex(x - 5, y + 4, 11, color); //  START ROW +4
  SetLightsByColorIndex(x - 4, y + 5, 9, color); //  START ROW +5
  SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::DrawPacManChomp02(int x, int y, byte color)
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
 
  SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorIndex(x - 4, y - 5, 9, color); //  START ROW -5
  SetLightsByColorIndex(x - 5, y - 4, 11, color); //  START ROW -4
  SetLightsByColorIndex(x - 5, y - 3, 11, color); //  START ROW -3
  SetLightsByColorIndex(x - 6, y - 2, 10, color); //  START ROW -2
  SetLightsByColorIndex(x - 6, y - 1, 7, color); //  START ROW -1
  SetLightsByColorIndex(x - 6, y + 0, 4, color); //  START ROW +0
  SetLightsByColorIndex(x - 6, y + 1, 7, color); //  START ROW +1
  SetLightsByColorIndex(x - 6, y + 2, 10, color); //  START ROW +2
  SetLightsByColorIndex(x - 5, y + 3, 11, color); //  START ROW +3
  SetLightsByColorIndex(x - 5, y + 4, 11, color); //  START ROW +4
  SetLightsByColorIndex(x - 4, y + 5, 9, color); //  START ROW +5
  SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::DrawPacManChomp03(int x, int y, byte color)
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
 
  SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  SetLightsByColorIndex(x - 4, y - 5, 7, color); //  START ROW -5
  SetLightsByColorIndex(x - 5, y - 4, 7, color); //  START ROW -4
  SetLightsByColorIndex(x - 5, y - 3, 6, color); //  START ROW -3
  SetLightsByColorIndex(x - 6, y - 2, 6, color); //  START ROW -2
  SetLightsByColorIndex(x - 6, y - 1, 5, color); //  START ROW -1
  SetLightsByColorIndex(x - 6, y + 0, 4, color); //  START ROW +0
  SetLightsByColorIndex(x - 6, y + 1, 5, color); //  START ROW +1
  SetLightsByColorIndex(x - 6, y + 2, 6, color); //  START ROW +2
  SetLightsByColorIndex(x - 5, y + 3, 6, color); //  START ROW +3
  SetLightsByColorIndex(x - 5, y + 4, 7, color); //  START ROW +4
  SetLightsByColorIndex(x - 4, y + 5, 7, color); //  START ROW +5
  SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void GhostScreen::PacManChompDanceThroughPlusGhost(int frameLength = 100, int animationFrameCount = 140)
{
  int frame = GetFrame(animationFrameCount, frameLength);

  PacManChompDanceThrough(-6, 7, frameLength, animationFrameCount, frame);
  PacManGhostDanceThrough(-26, 7, frameLength, 50, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-46, 7, frameLength, 51, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-66, 7, frameLength, 52, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-86, 7, frameLength, 53, 7, 0, animationFrameCount, frame);
}


void GhostScreen::PacManGhostDanceThrough(int x = 6, int y = 14, int frameLength = 48, int body = 50, int eyeWhite = 7, int eyeBall = 0, int animationTime = 100, int frame = 255)
{
  if (frame == 255) frame = GetFrame(frameLength, animationTime);
  
  if (frame % 4 == 0)       DrawPacManGhostWalk01(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 1)  DrawPacManGhostWalk01(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 2)  DrawPacManGhostWalk02(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 3)  DrawPacManGhostWalk02(frame + x, y, body, eyeWhite, eyeBall);
}

void GhostScreen::DrawPacManGhostWalk01(int x, int y, byte bodyColor = 50, byte eyeWhite = 7, byte eyeBall = 0)
{
  SetLightsByColorIndex(x - 2, y - 7, 4, bodyColor); // START ROW -7
  SetLightsByColorIndex(x - 4, y - 6, 8, bodyColor); // START ROW -6
  SetLightsByColorIndex(x - 5, y - 5, 10, bodyColor); // START ROW -5
  SetLightsByColorIndex(x - 6, y - 4, 3, bodyColor); // START ROW -4
  SetLightsByColorIndex(x - 3, y - 4, 2, eyeWhite);
  SetLightsByColorIndex(x - 1, y - 4, 4, bodyColor);
  SetLightsByColorIndex(x + 3, y - 4, 2, eyeWhite);
  SetLEDByColorIndex(x + 5, y - 4, bodyColor);
  SetLightsByColorIndex(x - 6, y - 3, 2, bodyColor); // START ROW -3
  SetLightsByColorIndex(x - 4, y - 3, 4, eyeWhite);
  SetLightsByColorIndex(x + 0, y - 3, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 3, 4, eyeWhite);
  SetLightsByColorIndex(x - 6, y - 2, 2, bodyColor); // START ROW -2
  SetLightsByColorIndex(x - 4, y - 2, 2, eyeWhite);
  SetLightsByColorIndex(x - 2, y - 2, 2, eyeBall);
  SetLightsByColorIndex(x + 0, y - 2, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 2, 2, eyeWhite);
  SetLightsByColorIndex(x + 4, y - 2, 2, eyeBall);
  SetLightsByColorIndex(x - 7, y - 1, 3, bodyColor); // START ROW -1
  SetLightsByColorIndex(x - 4, y - 1, 2, eyeWhite);
  SetLightsByColorIndex(x - 2, y - 1, 2, eyeBall);
  SetLightsByColorIndex(x + 0, y - 1, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 1, 2, eyeWhite);
  SetLightsByColorIndex(x + 4, y - 1, 2, eyeBall);
  SetLEDByColorIndex(x + 6, y - 1, bodyColor);
  SetLightsByColorIndex(x - 7, y + 0, 4, bodyColor); // START ROW +0
  SetLightsByColorIndex(x - 3, y + 0, 2, eyeWhite);
  SetLightsByColorIndex(x - 1, y + 0, 4, bodyColor);
  SetLightsByColorIndex(x + 3, y + 0, 2, eyeWhite);
  SetLightsByColorIndex(x + 5, y + 0, 2, bodyColor);
  SetLightsByColorIndex(x - 7, y + 1, 14, bodyColor); // START ROW +1
  SetLightsByColorIndex(x - 7, y + 2, 14, bodyColor); // START ROW +2
  SetLightsByColorIndex(x - 7, y + 3, 14, bodyColor); // START ROW +3
  SetLightsByColorIndex(x - 7, y + 4, 14, bodyColor); // START ROW +4
  SetLightsByColorIndex(x - 7, y + 5, 4, bodyColor); // START ROW +5
  SetLightsByColorIndex(x - 2, y + 5, 4, bodyColor);
  SetLightsByColorIndex(x + 3, y + 5, 4, bodyColor);
  SetLightsByColorIndex(x - 6, y + 6, 2, bodyColor); // START ROW +6
  SetLightsByColorIndex(x - 1, y + 6, 2, bodyColor);
  SetLightsByColorIndex(x + 4, y + 6, 2, bodyColor);
}

void GhostScreen::DrawPacManGhostWalk02(int x, int y, byte bodyColor = 50, byte eyeWhite = 7, byte eyeBall = 0)
{
  SetLightsByColorIndex(x - 2, y - 7, 4, bodyColor); // START ROW -7
  SetLightsByColorIndex(x - 4, y - 6, 8, bodyColor); // START ROW -6
  SetLightsByColorIndex(x - 5, y - 5, 10, bodyColor); // START ROW -5
  SetLightsByColorIndex(x - 6, y - 4, 3, bodyColor); // START ROW -4
  SetLightsByColorIndex(x - 3, y - 4, 2, eyeWhite);
  SetLightsByColorIndex(x - 1, y - 4, 4, bodyColor);
  SetLightsByColorIndex(x + 3, y - 4, 2, eyeWhite);
  SetLEDByColorIndex(x + 5, y - 4, bodyColor);
  SetLightsByColorIndex(x - 6, y - 3, 2, bodyColor); // START ROW -3
  SetLightsByColorIndex(x - 4, y - 3, 4, eyeWhite);
  SetLightsByColorIndex(x + 0, y - 3, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 3, 4, eyeWhite);
  SetLightsByColorIndex(x - 6, y - 2, 2, bodyColor); // START ROW -2
  SetLightsByColorIndex(x - 4, y - 2, 2, eyeWhite);
  SetLightsByColorIndex(x - 2, y - 2, 2, eyeBall);
  SetLightsByColorIndex(x + 0, y - 2, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 2, 2, eyeWhite);
  SetLightsByColorIndex(x + 4, y - 2, 2, eyeBall);
  SetLightsByColorIndex(x - 7, y - 1, 3, bodyColor); // START ROW -1
  SetLightsByColorIndex(x - 4, y - 1, 2, eyeWhite);
  SetLightsByColorIndex(x - 2, y - 1, 2, eyeBall);
  SetLightsByColorIndex(x + 0, y - 1, 2, bodyColor);
  SetLightsByColorIndex(x + 2, y - 1, 2, eyeWhite);
  SetLightsByColorIndex(x + 4, y - 1, 2, eyeBall);
  SetLEDByColorIndex(x + 6, y - 1, bodyColor);
  SetLightsByColorIndex(x - 7, y + 0, 4, bodyColor); // START ROW +0
  SetLightsByColorIndex(x - 3, y + 0, 2, eyeWhite);
  SetLightsByColorIndex(x - 1, y + 0, 4, bodyColor);
  SetLightsByColorIndex(x + 3, y + 0, 2, eyeWhite);
  SetLightsByColorIndex(x + 5, y + 0, 2, bodyColor);
  SetLightsByColorIndex(x - 7, y + 1, 14, bodyColor); // START ROW +1
  SetLightsByColorIndex(x - 7, y + 2, 14, bodyColor); // START ROW +2
  SetLightsByColorIndex(x - 7, y + 3, 14, bodyColor); // START ROW +3
  SetLightsByColorIndex(x - 7, y + 4, 14, bodyColor); // START ROW +4
  SetLightsByColorIndex(x - 7, y + 5, 2, bodyColor); // START ROW +5
  SetLightsByColorIndex(x - 4, y + 5, 3, bodyColor);
  SetLightsByColorIndex(x + 1, y + 5, 3, bodyColor);
  SetLightsByColorIndex(x + 5, y + 5, 2, bodyColor);
  SetLEDByColorIndex(x - 7, y + 6, bodyColor); // START ROW +6
  SetLightsByColorIndex(x - 3, y + 6, 2, bodyColor);
  SetLightsByColorIndex(x + 1, y + 6, 2, bodyColor);
  SetLEDByColorIndex(x + 6, y + 6, bodyColor);
}


//  NOTE: This is a 2D matrix screen animation that plays a diagonal flow of rainbow colors. Do not use this on 1D strip screens.
void GhostScreen::RainbowFlow2(int hueChangeSpeed = 1, bool berzerk = false, bool nextFrameReady = false)
{
  static int delayTime = 125;
  
  if (nextFrameReady)
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
    
    nextFrameMillis += delayTime;
  }
}