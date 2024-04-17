#include <FastLED.h>

#include "NES_Controller.h"
#include "Patterns.h"
#include "GhostScreen.h"
#include "OuterRing.h"

#define GHOST_SCREEN_DATA_PIN         2         //  The WS2801 string data pin for the inner ghost screen
#define GHOST_SCREEN_CLOCK_PIN        4         //  The WS2801 string clock pin for the inner ghost screen
#define OUTER_RING_DATA_PIN            6         //  The WS2801 string data pin for the outer ring lights
#define OUTER_RING_CLOCK_PIN           8         //  The WS2801 string clock pin for the outer ring lights

#define NES_DATA_PIN            10
#define NES_CLOCK_PIN           11
#define NES_LATCH_PIN           12

#define BRIGHTNESS              20                                //  The number (0 to 200) for the brightness setting)

#define TETRIS_BOARD_START_X    7
#define TETRIS_BOARD_START_Y    -2
#define TETRIS_BOARD_WIDTH      14
#define TETRIS_BOARD_HEIGHT     16

#define GHOST_CART_HARDWARE     false

//  "Iterate" button, which when pressed will iterate to the next pattern
unsigned long iterateButtonTimer = 0;
byte patternIndex = 0;

NES_Controller nesController(NES_DATA_PIN, NES_CLOCK_PIN, NES_LATCH_PIN);
GhostScreen ghostScreen;
OuterRing outerRing;

void SerialProgramInit() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("Program START!");
}

void ResetTetris(int x = 14, int y = 13, byte outerBG = 54, byte innerBG = 0)
{
  ghostScreen.SetLightsByColorIndex(x - 14, y - 13, 28, outerBG); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x - 14, y - 12, 28, outerBG); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x - 14, y - 11, 28, outerBG); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x - 14, y - 10, 28, outerBG); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 14, y - 9, 9, outerBG); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 5, y - 9, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 9, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 9, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 8, 9, outerBG); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 5, y - 8, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 8, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 8, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 8, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 7, 9, outerBG); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 5, y - 7, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 7, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 7, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 6, 9, outerBG); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 6, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 6, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 5, 9, outerBG); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 5, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 5, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 5, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 4, 9, outerBG); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 10, innerBG);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, outerBG);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 4, 6, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 12, y - 4, 2, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 3, 9, outerBG); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 3, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 2, 9, outerBG); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 5, y - 2, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 2, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y - 1, 9, outerBG); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 5, y - 1, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 1, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 0, 9, outerBG); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 5, y + 0, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 0, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 1, 9, outerBG); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 5, y + 1, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 1, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 2, 9, outerBG); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 5, y + 2, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 3, 9, outerBG); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 3, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 4, 9, outerBG); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 4, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 5, 9, outerBG); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 5, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 6, 9, outerBG); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 7, 9, outerBG); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 5, y + 7, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 7, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 8, 9, outerBG); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 5, y + 8, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 8, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 9, 9, outerBG); // START ROW +9
  ghostScreen.SetLightsByColorIndex(x - 5, y + 9, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 9, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 10, 9, outerBG); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 10, innerBG);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 10, 9, outerBG);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 11, 28, outerBG); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 14, y + 12, 28, outerBG); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 14, y + 13, 28, outerBG); // START ROW +13
  ghostScreen.SetLightsByColorIndex(x - 14, y + 14, 28, outerBG); // START ROW +14
}

void RainbowFlow2(int hueChangeSpeed = 1, bool berzerk = false)
{
  static int delayTime = 125;
  
  if (IsNextFrameReady())
  {
    static int rainbowPosition = 0;
    for (int i = 0; i < ghostScreen.SCREEN_WIDTH * 2; ++i)
    {
      CRGB color = Wheel(((i * 1024 / ghostScreen.LED_COUNT) + rainbowPosition) & 255);
      for (int j = 0; j < ghostScreen.SCREEN_HEIGHT; ++j)
      {
        if (j < 0 || j >= ghostScreen.SCREEN_WIDTH) continue;
        if ((i - j) < 0 || (i - j) >= ghostScreen.SCREEN_WIDTH) continue;

        ghostScreen.SetLEDByColorRef(i - j, j, color);
        if (berzerk) rainbowPosition += hueChangeSpeed;
      }
    }
    
    if (!berzerk) rainbowPosition += hueChangeSpeed;
    FastLED.show();
    
    nextFrameMillis += delayTime;
  }
}

void DrawLetter_A(int x, int y, byte color)
{
/*
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
*/
  ghostScreen.SetLightsByColorIndex(x - 6, y - 5, 14, color);   //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 14, color);   //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 4, color);    //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 4, color);    //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 4, color);    //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 4, y - 1, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 14, color);   //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 14, color);   //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 4, color);    //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 4, color);    //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x + 4, y + 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 4, color);    //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 5, 4, color);    //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x + 4, y + 5, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 4, color);    //  START ROW +6
  ghostScreen.SetLightsByColorIndex(x + 4, y + 6, 4, color);
}

void DrawLetter_B(int x, int y, byte color)
{
/*
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXXXXXXXXXX
 * XXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
*/
  ghostScreen.SetLightsByColorIndex(x - 6, y - 5, 14, color);   //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 14, color);   //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 4, color);    //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 4, color);    //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 4, color);    //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 4, y - 1, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 12, color);   //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 12, color);   //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 4, color);    //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 4, color);    //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x + 4, y + 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 4, color);    //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 5, 14, color);   //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 14, color);   //  START ROW +6
}

void DrawLetter_C(int x, int y, byte color)
{
/*
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXX
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
*/
  ghostScreen.SetLightsByColorIndex(x - 6, y - 5, 14, color);   //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 14, color);   //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 4, color);    //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 4, color);    //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 4, color);    //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 4, color);    //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 4, color);    //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 4, color);    //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 4, color);    //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 4, color);    //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 6, y + 5, 14, color);   //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 14, color);   //  START ROW +6
}

void DrawLetter_R(int x, int y, byte color)
{
/*
 * XXXXXXXXXXXXXX
 * XXXXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXXXXXXXXXX
 * XXXXXXXXXXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
 * XXXX      XXXX
*/
  ghostScreen.SetLightsByColorIndex(x - 6, y - 5, 14, color);   //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 14, color);   //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 4, color);    //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 4, color);    //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 4, color);    //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 4, y - 1, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 12, color);   //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 12, color);   //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 4, color);    //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 4, color);    //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x + 4, y + 3, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 4, color);    //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 5, 4, color);    //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x + 4, y + 5, 4, color);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 4, color);    //  START ROW +6
  ghostScreen.SetLightsByColorIndex(x + 4, y + 6, 4, color);
}

void DrawPacManChomp01(int x, int y, byte color)
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
 
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 4, y - 5, 9, color); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 11, color); //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 11, color); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 13, color); //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 13, color); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 13, color); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 13, color); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 13, color); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 11, color); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 11, color); //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 9, color); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void DrawPacManChomp02(int x, int y, byte color)
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
 
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 4, y - 5, 9, color); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 11, color); //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 11, color); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 10, color); //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 7, color); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 4, color); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 7, color); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 10, color); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 11, color); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 11, color); //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 9, color); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void DrawPacManChomp03(int x, int y, byte color)
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
 
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 5, color); //  START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 4, y - 5, 7, color); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 7, color); //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 6, color); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 6, color); //  START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 5, color); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 4, color); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 5, color); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 6, color); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 6, color); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 7, color); //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 7, color); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color); //  START ROW +6
}

void LetterMoveThrough_BRC(int x = 21, int y = 6, int frameLength = 60, int animationFrameCount = 90)
{
  int frame = GetFrame(animationFrameCount, frameLength);

  DrawLetter_B(x - frame, y, 4);
  DrawLetter_R(x + 16 - frame, y, 4);
  DrawLetter_C(x + 32 - frame, y, 4);
}

void PacManChompDanceThrough(int x = -6, int y = 7, int frameLength = 100, int animationFrameCount = 46, int frame = 255)
{
  if (frame == 255) frame = GetFrame(animationFrameCount, frameLength);
  
  if (frame % 8 == 0)       DrawPacManChomp01(frame + x, y, 4);
  else if (frame % 8 == 1)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 2)  DrawPacManChomp03(frame + x, y, 4);
  else if (frame % 8 == 3)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 4)  DrawPacManChomp01(frame + x, y, 4);
  else if (frame % 8 == 5)  DrawPacManChomp02(frame + x, y, 4);
  else if (frame % 8 == 6)  DrawPacManChomp03(frame + x, y, 4);
  else                      DrawPacManChomp02(frame + x, y, 4);
}

void DrawMsPacManChomp01(int x, int y, byte color1, byte color2, byte color3)
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

  ghostScreen.SetLightsByColorIndex(x + 3, y - 7, 2, color2); //  START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 4, color1); //  START ROW -6 
  ghostScreen.SetLightsByColorIndex(x + 2, y - 6, 3, color2);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 5, 6, color1); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x + 2, y - 5, 2, color2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, color3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 9, color1); //  START ROW -4
  ghostScreen.SetLEDByColorIndex(x + 4, y - 4, color2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, color3);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 4, 2, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 10, color1); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 5, y - 3, 3, color2);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 5, color1); //  START ROW -2
  ghostScreen.SetLEDByColorIndex(x + 4, y - 2, color1);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 2, 2, color2);
  ghostScreen.SetLEDByColorIndex(x - 7, y - 1, color2); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 13, color1);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 0, 2, color2); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 5, y + 0, 12, color1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 1, color2); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 13, color1);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 9, color1); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 3, color1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 11, color1); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 11, color1); //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 9, color1); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color1); //  START ROW +6
}

void DrawMsPacManChomp02(int x, int y, byte color1, byte color2, byte color3)
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

  ghostScreen.SetLightsByColorIndex(x + 3, y - 7, 2, color2); //  START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 4, color2); //  START ROW -6 
  ghostScreen.SetLightsByColorIndex(x + 2, y - 6, 3, color2);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 5, 4, color1); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x + 2, y - 5, 2, color2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, color3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 9, color1); //  START ROW -4
  ghostScreen.SetLEDByColorIndex(x + 4, y - 4, color2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, color3);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 4, 2, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 2, color2); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 3, y - 3, 3, color1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 3, color1);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 3, 3, color2);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 2, 2, color1); //  START ROW -2
  ghostScreen.SetLEDByColorIndex(x + 1, y - 2, color3);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 2, 2, color1);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 2, 2, color2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 1, 6, color1); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 3, y + 0, 4, color1); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 1, y + 1, 6, color1); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 1, y + 2, 4, color1); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 3, color1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 2, color2); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 3, y + 3, 9, color1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 11, color1); //  START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 9, color1); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color1); //  START ROW +6
}

void DrawMsPacManChomp03(int x, int y, byte color1, byte color2, byte color3)
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

  ghostScreen.SetLightsByColorIndex(x + 3, y - 7, 2, color2); //  START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 6, color2); //  START ROW -6 
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 4, color1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 6, 3, color2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 5, color2); //  START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 1, y - 5, 3, color1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 5, 2, color2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, color3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, color2);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 4, 2, color1); //  START ROW -4
  ghostScreen.SetLightsByColorIndex(x + 2, y - 4, 2, color1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 4, color2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, color3);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 4, 2, color2);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, color1); //  START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 3, y - 3, 2, color1);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 3, 3, color2);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 2, color1); //  START ROW -2
  ghostScreen.SetLEDByColorIndex(x + 2, y - 2, color3);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 2, color1);
  ghostScreen.SetLightsByColorIndex(x + 5, y - 2, 2, color2);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, color1); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 3, y + 0, 4, color1); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 2, y + 1, 5, color1); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, color1); //  START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 3, color1);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 3, 6, color1); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 1, y + 4, 7, color1); //  START ROW +4
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, color2); //  START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 6, color1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 6, color2);  //  START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 2, y + 6, 5, color1);
}

void MsPacManChompDanceThrough(int frameLength = 100, int animationFrameCount = 48)
{
  int frame = GetFrame(animationFrameCount, frameLength);
  
  if (frame % 8 == 0)       DrawMsPacManChomp01(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 1)  DrawMsPacManChomp01(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 2)  DrawMsPacManChomp02(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 3)  DrawMsPacManChomp02(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 4)  DrawMsPacManChomp03(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 5)  DrawMsPacManChomp03(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else if (frame % 8 == 6)  DrawMsPacManChomp02(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
  else                      DrawMsPacManChomp02(ghostScreen.SCREEN_WIDTH - frame + 6, 7, 4, 1, 3);
}

void DrawPacManGhostWalk01(int x, int y, byte bodyColor = 50, byte eyeWhite = 7, byte eyeBall = 0)
{
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 4, bodyColor); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 4, y - 6, 8, bodyColor); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 5, y - 5, 10, bodyColor); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 3, bodyColor); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 4, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 4, 2, eyeWhite);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 2, bodyColor); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 4, y - 3, 4, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 3, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 4, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 2, bodyColor); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 2, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 2, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 1, 3, bodyColor); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 1, 2, eyeBall);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 1, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 0, 4, bodyColor); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 0, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 0, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 0, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 1, 14, bodyColor); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 7, y + 2, 14, bodyColor); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 7, y + 3, 14, bodyColor); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 7, y + 4, 14, bodyColor); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 7, y + 5, 4, bodyColor); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 2, y + 5, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 5, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 2, bodyColor); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 6, 2, bodyColor);
}

void DrawPacManGhostWalk02(int x, int y, byte bodyColor = 50, byte eyeWhite = 7, byte eyeBall = 0)
{
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 4, bodyColor); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 4, y - 6, 8, bodyColor); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 5, y - 5, 10, bodyColor); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 3, bodyColor); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 4, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 4, 2, eyeWhite);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 2, bodyColor); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 4, y - 3, 4, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 3, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 4, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 2, bodyColor); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 2, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 2, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 1, 3, bodyColor); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, eyeBall);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 1, 2, eyeBall);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 1, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 0, 4, bodyColor); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 0, 4, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 0, 2, eyeWhite);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 0, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 1, 14, bodyColor); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 7, y + 2, 14, bodyColor); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 7, y + 3, 14, bodyColor); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 7, y + 4, 14, bodyColor); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 7, y + 5, 2, bodyColor); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 4, y + 5, 3, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 5, 3, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 5, 2, bodyColor);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 6, bodyColor); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, bodyColor);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 6, 2, bodyColor);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 6, bodyColor);
}

void PacManGhostDanceThrough(int x = 6, int y = 14, int frameLength = 48, int body = 50, int eyeWhite = 7, int eyeBall = 0, int animationTime = 100, int frame = 255)
{
  if (frame == 255) frame = GetFrame(frameLength, animationTime);
  
  if (frame % 4 == 0)       DrawPacManGhostWalk01(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 1)  DrawPacManGhostWalk01(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 2)  DrawPacManGhostWalk02(frame + x, y, body, eyeWhite, eyeBall);
  else if (frame % 4 == 3)  DrawPacManGhostWalk02(frame + x, y, body, eyeWhite, eyeBall);
}

void PacManChompDanceThroughPlusGhost(int frameLength = 100, int animationFrameCount = 140)
{
  int frame = GetFrame(animationFrameCount, frameLength);

  PacManChompDanceThrough(-6, 7, frameLength, animationFrameCount, frame);
  PacManGhostDanceThrough(-26, 7, frameLength, 50, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-46, 7, frameLength, 51, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-66, 7, frameLength, 52, 7, 0, animationFrameCount, frame);
  PacManGhostDanceThrough(-86, 7, frameLength, 53, 7, 0, animationFrameCount, frame);
}

void DrawSpaceInvader01(int x, int y, byte color1 = 7, byte color2 = 7)
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
 
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, color1); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x + 3, y - 4, color1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, color1); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x + 2, y - 3, color1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 2, 7, color2); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, color2); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 1, y - 1, 3, color2);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 1, 2, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y, 11, color1); //  START ROW +0
  ghostScreen.SetLEDByColorIndex(x - 5, y + 1, color1); //  START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 7, color1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 1, color1);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, color1); //  START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 3, y + 2, color1);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, color1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 2, color1);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 2, color1); //  START ROW +3
  ghostScreen.SetLightsByColorIndex(x + 1, y + 3, 2, color1);
}

void DrawSpaceInvader02(int x, int y, byte color1 = 7, byte color2 = 7)
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
 
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, color1); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x + 3, y - 4, color1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, color1); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x + 2, y - 3, color1);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, color2); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 3, y - 2, 7, color2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 2, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 1, 3, color2); //  START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 1, y - 1, 3, color2);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 1, 3, color2);
  ghostScreen.SetLightsByColorIndex(x - 5, y, 11, color1); //  START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 7, color1); //  START ROW +1
  ghostScreen.SetLEDByColorIndex(x - 3, y + 2, color1); //  START ROW +2
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, color1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, color1); //  START ROW +3
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, color1);
}

void SpaceInvaderDanceThrough(byte color1 = 7, byte color2 = 7)
{
  int frame = GetFrame(40);
  
  if (frame & 1)  DrawSpaceInvader01(frame - 6, 7, color1, color2);
  else            DrawSpaceInvader02(frame - 6, 7, color1, color2);
}

void DrawMegaManRun01(int x, int y, byte outline, byte body1, byte body2, byte skin, byte eyes)
{
/*
 *              OOO
 *            OOObbO
 *           OBBBObbO
 *          OBBBBBOOOO
 *          OBBBBBObbBO
 *         ObBBBBBBOOBO
 *         ObBBSEEEBBEO
 *       OOObBSEEOOSOEO
 *     OObbbOBSEEOOSOEO
 *    OBBBbbbOSSEEESESO
 *   OBBBBbbObbSOOOOSO   // <-- 0
 *   OBBBOOObbbbBSSSOOO
 *   OBBBO ObbbbbOOOBBBO
 *    OOO OBbOBbbBBBBBBO
 *   OBBOOOBBbOBbBBBBBBO
 *  OBBBBObBBBBOOOOOOOO
 * OBBBBBbbbBBBBbbbO
 * OBBOBBbbbOOObbbBBO
 *  OOOOBBbO   OBBBBO
 *      OOO    OBBBOOO
 *            OBBBBBBBO
 *            OOOOOOOOO
 */
 
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 3, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 2, y - 9, 3, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 2, y - 8, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 8, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 3, y - 7, 5, body1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 7, 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 6, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 3, y - 6, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 6, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, body2);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 6, body1);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 4, outline); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x - 4, y - 4, body2);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 3, eyes);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, eyes);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 3, 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, skin);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 3, skin);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 9, y - 2, 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 7, y - 2, 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 2, skin);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 2, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 2, skin);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 2, eyes);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 10, y - 1, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 9, y - 1, 3, body1);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 1, 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 1, skin);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 1, eyes);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 1, skin);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 0, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 10, y + 0, 4, body1);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 0, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 0, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 0, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 10, y + 1, 3, body1);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 1, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 1, 4, body2);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 1, body1);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 1, 3, skin);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 1, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 2, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 10, y + 2, 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 5, body2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 10, y + 3, 3, outline); // START ROW +3
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 3, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 3, 2, body2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 3, 6, body1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 10, y + 4, 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, body2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 4, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 4, body2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 6, body1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 12, y + 5, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 11, y + 5, 4, body1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, body2);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 4, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 13, y + 6, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 12, y + 6, 5, body1);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 6, 3, body2);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 6, 4, body1);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 6, 3, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 13, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 12, y + 7, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 10, y + 7, outline);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 7, 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 3, body2);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 7, 3, body2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 7, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 7, outline);
  ghostScreen.SetLightsByColorIndex(x - 12, y + 8, 4, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 8, y + 8, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 8, body2);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 8, 4, body1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 9, 3, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 1, y + 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 9, 3, body1);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 9, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 1, y + 10, 7, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 11, 9, outline); // START ROW +11
}

void DrawMegaManRun02(int x, int y, byte outline, byte body1, byte body2, byte skin, byte eyes)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x - 1, y - 10, 3, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x + 2, y - 10, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 9, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 2, y - 8, 5, body1);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 8, 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, outline); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 7, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 7, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 7, body1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 6, outline); // START ROW -6
  ghostScreen.SetLEDByColorIndex(x - 3, y - 6, body2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 6, body1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, body1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 3, y - 5, body2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 5, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 5, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 5, 3, eyes);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 5, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, outline); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, body2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 4, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 4, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 4, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 4, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 3, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 3, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 6, y - 2, 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 2, 2, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 2, 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 2, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 2, eyes);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 2, skin);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 8, y - 1, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 7, y - 1, 5, body2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 1, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 1, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 1, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 1, skin);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 0, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 7, y + 0, 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 6, y + 1, 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 1, 2, body2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 2, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 6, y + 2, 4, body1);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 2, 4, body2);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 3, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 3, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 4, y + 4, 4, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 4, body1);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 4, 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, body2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 7, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 9, outline); // START ROW +9
  ghostScreen.SetLightsByColorIndex(x - 5, y + 9, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 3, body1);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 11, outline); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 4, y + 11, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 11, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 12, 6, outline); // START ROW +12
}

void DrawMegaManRun03(int x, int y, byte outline, byte body1, byte body2, byte skin, byte eyes)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 10, 3, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 3, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x + 2, y - 9, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 1, y - 8, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 8, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, outline); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 5, body1);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 7, 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 6, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 2, y - 6, 5, body1);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 6, 2, body2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 5, 3, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 3, y - 5, body2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 5, 6, body1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y - 4, 2, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 6, y - 4, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, body2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, eyes);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 4, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 8, y - 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 7, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y - 3, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 3, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 3, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 10, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 9, y - 2, 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 2, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skin);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 2, eyes);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 2, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 2, eyes);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 9, y - 2, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y - 1, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 10, y - 1, 4, body1);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 1, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 1, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 1, 2, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 1, 3, eyes);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 1, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 1, eyes);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 1, skin);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 1, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 9, y - 1, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 12, y - 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 0, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x - 10, y + 0, 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 0, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 0, body1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 0, skin);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 0, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, skin);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 0, eyes);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 9, y + 0, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 12, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 10, y + 1, 3, body1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 1, 3, body2);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 1, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 5, skin);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, body2);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 1, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 9, y + 1, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 12, y + 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 10, y + 2, 3, outline); // START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 2, 3, body2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 2, 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 3, body2);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 2, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 11, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 3, 2, outline); // START ROW +3
  ghostScreen.SetLEDByColorIndex(x - 5, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 3, 3, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 3, 5, body2);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 3, 2, body2);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 3, 3, body1);
  ghostScreen.SetLEDByColorIndex(x + 10, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 4, 6, body1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 4, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 4, body2);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 4, 2, body1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 10, y + 5, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 9, y + 5, 4, body1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 3, body2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 5, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 6, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 10, y + 6, 5, body1);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 6, body2);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 6, body1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 4, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 11, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 10, y + 7, 2, body1);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 7, outline);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 2, body1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 7, 3, body2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 7, 3, body2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 7, body1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 7, outline);
  ghostScreen.SetLightsByColorIndex(x - 10, y + 8, 4, outline); // START ROW +8
  ghostScreen.SetLEDByColorIndex(x - 6, y + 8, body1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 8, 2, body2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 8, 4, body1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 3, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 1, y + 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 9, 3, body1);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 9, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 1, y + 10, 7, body1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 11, 9, outline); // START ROW +11
}

void MegaManRunThrough()
{
  int frame = GetFrame(52, 90);

  ghostScreen.SetScreen(CRGB(GetColor(8, 0), GetColor(8, 1), GetColor(8, 2)));
  
  if (frame % 8 == 0)       DrawMegaManRun01(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 1)  DrawMegaManRun01(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 2)  DrawMegaManRun02(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 3)  DrawMegaManRun02(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 4)  DrawMegaManRun03(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 5)  DrawMegaManRun03(frame - 14, 7, 0, 9, 10, 11, 7);
  else if (frame % 8 == 6)  DrawMegaManRun02(frame - 14, 7, 0, 9, 10, 11, 7);
  else                      DrawMegaManRun02(frame - 14, 7, 0, 9, 10, 11, 7);
}

void DrawMarioWarp01(int x, int y, byte outline = 0, byte skintone = 12, byte outfit = 34)
{
  ghostScreen.SetLightsByColorIndex(x - 4, y - 13, 3, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 5, y - 13, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 12, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x - 3, y - 12, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 12, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 12, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 11, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x - 3, y - 11, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 11, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 4, outfit);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 11, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 10, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 3, y - 10, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 5, outfit);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 3, y - 9, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 3, outfit);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 9, 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, outfit);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, outfit);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 1, y - 6, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 5, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 1, 2, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 1, 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 2, 4, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 4, outfit);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 2, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 2, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 8, y + 3, 4, skintone);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 3, 4, outfit);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 3, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 3, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 3, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, outfit);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 4, 3, outfit);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 5, 8, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, outfit);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLEDByColorIndex(x - 12, y + 6, outfit);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 6, 2, outfit);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 6, skintone);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 13, y + 7, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 7, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 7, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 13, y + 8, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 8, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 8, outfit);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 8, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 8, 12, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 12, y + 9, outfit);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 9, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 9, outfit);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 9, outfit);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 13, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 10, 5, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 8, y + 10, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 10, 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 11, outline); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 8, y + 11, 3, outfit);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 12, outline); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 8, y + 12, 2, outfit);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, outfit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 13, 2, outline); // START ROW +13
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline);
}

void DrawMarioWarp02(int x, int y, byte outline = 0, byte skintone1 = 15, byte raccoon1 = 17, byte skintone2 = 14, byte red3 = 27, byte raccoon2 = 18, byte red2 = 26, byte red1 = 25, byte skintone3 = 21, byte overalls2 = 23, byte overalls1 = 22, byte raccoon3 = 7, byte raccoon4 = 24, byte raccoon5 = 19, byte goldshoes = 20)
{
  ghostScreen.SetLightsByColorIndex(x - 4, y - 13, 3, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 5, y - 13, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 12, outline); // START ROW -12
  ghostScreen.SetLEDByColorIndex(x - 3, y - 12, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 12, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 12, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 12, raccoon1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 11, outline); // START ROW -11
  ghostScreen.SetLEDByColorIndex(x - 3, y - 11, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 11, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 11, raccoon1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 11, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, red3);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 11, raccoon2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 10, outline); // START ROW -10
  ghostScreen.SetLEDByColorIndex(x - 3, y - 10, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 10, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 10, raccoon2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 3, red2);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 10, 2, red3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 3, y - 9, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 2, red2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, red1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, red1);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLEDByColorIndex(x - 1, y - 6, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 6, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 5, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 3, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 1, 2, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 2, red2);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 1, 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 2, 4, outline); // START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 4, y + 2, red2);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 2, 2, red3);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 2, red2);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 2, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, red2);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 2, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 8, y + 3, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 3, 3, red2);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 3, red1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, red2);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 3, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 3, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 3, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, red1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 4, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 2, red1);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 5, 8, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, red1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 5, overalls1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 5, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 5, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLEDByColorIndex(x - 12, y + 6, raccoon1);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 6, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 6, 2, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 2, overalls1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 6, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 6, 2, raccoon3);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 6, 2, raccoon4);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 6, raccoon3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 13, y + 7, 2, raccoon1);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 7, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 7, 2, raccoon1);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 3, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 7, 3, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 7, 2, raccoon3);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 7, raccoon4);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 7, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, raccoon3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 13, y + 8, 2, raccoon2);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 8, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 8, raccoon2);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 8, 2, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 3, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 8, 7, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 12, y + 9, raccoon2);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 9, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 9, raccoon2);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 9, raccoon1);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 9, 5, overalls1);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 9, 3, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 9, 2, overalls1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 10, 5, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 8, y + 10, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 10, raccoon5);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 4, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 10, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 10, 3, overalls1);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 10, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 8, y + 11, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 11, raccoon5);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, goldshoes);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 11, 2, overalls1);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 12, outline); // START ROW +12
  ghostScreen.SetLEDByColorIndex(x - 8, y + 12, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 12, goldshoes);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 12, raccoon1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 12, raccoon5);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 13, 2, outline); // START ROW +13
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline);
}

void DrawMarioWarp03(int x, int y, byte outline = 0, byte skintone = 12, byte raccoon = 28)
{
  ghostScreen.SetLightsByColorIndex(x - 4, y - 13, 2, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 0, y - 13, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 13, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 12, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x - 4, y - 12, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 12, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 12, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 11, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x - 4, y - 11, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 6, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 11, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 10, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 4, y - 10, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 10, 7, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 4, y - 9, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 9, 9, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 5, y - 8, 12, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 7, outline); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 5, y - 7, 6, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 7, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 7, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 6, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 5, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 5, outline); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 5, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 5, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 4, y - 3, 3, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 3, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 1, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 3, y - 1, 3, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 1, 2, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 2, 4, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 2, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 8, y + 3, 5, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 3, 3, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 3, 5, raccoon);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 6, skintone);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 4, 3, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 4, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 4, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 4, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 5, 8, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 5, 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLEDByColorIndex(x - 12, y + 6, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 6, 2, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 6, skintone);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 3, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 6, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 13, y + 7, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 7, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 7, 5, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 7, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 13, y + 8, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 8, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 8, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 8, skintone);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 8, 5, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 8, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 12, y + 9, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 9, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 9, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 9, skintone);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 5, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 9, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 10, 5, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 8, y + 10, skintone);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 10, 4, raccoon);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 10, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 10, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 8, y + 11, skintone);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 11, 2, raccoon);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 11, 4, raccoon);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 12, outline); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 8, y + 12, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 13, 2, outline); // START ROW +13
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline);
}

void DrawMarioWarp04(int x, int y, byte outline = 0, byte skintone2 = 15, byte tanuki1 = 30, byte skintone1 = 14, byte tanuki2 = 31, byte tanuki3 = 32, byte skintone3 = 21, byte belly = 16, byte tanuki4 = 17, byte tanuki5 = 19, byte goldshoes = 20)
{
  ghostScreen.SetLightsByColorIndex(x - 4, y - 13, 2, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 0, y - 13, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 13, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 12, outline); // START ROW -12
  ghostScreen.SetLEDByColorIndex(x - 4, y - 12, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 12, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 12, 4, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 12, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 11, outline); // START ROW -11
  ghostScreen.SetLEDByColorIndex(x - 4, y - 11, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 11, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 11, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 11, 4, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 11, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 11, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 10, outline); // START ROW -10
  ghostScreen.SetLEDByColorIndex(x - 4, y - 10, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 10, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 10, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 2, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 10, 2, tanuki3);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 10, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 9, outline); // START ROW -9
  ghostScreen.SetLEDByColorIndex(x - 4, y - 9, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 9, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 9, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 2, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 4, tanuki3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 9, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 9, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 5, y - 8, 3, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 8, 8, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 8, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 7, outline); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 5, y - 7, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 7, 3, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 7, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 7, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 7, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 6, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 6, 2, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 6, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 5, outline); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x - 5, y - 5, 2, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 5, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 5, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 4, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 3, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 4, y - 3, 3, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 3, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 1, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 3, y - 1, 3, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 1, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 1, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 1, 2, outline); // START ROW +1
  ghostScreen.SetLEDByColorIndex(x - 3, y + 1, tanuki2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 1, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 2, 4, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 3, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 2, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 4, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 2, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 8, y + 3, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 3, 3, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 3, 3, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 3, 3, tanuki2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 3, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 3, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 8, y + 4, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 4, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 4, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 4, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 4, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 2, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 4, 2, belly);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 4, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 4, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 4, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 5, 8, outline); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 5, y + 5, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 5, tanuki1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 5, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 5, 5, belly);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 5, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLEDByColorIndex(x - 12, y + 6, tanuki2);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 6, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 6, 2, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 6, tanuki4);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 6, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 6, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 6, 6, belly);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 6, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 7, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 13, y + 7, 2, tanuki2);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 7, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x - 9, y + 7, 2, tanuki2);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 7, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 7, 3, tanuki2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 7, 6, belly);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 14, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 13, y + 8, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 8, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 8, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 8, tanuki5);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 8, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 8, 3, tanuki2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 8, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 1, y + 8, skintone3);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 8, 5, belly);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 8, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 14, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 12, y + 9, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 11, y + 9, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 9, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 8, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 9, tanuki5);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, tanuki2);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 9, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 9, 2, skintone3);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 9, 3, belly);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 9, 2, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, outline);
  ghostScreen.SetLightsByColorIndex(x - 13, y + 10, 5, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 8, y + 10, tanuki5);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 10, 4, tanuki1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 10, 4, skintone3);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 10, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 8, y + 11, tanuki5);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 11, 2, tanuki1);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 11, 4, tanuki1);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 9, y + 12, outline); // START ROW +12
  ghostScreen.SetLEDByColorIndex(x - 8, y + 12, goldshoes);
  ghostScreen.SetLEDByColorIndex(x - 7, y + 12, tanuki5);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, tanuki5);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 8, y + 13, 2, outline); // START ROW +13
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline);
}

void DrawMarioWarp05(int x, int y, byte outline = 0, byte skintone = 12, byte redsuit = 34)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x + 6, y - 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 2, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 11, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 10, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 1, y - 10, 6, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 10, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 2, y - 9, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 9, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 8, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 1, y - 6, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 6, 2, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 5, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 5, 2, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 0, 2, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 5, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 2, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 3, 3, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, redsuit);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, redsuit);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 5, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 5, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 5, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 7, 2, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 8, 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 9, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 9, 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 10, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 10, 3, redsuit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 11, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 11, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, redsuit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void DrawMarioWarp06(int x, int y, byte outline = 0, byte red3 = 27, byte skintone1 = 14, byte red1 = 25, byte red2 = 26, byte skintone2 = 15, byte skintone3 = 21, byte overalls2 = 23, byte overalls3 = 24, byte button = 16, byte goldshoes = 20, byte shoes1 = 19, byte shoes2 = 17, byte overalls1 = 22)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x + 6, y - 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 2, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, red3);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 11, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 10, outline); // START ROW -10
  ghostScreen.SetLEDByColorIndex(x - 1, y - 10, red1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 3, red2);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 10, 2, red3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 10, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 10, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 9, outline); // START ROW -9
  ghostScreen.SetLEDByColorIndex(x - 2, y - 9, red1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 2, red2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 9, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, red1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 8, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, red1);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLEDByColorIndex(x - 1, y - 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 6, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 6, red2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 6, red1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 5, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 5, red2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 5, red1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 3, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, red1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, red1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, red1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 0, red2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 0, red1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, red2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, red1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 4, y + 2, red1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 2, red2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 2, 2, red3);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, red2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, red2);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 2, red3);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLEDByColorIndex(x - 5, y + 3, red1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, red2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 3, red3);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 3, red1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, red2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 3, red3);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, red1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 4, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 4, red1);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 4, 2, red2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, red1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 2, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 5, overalls3);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 5, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, button);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, overalls3);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 6, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 7, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, button);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 7, overalls3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, goldshoes);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 7, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, shoes2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 8, 4, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, goldshoes);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 8, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 8, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 9, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 9, 3, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 9, 3, overalls1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, shoes1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 9, 2, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 5, y + 10, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 10, shoes1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 4, overalls1);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 10, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 10, shoes1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 10, 2, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 5, y + 11, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 11, shoes1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 11, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 11, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 11, shoes2);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLEDByColorIndex(x - 5, y + 12, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 12, shoes1);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void DrawMarioWarp07(int x, int y, byte outline = 34, byte skintone = 12, byte suit = 35)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x + 6, y - 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 2, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 11, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 10, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x - 1, y - 10, 6, suit);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 10, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 9, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 2, y - 9, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 9, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 8, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, suit);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 1, y - 6, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 6, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 5, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 5, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x - 5, y - 3, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 3, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, suit);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 0, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 5, suit);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 2, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 3, suit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 3, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, suit);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 5, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 5, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 5, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 7, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 8, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 9, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 9, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 10, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 10, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 11, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 11, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void DrawMarioWarp08(int x, int y, byte outline = 0, byte hat3 = 16, byte skintone1 = 14, byte hat1 = 39, byte hat2 = 40, byte skintone2 = 15, byte skintone3 = 21, byte overalls2 = 37, byte overalls3 = 38, byte goldshoes = 20, byte shoes1 = 19, byte shoes2 = 17, byte overalls1 = 36)
{
  ghostScreen.SetLightsByColorIndex(x + 1, y - 12, 4, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x + 6, y - 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 2, outline); // START ROW -11
  ghostScreen.SetLightsByColorIndex(x + 1, y - 11, 3, hat3);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 11, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 11, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 10, outline); // START ROW -10
  ghostScreen.SetLEDByColorIndex(x - 1, y - 10, hat1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 3, hat2);
  ghostScreen.SetLightsByColorIndex(x + 3, y - 10, 2, hat3);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 10, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 10, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 9, outline); // START ROW -9
  ghostScreen.SetLEDByColorIndex(x - 2, y - 9, hat1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 9, 2, hat2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 9, 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 9, 2, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 3, hat1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 8, 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 8, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 8, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 7, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 3, y - 7, hat1);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 7, 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 7, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y - 6, 4, outline); // START ROW -6
  ghostScreen.SetLEDByColorIndex(x - 1, y - 6, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 6, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 6, hat2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 6, hat1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 5, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 5, hat2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 5, hat1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x - 5, y - 4, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 3, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, hat1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, hat1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, hat1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 0, hat2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 0, hat1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, hat2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, hat1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 4, y + 2, hat1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 2, hat2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 2, 2, hat3);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, hat2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, hat2);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 2, hat3);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLEDByColorIndex(x - 5, y + 3, hat1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, hat2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 3, hat3);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 3, hat1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, hat2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 3, hat3);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, hat1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 4, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 4, hat1);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 4, 2, hat2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, hat1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 2, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 5, overalls3);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 5, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, hat3);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, overalls3);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 6, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 7, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, hat3);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 7, overalls3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, goldshoes);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 7, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, shoes2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 8, 4, overalls2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, goldshoes);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 8, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 8, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 9, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 9, 3, overalls2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 9, 3, overalls1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, shoes1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 9, 2, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 5, y + 10, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 10, shoes1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 4, overalls1);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 10, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 10, shoes1);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 10, 2, shoes2);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 5, y + 11, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 11, shoes1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 11, overalls1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 11, shoes1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 11, shoes2);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLEDByColorIndex(x - 5, y + 12, shoes2);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 12, shoes1);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void DrawMarioWarp09(int x, int y, byte outline = 34, byte skintone = 35, byte suit = 7)
{
  ghostScreen.SetLightsByColorIndex(x - 1, y - 13, 5, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 6, y - 13, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y - 12, 7, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x + 6, y - 12, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 11, outline); // START ROW -11
  ghostScreen.SetLEDByColorIndex(x - 2, y - 11, suit);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 11, 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 11, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 10, 3, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 7, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 10, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 9, 2, outline); // START ROW -9
  ghostScreen.SetLightsByColorIndex(x - 2, y - 9, 9, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 9, skintone);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLightsByColorIndex(x - 3, y - 8, 4, suit);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 8, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 8, suit);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 8, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 7, 2, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 2, y - 7, suit);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 7, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 7, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 7, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 6, outline); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 4, y - 6, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 6, 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 6, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, suit); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 5, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 5, 2, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 5, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x - 5, y - 4, suit);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 4, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 4, 7, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, suit);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 3, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, skintone);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x - 4, y - 2, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 4, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, suit);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 0, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x - 4, y + 2, 5, suit);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 2, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x - 5, y + 3, 3, suit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 3, 3, suit);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, suit);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 4, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 4, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, suit);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 5, 5, skintone);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 5, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 5, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 5, 2, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 5, skintone);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, skintone);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, skintone);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 7, 2, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 8, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 8, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 9, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 9, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLightsByColorIndex(x - 5, y + 10, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 10, 9, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 10, 3, suit);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLightsByColorIndex(x - 5, y + 11, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 11, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 11, 2, suit);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLightsByColorIndex(x - 5, y + 12, 2, suit);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void DrawMarioWarp10(int x, int y, byte outline = 0, byte hardhat1 = 41, byte hardhat2 = 42, byte hardhat3 = 43, byte skintone1 = 15, byte skintone2 = 14, byte skintone3 = 21, byte yellowhat2 = 44, byte yellowhat1 = 45, byte brownsuit1 = 46, byte brownsuit2 = 47, byte button = 16, byte brownsuit3 = 19)
{
  ghostScreen.SetLightsByColorIndex(x - 1, y - 13, 5, outline); // START ROW -13
  ghostScreen.SetLightsByColorIndex(x + 6, y - 13, 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 12, outline); // START ROW -12
  ghostScreen.SetLightsByColorIndex(x - 1, y - 12, 2, hardhat1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 12, hardhat2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 12, hardhat3);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 12, hardhat1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 12, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 12, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 12, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 12, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 12, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 11, outline); // START ROW -11
  ghostScreen.SetLEDByColorIndex(x - 2, y - 11, hardhat1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 11, hardhat2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 11, 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 11, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 11, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 11, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y - 10, 3, outline); // START ROW -10
  ghostScreen.SetLightsByColorIndex(x + 0, y - 10, 7, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 10, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 10, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 9, 2, outline); // START ROW -9
  ghostScreen.SetLEDByColorIndex(x - 2, y - 9, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 9, yellowhat2);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 9, 6, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 9, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 9, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 8, outline); // START ROW -8
  ghostScreen.SetLEDByColorIndex(x - 3, y - 8, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 8, yellowhat2);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 8, 2, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 8, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 8, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x + 7, y - 8, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 7, 2, outline); // START ROW -7
  ghostScreen.SetLEDByColorIndex(x - 2, y - 7, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 7, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 7, 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 7, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 7, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 6, outline); // START ROW -6
  ghostScreen.SetLEDByColorIndex(x - 4, y - 6, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 6, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 1, y - 6, 2, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 6, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 6, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 6, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 6, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 5, outline); // START ROW -5
  ghostScreen.SetLEDByColorIndex(x - 5, y - 5, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 5, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 5, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 4, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y - 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 6, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 5, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 5, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 4, outline); // START ROW -4
  ghostScreen.SetLEDByColorIndex(x - 5, y - 4, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 4, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 4, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 4, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 1, y - 4, 3, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 4, 3, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 4, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y - 3, outline); // START ROW -3
  ghostScreen.SetLEDByColorIndex(x - 5, y - 3, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 4, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 3, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 3, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 0, y - 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y - 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 3, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 3, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 3, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 9, y - 3, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y - 2, outline); // START ROW -2
  ghostScreen.SetLEDByColorIndex(x - 4, y - 2, yellowhat2);
  ghostScreen.SetLEDByColorIndex(x - 3, y - 2, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x - 2, y - 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 1, y - 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 2, 4, outline);
  ghostScreen.SetLightsByColorIndex(x + 4, y - 2, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 6, y - 2, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y - 1, 2, outline); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x - 2, y - 1, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x + 0, y - 1, 2, skintone2);
  ghostScreen.SetLightsByColorIndex(x + 2, y - 1, 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y - 1, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 8, y - 1, outline);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 0, 3, outline); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 0, y + 0, 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 0, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 0, 2, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 0, outline);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 1, outline); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x - 3, y + 1, 3, brownsuit2);
  ghostScreen.SetLightsByColorIndex(x + 0, y + 1, 6, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 1, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 1, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 2, outline); // START ROW +2
  ghostScreen.SetLEDByColorIndex(x - 4, y + 2, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 2, brownsuit2);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 2, 2, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x + 0, y + 2, brownsuit2);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 2, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 2, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 3, outline); // START ROW +3
  ghostScreen.SetLEDByColorIndex(x - 5, y + 3, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 3, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 3, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 3, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 3, hardhat2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 3, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 3, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 3, yellowhat1);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 3, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 4, outline); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x - 5, y + 4, 2, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 4, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 4, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 4, hardhat2);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 4, y + 4, brownsuit1);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 4, 2, brownsuit2);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 4, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 5, outline); // START ROW +5
  ghostScreen.SetLEDByColorIndex(x - 5, y + 5, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 5, skintone1);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 5, skintone2);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 5, 2, skintone3);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 5, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 5, outline);
  ghostScreen.SetLEDByColorIndex(x + 3, y + 5, hardhat3);
  ghostScreen.SetLightsByColorIndex(x + 4, y + 5, 5, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 6, 2, outline); // START ROW +6
  ghostScreen.SetLightsByColorIndex(x - 3, y + 6, 2, skintone1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 6, 3, skintone2);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 6, 2, button);
  ghostScreen.SetLightsByColorIndex(x + 5, y + 6, 2, hardhat3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 6, button);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 6, outline);
  ghostScreen.SetLightsByColorIndex(x - 4, y + 7, 2, outline); // START ROW +7
  ghostScreen.SetLightsByColorIndex(x - 2, y + 7, 3, skintone1);
  ghostScreen.SetLEDByColorIndex(x + 1, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 2, y + 7, hardhat2);
  ghostScreen.SetLightsByColorIndex(x + 3, y + 7, 2, button);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 7, hardhat3);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 7, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 7, brownsuit3);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 7, outline);
  ghostScreen.SetLEDByColorIndex(x - 5, y + 8, outline); // START ROW +8
  ghostScreen.SetLightsByColorIndex(x - 4, y + 8, 2, brownsuit1);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 8, 3, outline);
  ghostScreen.SetLightsByColorIndex(x + 1, y + 8, 4, hardhat2);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 8, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 8, yellowhat1);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 8, brownsuit3);
  ghostScreen.SetLEDByColorIndex(x + 8, y + 8, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 8, outline);
  ghostScreen.SetLightsByColorIndex(x - 6, y + 9, 2, outline); // START ROW +9
  ghostScreen.SetLEDByColorIndex(x - 4, y + 9, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 9, hardhat1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 9, 3, hardhat2);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 9, 3, hardhat1);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 9, brownsuit3);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 9, 2, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 9, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 10, outline); // START ROW +10
  ghostScreen.SetLEDByColorIndex(x - 5, y + 10, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 10, brownsuit3);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 10, outline);
  ghostScreen.SetLightsByColorIndex(x - 2, y + 10, 4, hardhat1);
  ghostScreen.SetLightsByColorIndex(x + 2, y + 10, 4, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 10, brownsuit3);
  ghostScreen.SetLightsByColorIndex(x + 7, y + 10, 2, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x + 9, y + 10, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 11, outline); // START ROW +11
  ghostScreen.SetLEDByColorIndex(x - 5, y + 11, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 11, brownsuit3);
  ghostScreen.SetLEDByColorIndex(x - 3, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x - 2, y + 11, hardhat1);
  ghostScreen.SetLightsByColorIndex(x - 1, y + 11, 3, outline);
  ghostScreen.SetLEDByColorIndex(x + 5, y + 11, outline);
  ghostScreen.SetLEDByColorIndex(x + 6, y + 11, brownsuit3);
  ghostScreen.SetLEDByColorIndex(x + 7, y + 11, brownsuit1);
  ghostScreen.SetLightsByColorIndex(x + 8, y + 11, 2, outline);
  ghostScreen.SetLEDByColorIndex(x - 6, y + 12, outline); // START ROW +12
  ghostScreen.SetLEDByColorIndex(x - 5, y + 12, brownsuit1);
  ghostScreen.SetLEDByColorIndex(x - 4, y + 12, brownsuit3);
  ghostScreen.SetLightsByColorIndex(x - 3, y + 12, 2, outline);
  ghostScreen.SetLightsByColorIndex(x + 6, y + 12, 3, outline);
  ghostScreen.SetLightsByColorIndex(x - 5, y + 13, 2, outline); // START ROW +13
}

void MarioWarpThrough()
{
  int frame = GetFrame(56, 200);
  int frameIndex = (frame % 40) / 4;
  static int framePrint = -1;

  ghostScreen.SetScreen(CRGB(GetColor(8, 0), GetColor(8, 1), GetColor(8, 2)));
  
  if      (frameIndex == 0) DrawMarioWarp09(frame - 14, 7);
  else if (frameIndex == 1) DrawMarioWarp10(frame - 14, 7);
  else if (frameIndex == 2) DrawMarioWarp01(frame - 14, 7);
  else if (frameIndex == 3) DrawMarioWarp02(frame - 14, 7);
  else if (frameIndex == 4) DrawMarioWarp07(frame - 14, 7);
  else if (frameIndex == 5) DrawMarioWarp08(frame - 14, 7);
  else if (frameIndex == 6) DrawMarioWarp05(frame - 14, 7);
  else if (frameIndex == 7) DrawMarioWarp06(frame - 14, 7);
  else if (frameIndex == 8) DrawMarioWarp03(frame - 14, 7);
  else                      DrawMarioWarp04(frame - 14, 7);
}

void DetermineNextTetrisShape(byte& nextShape, byte& nextColor)
{
  RenderTetrisShape(nextShape, 0, 0, 22, 6);
  nextShape = random(4);
  nextColor = GetRandomVibrantColorIndex();
}

void IterateCurrentTetrisShape(byte& currentShape, byte& currentColor, byte &nextShape, byte& nextColor)
{
  currentShape = nextShape;
  currentColor = nextColor;
  DetermineNextTetrisShape(nextShape, nextColor);
}

void RenderTetrisShape(byte shapeIndex, byte color, byte facing, byte xPos, byte yPos)
{
  switch (shapeIndex)
  {
    case 0: //  SQUARE
      ghostScreen.SetLightsByColorIndex(xPos, yPos, 2, color); ghostScreen.SetLightsByColorIndex(xPos, yPos + 1, 2, color);
      break;
    case 1: //  LINE
      switch (facing)
      {
        case 0: //  000 Degrees
        case 2: //  180 Degrees
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 0, 4, color);
          break;
        case 1: //  090 Degrees
        case 3: //  270 Degrees
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos - 1, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 0, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 1, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 2, color);
          break;
      }
      break;
    case 2: //  L-BLOCK
      switch (facing)
      {
        case 0:
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 0, 3, color);
          ghostScreen.SetLEDByColorIndex(xPos - 1, yPos + 1, color);
          break;
        case 1:
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos - 1, 2, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 0, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 1, color);
          break;
        case 2:
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 0, 3, color);
          ghostScreen.SetLEDByColorIndex(xPos + 1, yPos - 1, color);
          break;
        case 3:
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos - 1, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 0, color);
          ghostScreen.SetLightsByColorIndex(xPos + 0, yPos + 1, 2, color);
          break;
      }
      break;
    case 3: //  REVERSE L-BLOCK
      switch (facing)
      {
        case 0:
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 0, 3, color);
          ghostScreen.SetLEDByColorIndex(xPos + 1, yPos + 1, color);
          break;
        case 1:
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos - 1, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 0, color);
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 1, 2, color);
          break;
        case 2:
          ghostScreen.SetLEDByColorIndex(xPos - 1, yPos - 1, color);
          ghostScreen.SetLightsByColorIndex(xPos - 1, yPos + 0, 3, color);
          break;
        case 3:
          ghostScreen.SetLightsByColorIndex(xPos + 0, yPos - 1, 2, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 0, color);
          ghostScreen.SetLEDByColorIndex(xPos + 0, yPos + 1, color);
          break;
      }
      break;
  }
}

bool CheckTetrisSpace(byte xPos, byte yPos, byte shape, byte facing)
{
  switch (shape)
  {
    case 0: //  SQUARE
      return (ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 1));
      break;
    case 1: //  LINE
      switch (facing)
      {
        case 0: //  000 Degrees
        case 2: //  180 Degrees
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 2, yPos + 0));
          break;
        case 1: //  090 Degrees
        case 3: //  270 Degrees
          return (ghostScreen.IsPixelBlack(xPos + 0, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 2));
          break;
      }
      break;
    case 2: //  L-BLOCK
      switch (facing)
      {
        case 0:
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos - 1, yPos + 1));
          break;
        case 1:
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1));
          break;
        case 2:
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos - 1));
          break;
        case 3:
          return (ghostScreen.IsPixelBlack(xPos + 0, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 1));
          break;
      }
      break;
    case 3: //  REVERSE L-BLOCK
      switch (facing)
      {
        case 0:
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 1));
          break;
        case 1:
          return (ghostScreen.IsPixelBlack(xPos + 0, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos - 1, yPos + 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1));
          break;
        case 2:
          return (ghostScreen.IsPixelBlack(xPos - 1, yPos - 1) && ghostScreen.IsPixelBlack(xPos - 1, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 1, yPos + 0));
          break;
        case 3:
          return (ghostScreen.IsPixelBlack(xPos + 0, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 1, yPos - 1) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 0) && ghostScreen.IsPixelBlack(xPos + 0, yPos + 1));
          break;
      }
      break;
  }
  
  return true;
}

void DropTetrisRow(byte rowIndex)
{
  for (int i = 0; i < rowIndex; ++i)
    for (int j = 0; j < TETRIS_BOARD_WIDTH; ++j)
      ghostScreen.SetLEDByColorRef(TETRIS_BOARD_START_X + j, TETRIS_BOARD_START_Y + rowIndex - i, ghostScreen.GetPixel(TETRIS_BOARD_START_X + j, TETRIS_BOARD_START_Y + rowIndex - i - 1));
}

void CheckForTetrisRowCleared()
{
  for (int i = 0; i < TETRIS_BOARD_HEIGHT; ++i)
  {
    for (int j = 0; j < TETRIS_BOARD_WIDTH; ++j)
    {
      if (ghostScreen.IsPixelBlack(TETRIS_BOARD_START_X + j, TETRIS_BOARD_START_Y + i)) break;
      if (j == TETRIS_BOARD_WIDTH - 1)
      {
        DropTetrisRow(i);
      }
    }
  }
}

void ShowTetrisFailureAnimation()
{
  for (int i = 0; i < TETRIS_BOARD_HEIGHT; ++i)
    for (int j = 0; j < TETRIS_BOARD_WIDTH; ++j)
      if (!ghostScreen.IsPixelBlack(TETRIS_BOARD_START_X + j, TETRIS_BOARD_START_Y + i))
        ghostScreen.SetLEDByColorIndex(TETRIS_BOARD_START_X + j, TETRIS_BOARD_START_Y + i, 7);

  FastLED.show();
  delay(1000);
  UpdateMillisOffset();
  ResetTetris();
}

void Tetris()
{
  static byte currentShape = 255;
  static byte currentColor = 0;
  static byte currentFacing = 0;
  
  static byte nextShape = 255;
  static byte nextColor = 0;
  
  static byte xPos = 4;
  static byte yPos = 1;

  if (nextShape == 255) DetermineNextTetrisShape(nextShape, nextColor);  
  if (currentShape == 255)
  {
    currentFacing = 0;
    Serial.println("Iterating to new tetris shape...");
    IterateCurrentTetrisShape(currentShape, currentColor, nextShape, nextColor);
    xPos = 4;
    yPos = 1;
  }

  //RenderTetrisShape(nextShape, nextColor, 0, 22, 6);
  RenderTetrisShape(currentShape, currentColor, currentFacing, TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos);

  if (IsNextFrameReady())
  {
    Serial.print("Rendering current tetris shape: ");
    Serial.print(currentShape);
    Serial.print(", ");
    Serial.print(currentColor);
    Serial.print(", ");
    Serial.print(currentFacing);
    Serial.print(" (");
    Serial.print(TETRIS_BOARD_START_X + xPos);
    Serial.print(", ");
    Serial.print(TETRIS_BOARD_START_Y + yPos);
    Serial.println(")");
    RenderTetrisShape(currentShape, 0, currentFacing, TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos);

    /*
    //  Move left or right if the controller is polled with LEFT or RIGHT input
    if (nesController.CheckButton(NES_LEFT_BUTTON))
    {
      if (CheckTetrisSpace(TETRIS_BOARD_START_X + xPos - 1, TETRIS_BOARD_START_Y + yPos, currentShape, currentFacing)) xPos -= 1;
    }
    
    if (nesController.CheckButton(NES_RIGHT_BUTTON))
    {
      if (CheckTetrisSpace(TETRIS_BOARD_START_X + xPos + 1, TETRIS_BOARD_START_Y + yPos, currentShape, currentFacing)) xPos += 1;
    }
    
    if (nesController.CheckButton(NES_UP_BUTTON))
    {
      int newFacing = currentFacing + 1;
      if (newFacing == 4) newFacing = 0;
      if (CheckTetrisSpace(TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos + 1, currentShape, newFacing)) currentFacing = newFacing;
    }
    
    if (nesController.CheckButton(NES_DOWN_BUTTON))
    {
      if (CheckTetrisSpace(TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos + 1, currentShape, currentFacing)) yPos += 2;
    }
    */

    //  Move down if possible. If not, leave the shape and move on the next shape
    if (CheckTetrisSpace(TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos + 1, currentShape, currentFacing)) {
      yPos += 1;
      Serial.println("Moving tetris piece down one space...");
    }
    else
    {
      RenderTetrisShape(currentShape, currentColor, currentFacing, TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos);
      CheckForTetrisRowCleared();

      IterateCurrentTetrisShape(currentShape, currentColor, nextShape, nextColor);
      xPos = 4;
      yPos = 1;
      currentFacing = 0;
      if (!CheckTetrisSpace(TETRIS_BOARD_START_X + xPos, TETRIS_BOARD_START_Y + yPos, currentShape, currentFacing)) ShowTetrisFailureAnimation();
    }
    nextFrameMillis += 500;
  }
}

inline void IteratePatternIndex(byte overrideIndex = 255)
{
    ghostScreen.ClearScreen();

    if (overrideIndex != 255) patternIndex = overrideIndex;
    else ++patternIndex;

    UpdateMillisOffset();
    if (patternIndex == 0) ResetTetris();
}

void setup()
{
  //  Setup the LED strips up for both inner ghost and outer ring
  if (GHOST_CART_HARDWARE) {
    FastLED.addLeds<WS2801, GHOST_SCREEN_DATA_PIN, GHOST_SCREEN_CLOCK_PIN, RGB>(ghostScreen.LEDs, ghostScreen.LED_COUNT).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<WS2801, OUTER_RING_DATA_PIN, OUTER_RING_CLOCK_PIN, RGB>(outerRing.LEDs, outerRing.LED_COUNT).setCorrection( TypicalLEDStrip );
  }
  else {
    FastLED.addLeds<WS2812B, GHOST_SCREEN_DATA_PIN, GRB>(ghostScreen.LEDs, ghostScreen.LED_COUNT).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<WS2812B, OUTER_RING_DATA_PIN, GRB>(outerRing.LEDs, outerRing.LED_COUNT).setCorrection( TypicalLEDStrip );
  }     

  //  Set all LED brightness and clear all strips
  FastLED.setBrightness(BRIGHTNESS);
  ghostScreen.ClearScreen();
  ClearStrip(outerRing.LEDs, outerRing.LED_COUNT);
  FastLED.show();
  
  //  Seed the random number generator
  randomSeed(analogRead(0));
  
  //  Set the "Iterate" button timer to the current time
  ghostScreen.ButtonIterationTimer = millis();
  IteratePatternIndex(0);

  SerialProgramInit();

  ghostScreen.Initialize(true);
}

void loop()
{
  nesController.ReadController();
  
  //  Determine if the current time is past the button delay timer
  unsigned long currentMillis = millis();
  if ((currentMillis > ghostScreen.ButtonIterationTimer) && (nesController.CheckButton(NES_A_BUTTON))) {
    Serial.println("NES Controller [A] Button pressed, iterating to next pattern on Ghost Screen...");
    ghostScreen.ButtonIterationTimer = currentMillis + ghostScreen.BUTTON_DELAY;
    IteratePatternIndex();
  }

  switch (patternIndex)
  {
    case 0:   Serial.println("RainbowFlow1()");                       RainbowFlow1(ghostScreen.LEDs, ghostScreen.LED_COUNT);                      break;
    case 1:   Serial.println("RainbowFlow2()");                       RainbowFlow2(10, false);                                                    break;
    case 2:   Serial.println("ColorFire()");                          ColorFire(ghostScreen.LEDs, ghostScreen.LED_COUNT);                         break;
    case 3:   Serial.println("GlowFlow()");                           GlowFlow(ghostScreen.LEDs, ghostScreen.LED_COUNT, 10, 100);                 break;
    case 4:   Serial.println("PacManChompDanceThrough()");            ghostScreen.ClearScreen(); PacManChompDanceThrough();                       break;
    case 5:   Serial.println("PacManChompDanceThroughPlusGhost()");   ghostScreen.ClearScreen(); PacManChompDanceThroughPlusGhost();              break;
    case 6:   Serial.println("MsPacManChompDanceThrough()");          ghostScreen.ClearScreen(); MsPacManChompDanceThrough();                     break;
    case 7:   Serial.println("SpaceInvaderDanceThrough()");           ghostScreen.ClearScreen(); SpaceInvaderDanceThrough();                      break;
    case 8:   Serial.println("MegaManRunThrough()");                  ghostScreen.ClearScreen(); MegaManRunThrough();                             break;
    case 9:   Serial.println("MarioWarpThrough()");                   ghostScreen.ClearScreen(); MarioWarpThrough();                              break;
    case 10:  Serial.println("LetterMoveThrough_BRC()");              ghostScreen.ClearScreen(); LetterMoveThrough_BRC();                         break;
    //case 11:  /*Serial.println("Tetris()");*/                         ghostScreen.ClearScreen(); Tetris();                                        break;
    default:  patternIndex = 0;                                       break;
  }
  FastLED.show();

  outerRing.Pacman();
}