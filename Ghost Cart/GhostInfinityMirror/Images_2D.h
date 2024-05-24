#pragma once

#include "LED_Screen.h"

///////////////
// 2D Images
///////////////
void Image2D_PacManChomp01(LED_Screen* screen, int x, int y, CRGB& color)
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
 
  screen->SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  screen->SetLightsByColorRef(x - 4, y - 5, 9, color); //  START ROW -5
  screen->SetLightsByColorRef(x - 5, y - 4, 11, color); //  START ROW -4
  screen->SetLightsByColorRef(x - 5, y - 3, 11, color); //  START ROW -3
  screen->SetLightsByColorRef(x - 6, y - 2, 13, color); //  START ROW -2
  screen->SetLightsByColorRef(x - 6, y - 1, 13, color); //  START ROW -1
  screen->SetLightsByColorRef(x - 6, y + 0, 13, color); //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 13, color); //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 13, color); //  START ROW +2
  screen->SetLightsByColorRef(x - 5, y + 3, 11, color); //  START ROW +3
  screen->SetLightsByColorRef(x - 5, y + 4, 11, color); //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 5, 9, color); //  START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void Image2D_PacManChomp02(LED_Screen* screen, int x, int y, CRGB& color)
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
 
  screen->SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  screen->SetLightsByColorRef(x - 4, y - 5, 9, color); //  START ROW -5
  screen->SetLightsByColorRef(x - 5, y - 4, 11, color); //  START ROW -4
  screen->SetLightsByColorRef(x - 5, y - 3, 11, color); //  START ROW -3
  screen->SetLightsByColorRef(x - 6, y - 2, 10, color); //  START ROW -2
  screen->SetLightsByColorRef(x - 6, y - 1, 7, color); //  START ROW -1
  screen->SetLightsByColorRef(x - 6, y + 0, 4, color); //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 7, color); //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 10, color); //  START ROW +2
  screen->SetLightsByColorRef(x - 5, y + 3, 11, color); //  START ROW +3
  screen->SetLightsByColorRef(x - 5, y + 4, 11, color); //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 5, 9, color); //  START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void Image2D_PacManChomp03(LED_Screen* screen, int x, int y, CRGB& color)
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
 
  screen->SetLightsByColorRef(x - 2, y - 6, 5, color); //  START ROW -6
  screen->SetLightsByColorRef(x - 4, y - 5, 7, color); //  START ROW -5
  screen->SetLightsByColorRef(x - 5, y - 4, 7, color); //  START ROW -4
  screen->SetLightsByColorRef(x - 5, y - 3, 6, color); //  START ROW -3
  screen->SetLightsByColorRef(x - 6, y - 2, 6, color); //  START ROW -2
  screen->SetLightsByColorRef(x - 6, y - 1, 5, color); //  START ROW -1
  screen->SetLightsByColorRef(x - 6, y + 0, 4, color); //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 5, color); //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 6, color); //  START ROW +2
  screen->SetLightsByColorRef(x - 5, y + 3, 6, color); //  START ROW +3
  screen->SetLightsByColorRef(x - 5, y + 4, 7, color); //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 5, 7, color); //  START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color); //  START ROW +6
}

void Image2D_PacManGhostWalk01(LED_Screen* screen, int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall)
{
  screen->SetLightsByColorRef(x - 2, y - 7, 4, bodyColor); // START ROW -7
  screen->SetLightsByColorRef(x - 4, y - 6, 8, bodyColor); // START ROW -6
  screen->SetLightsByColorRef(x - 5, y - 5, 10, bodyColor); // START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 3, bodyColor); // START ROW -4
  screen->SetLightsByColorRef(x - 3, y - 4, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 1, y - 4, 4, bodyColor);
  screen->SetLightsByColorRef(x + 3, y - 4, 2, eyeWhite);
  screen->SetLEDByColorRef(x + 5, y - 4, bodyColor);
  screen->SetLightsByColorRef(x - 6, y - 3, 2, bodyColor); // START ROW -3
  screen->SetLightsByColorRef(x - 4, y - 3, 4, eyeWhite);
  screen->SetLightsByColorRef(x + 0, y - 3, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 3, 4, eyeWhite);
  screen->SetLightsByColorRef(x - 6, y - 2, 2, bodyColor); // START ROW -2
  screen->SetLightsByColorRef(x - 4, y - 2, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 2, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x + 0, y - 2, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 2, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x - 7, y - 1, 3, bodyColor); // START ROW -1
  screen->SetLightsByColorRef(x - 4, y - 1, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 2, y - 1, 2, eyeBall);
  screen->SetLightsByColorRef(x + 0, y - 1, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 1, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 1, 2, eyeBall);
  screen->SetLEDByColorRef(x + 6, y - 1, bodyColor);
  screen->SetLightsByColorRef(x - 7, y + 0, 4, bodyColor); // START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 0, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 1, y + 0, 4, bodyColor);
  screen->SetLightsByColorRef(x + 3, y + 0, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 5, y + 0, 2, bodyColor);
  screen->SetLightsByColorRef(x - 7, y + 1, 14, bodyColor); // START ROW +1
  screen->SetLightsByColorRef(x - 7, y + 2, 14, bodyColor); // START ROW +2
  screen->SetLightsByColorRef(x - 7, y + 3, 14, bodyColor); // START ROW +3
  screen->SetLightsByColorRef(x - 7, y + 4, 14, bodyColor); // START ROW +4
  screen->SetLightsByColorRef(x - 7, y + 5, 4, bodyColor); // START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 5, 4, bodyColor);
  screen->SetLightsByColorRef(x + 3, y + 5, 4, bodyColor);
  screen->SetLightsByColorRef(x - 6, y + 6, 2, bodyColor); // START ROW +6
  screen->SetLightsByColorRef(x - 1, y + 6, 2, bodyColor);
  screen->SetLightsByColorRef(x + 4, y + 6, 2, bodyColor);
}

void Image2D_PacManGhostWalk02(LED_Screen* screen, int x, int y, CRGB& bodyColor, CRGB& eyeWhite, CRGB& eyeBall)
{
  screen->SetLightsByColorRef(x - 2, y - 7, 4, bodyColor); // START ROW -7
  screen->SetLightsByColorRef(x - 4, y - 6, 8, bodyColor); // START ROW -6
  screen->SetLightsByColorRef(x - 5, y - 5, 10, bodyColor); // START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 3, bodyColor); // START ROW -4
  screen->SetLightsByColorRef(x - 3, y - 4, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 1, y - 4, 4, bodyColor);
  screen->SetLightsByColorRef(x + 3, y - 4, 2, eyeWhite);
  screen->SetLEDByColorRef(x + 5, y - 4, bodyColor);
  screen->SetLightsByColorRef(x - 6, y - 3, 2, bodyColor); // START ROW -3
  screen->SetLightsByColorRef(x - 4, y - 3, 4, eyeWhite);
  screen->SetLightsByColorRef(x + 0, y - 3, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 3, 4, eyeWhite);
  screen->SetLightsByColorRef(x - 6, y - 2, 2, bodyColor); // START ROW -2
  screen->SetLightsByColorRef(x - 4, y - 2, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 2, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x + 0, y - 2, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 2, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x - 7, y - 1, 3, bodyColor); // START ROW -1
  screen->SetLightsByColorRef(x - 4, y - 1, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 2, y - 1, 2, eyeBall);
  screen->SetLightsByColorRef(x + 0, y - 1, 2, bodyColor);
  screen->SetLightsByColorRef(x + 2, y - 1, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 1, 2, eyeBall);
  screen->SetLEDByColorRef(x + 6, y - 1, bodyColor);
  screen->SetLightsByColorRef(x - 7, y + 0, 4, bodyColor); // START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 0, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 1, y + 0, 4, bodyColor);
  screen->SetLightsByColorRef(x + 3, y + 0, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 5, y + 0, 2, bodyColor);
  screen->SetLightsByColorRef(x - 7, y + 1, 14, bodyColor); // START ROW +1
  screen->SetLightsByColorRef(x - 7, y + 2, 14, bodyColor); // START ROW +2
  screen->SetLightsByColorRef(x - 7, y + 3, 14, bodyColor); // START ROW +3
  screen->SetLightsByColorRef(x - 7, y + 4, 14, bodyColor); // START ROW +4
  screen->SetLightsByColorRef(x - 7, y + 5, 2, bodyColor); // START ROW +5
  screen->SetLightsByColorRef(x - 4, y + 5, 3, bodyColor);
  screen->SetLightsByColorRef(x + 1, y + 5, 3, bodyColor);
  screen->SetLightsByColorRef(x + 5, y + 5, 2, bodyColor);
  screen->SetLEDByColorRef(x - 7, y + 6, bodyColor); // START ROW +6
  screen->SetLightsByColorRef(x - 3, y + 6, 2, bodyColor);
  screen->SetLightsByColorRef(x + 1, y + 6, 2, bodyColor);
  screen->SetLEDByColorRef(x + 6, y + 6, bodyColor);
}


void Image2D_MsPacManChomp01(LED_Screen* screen, int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
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

  screen->SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  screen->SetLightsByColorRef(x - 2, y - 6, 4, color1); //  START ROW -6 
  screen->SetLightsByColorRef(x + 2, y - 6, 3, color2);
  screen->SetLightsByColorRef(x - 4, y - 5, 6, color1); //  START ROW -5
  screen->SetLightsByColorRef(x + 2, y - 5, 2, color2);
  screen->SetLEDByColorRef(x + 4, y - 5, color3);
  screen->SetLEDByColorRef(x + 5, y - 5, color2);
  screen->SetLightsByColorRef(x - 5, y - 4, 9, color1); //  START ROW -4
  screen->SetLEDByColorRef(x + 4, y - 4, color2);
  screen->SetLEDByColorRef(x + 5, y - 4, color3);
  screen->SetLightsByColorRef(x + 6, y - 4, 2, color2);
  screen->SetLightsByColorRef(x - 5, y - 3, 10, color1); //  START ROW -3
  screen->SetLightsByColorRef(x + 5, y - 3, 3, color2);
  screen->SetLightsByColorRef(x - 6, y - 2, 5, color1); //  START ROW -2
  screen->SetLEDByColorRef(x + 4, y - 2, color1);
  screen->SetLightsByColorRef(x + 5, y - 2, 2, color2);
  screen->SetLEDByColorRef(x - 7, y - 1, color2); //  START ROW -1
  screen->SetLightsByColorRef(x - 6, y - 1, 13, color1);
  screen->SetLightsByColorRef(x - 7, y + 0, 2, color2); //  START ROW +0
  screen->SetLightsByColorRef(x - 5, y + 0, 12, color1);
  screen->SetLEDByColorRef(x - 7, y + 1, color2); //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 1, 13, color1);
  screen->SetLightsByColorRef(x - 6, y + 2, 9, color1); //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 3, color1);
  screen->SetLightsByColorRef(x - 5, y + 3, 11, color1); //  START ROW +3
  screen->SetLightsByColorRef(x - 5, y + 4, 11, color1); //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 5, 9, color1); //  START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color1); //  START ROW +6
}

void Image2D_MsPacManChomp02(LED_Screen* screen, int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
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

  screen->SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  screen->SetLightsByColorRef(x - 2, y - 6, 4, color2); //  START ROW -6 
  screen->SetLightsByColorRef(x + 2, y - 6, 3, color2);
  screen->SetLightsByColorRef(x - 4, y - 5, 4, color1); //  START ROW -5
  screen->SetLightsByColorRef(x + 2, y - 5, 2, color2);
  screen->SetLEDByColorRef(x + 4, y - 5, color3);
  screen->SetLEDByColorRef(x + 5, y - 5, color2);
  screen->SetLightsByColorRef(x - 5, y - 4, 9, color1); //  START ROW -4
  screen->SetLEDByColorRef(x + 4, y - 4, color2);
  screen->SetLEDByColorRef(x + 5, y - 4, color3);
  screen->SetLightsByColorRef(x + 6, y - 4, 2, color2);
  screen->SetLightsByColorRef(x - 5, y - 3, 2, color2); //  START ROW -3
  screen->SetLightsByColorRef(x - 3, y - 3, 3, color1);
  screen->SetLightsByColorRef(x + 2, y - 3, 3, color1);
  screen->SetLightsByColorRef(x + 5, y - 3, 3, color2);
  screen->SetLightsByColorRef(x - 1, y - 2, 2, color1); //  START ROW -2
  screen->SetLEDByColorRef(x + 1, y - 2, color3);
  screen->SetLightsByColorRef(x + 3, y - 2, 2, color1);
  screen->SetLightsByColorRef(x + 5, y - 2, 2, color2);
  screen->SetLightsByColorRef(x + 1, y - 1, 6, color1); //  START ROW -1
  screen->SetLightsByColorRef(x + 3, y + 0, 4, color1); //  START ROW +0
  screen->SetLightsByColorRef(x + 1, y + 1, 6, color1); //  START ROW +1
  screen->SetLightsByColorRef(x - 1, y + 2, 4, color1); //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 3, color1);
  screen->SetLightsByColorRef(x - 5, y + 3, 2, color2); //  START ROW +3
  screen->SetLightsByColorRef(x - 3, y + 3, 9, color1);
  screen->SetLightsByColorRef(x - 5, y + 4, 11, color1); //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 5, 9, color1); //  START ROW +5
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color1); //  START ROW +6
}

void Image2D_MsPacManChomp03(LED_Screen* screen, int x, int y, CRGB& color1, CRGB& color2, CRGB& color3)
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

  screen->SetLightsByColorRef(x + 3, y - 7, 2, color2); //  START ROW -7
  screen->SetLEDByColorRef(x - 3, y - 6, color2); //  START ROW -6 
  screen->SetLightsByColorRef(x - 2, y - 6, 4, color1);
  screen->SetLightsByColorRef(x + 2, y - 6, 3, color2);
  screen->SetLEDByColorRef(x - 2, y - 5, color2); //  START ROW -5
  screen->SetLightsByColorRef(x - 1, y - 5, 3, color1);
  screen->SetLightsByColorRef(x + 2, y - 5, 2, color2);
  screen->SetLEDByColorRef(x + 4, y - 5, color3);
  screen->SetLEDByColorRef(x + 5, y - 5, color2);
  screen->SetLightsByColorRef(x - 1, y - 4, 2, color1); //  START ROW -4
  screen->SetLightsByColorRef(x + 2, y - 4, 2, color1);
  screen->SetLEDByColorRef(x + 4, y - 4, color2);
  screen->SetLEDByColorRef(x + 5, y - 4, color3);
  screen->SetLightsByColorRef(x + 6, y - 4, 2, color2);
  screen->SetLEDByColorRef(x + 0, y - 3, color1); //  START ROW -3
  screen->SetLightsByColorRef(x + 3, y - 3, 2, color1);
  screen->SetLightsByColorRef(x + 5, y - 3, 3, color2);
  screen->SetLEDByColorRef(x + 1, y - 2, color1); //  START ROW -2
  screen->SetLEDByColorRef(x + 2, y - 2, color3);
  screen->SetLEDByColorRef(x + 4, y - 2, color1);
  screen->SetLightsByColorRef(x + 5, y - 2, 2, color2);
  screen->SetLightsByColorRef(x + 2, y - 1, 5, color1); //  START ROW -1
  screen->SetLightsByColorRef(x + 3, y + 0, 4, color1); //  START ROW +0
  screen->SetLightsByColorRef(x + 2, y + 1, 5, color1); //  START ROW +1
  screen->SetLightsByColorRef(x + 1, y + 2, 2, color1); //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 3, color1);
  screen->SetLightsByColorRef(x + 0, y + 3, 6, color1); //  START ROW +3
  screen->SetLightsByColorRef(x - 1, y + 4, 7, color1); //  START ROW +4
  screen->SetLEDByColorRef(x - 2, y + 5, color2); //  START ROW +5
  screen->SetLightsByColorRef(x - 1, y + 5, 6, color1);
  screen->SetLEDByColorRef(x - 3, y + 6, color2);  //  START ROW +6
  screen->SetLightsByColorRef(x - 2, y + 6, 5, color1);
}

void Image2D_SpaceInvader01(LED_Screen* screen, int x, int y, CRGB& color1, CRGB& color2)
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
 
  screen->SetLEDByColorRef(x - 3, y - 4, color1); // START ROW -4
  screen->SetLEDByColorRef(x + 3, y - 4, color1);
  screen->SetLEDByColorRef(x - 2, y - 3, color1); // START ROW -3
  screen->SetLEDByColorRef(x + 2, y - 3, color1);
  screen->SetLightsByColorRef(x - 3, y - 2, 7, color2); // START ROW -2
  screen->SetLightsByColorRef(x - 4, y - 1, 2, color2); //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 3, color2);
  screen->SetLightsByColorRef(x + 3, y - 1, 2, color2);
  screen->SetLightsByColorRef(x - 5, y, 11, color1); //  START ROW +0
  screen->SetLEDByColorRef(x - 5, y + 1, color1); //  START ROW +1
  screen->SetLightsByColorRef(x - 3, y + 1, 7, color1);
  screen->SetLEDByColorRef(x + 5, y + 1, color1);
  screen->SetLEDByColorRef(x - 5, y + 2, color1); //  START ROW +2
  screen->SetLEDByColorRef(x - 3, y + 2, color1);
  screen->SetLEDByColorRef(x + 3, y + 2, color1);
  screen->SetLEDByColorRef(x + 5, y + 2, color1);
  screen->SetLightsByColorRef(x - 2, y + 3, 2, color1); //  START ROW +3
  screen->SetLightsByColorRef(x + 1, y + 3, 2, color1);
}

void Image2D_SpaceInvader02(LED_Screen* screen, int x, int y, CRGB& color1, CRGB& color2)
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
 
  screen->SetLEDByColorRef(x - 3, y - 4, color1); // START ROW -4
  screen->SetLEDByColorRef(x + 3, y - 4, color1);
  screen->SetLEDByColorRef(x - 2, y - 3, color1); // START ROW -3
  screen->SetLEDByColorRef(x + 2, y - 3, color1);
  screen->SetLEDByColorRef(x - 5, y - 2, color2); // START ROW -2
  screen->SetLightsByColorRef(x - 3, y - 2, 7, color2);
  screen->SetLEDByColorRef(x + 5, y - 2, color2);
  screen->SetLightsByColorRef(x - 5, y - 1, 3, color2); //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 3, color2);
  screen->SetLightsByColorRef(x + 3, y - 1, 3, color2);
  screen->SetLightsByColorRef(x - 5, y, 11, color1); //  START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 1, 7, color1); //  START ROW +1
  screen->SetLEDByColorRef(x - 3, y + 2, color1); //  START ROW +2
  screen->SetLEDByColorRef(x + 3, y + 2, color1);
  screen->SetLEDByColorRef(x - 4, y + 3, color1); //  START ROW +3
  screen->SetLEDByColorRef(x + 4, y + 3, color1);
}


void Image2D_Letter_A(LED_Screen* screen, int x, int y, CRGB& color)
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

  screen->SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  screen->SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  screen->SetLightsByColorRef(x + 4, y - 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  screen->SetLightsByColorRef(x + 4, y - 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  screen->SetLightsByColorRef(x + 4, y - 1, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 0, 14, color);   //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 14, color);   //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  screen->SetLightsByColorRef(x + 4, y + 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  screen->SetLightsByColorRef(x + 4, y + 4, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 5, 4, color);    //  START ROW +5
  screen->SetLightsByColorRef(x + 4, y + 5, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 6, 4, color);    //  START ROW +6
  screen->SetLightsByColorRef(x + 4, y + 6, 4, color);
}

void Image2D_Letter_B(LED_Screen* screen, int x, int y, CRGB& color)
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

  screen->SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  screen->SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  screen->SetLightsByColorRef(x + 4, y - 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  screen->SetLightsByColorRef(x + 4, y - 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  screen->SetLightsByColorRef(x + 4, y - 1, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 0, 12, color);   //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 12, color);   //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  screen->SetLightsByColorRef(x + 4, y + 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  screen->SetLightsByColorRef(x + 4, y + 4, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 5, 14, color);   //  START ROW +5
  screen->SetLightsByColorRef(x - 6, y + 6, 14, color);   //  START ROW +6
}

void Image2D_Letter_C(LED_Screen* screen, int x, int y, CRGB& color)
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

  screen->SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  screen->SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  screen->SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  screen->SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  screen->SetLightsByColorRef(x - 6, y + 0, 4, color);    //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 4, color);    //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  screen->SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  screen->SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  screen->SetLightsByColorRef(x - 6, y + 5, 14, color);   //  START ROW +5
  screen->SetLightsByColorRef(x - 6, y + 6, 14, color);   //  START ROW +6
}

void Image2D_Letter_R(LED_Screen* screen, int x, int y, CRGB& color)
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

  screen->SetLightsByColorRef(x - 6, y - 5, 14, color);   //  START ROW -5
  screen->SetLightsByColorRef(x - 6, y - 4, 14, color);   //  START ROW -4
  screen->SetLightsByColorRef(x - 6, y - 3, 4, color);    //  START ROW -3
  screen->SetLightsByColorRef(x + 4, y - 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 2, 4, color);    //  START ROW -2
  screen->SetLightsByColorRef(x + 4, y - 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y - 1, 4, color);    //  START ROW -1
  screen->SetLightsByColorRef(x + 4, y - 1, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 0, 12, color);   //  START ROW +0
  screen->SetLightsByColorRef(x - 6, y + 1, 12, color);   //  START ROW +1
  screen->SetLightsByColorRef(x - 6, y + 2, 4, color);    //  START ROW +2
  screen->SetLightsByColorRef(x + 4, y + 2, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 3, 4, color);    //  START ROW +3
  screen->SetLightsByColorRef(x + 4, y + 3, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 4, 4, color);    //  START ROW +4
  screen->SetLightsByColorRef(x + 4, y + 4, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 5, 4, color);    //  START ROW +5
  screen->SetLightsByColorRef(x + 4, y + 5, 4, color);
  screen->SetLightsByColorRef(x - 6, y + 6, 4, color);    //  START ROW +6
  screen->SetLightsByColorRef(x + 4, y + 6, 4, color);
}

void Image2D_SimpleFlame01(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x + 0, y - 5, 1, flameColor1);   //  START ROW -5
  screen->SetLightsByColorRef(x - 1, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x - 2, y - 2, 1, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 1, y - 2, 1, flameColor2);
  screen->SetLightsByColorRef(x + 0, y - 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 2, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 2, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 1, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 2, y + 1, 4, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 3, y + 2, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 2, 1, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 2, 2, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 4, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 3, 2, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 3, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 4, 2, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 4, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 6, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 6, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 7, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 7, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame02(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x - 1, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x - 1, y - 2, 2, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 2, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 1, flameColor2);
  screen->SetLightsByColorRef(x + 0, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 2, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 3, y + 1, 4, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 4, y + 2, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 2, 1, flameColor3);
  screen->SetLightsByColorRef(x - 1, y + 2, 3, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 3, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 3, 1, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 3, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 3, 2, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 3, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 4, 2, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 4, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 3, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 3, y + 6, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 6, 2, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 3, y + 7, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 7, 2, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame03(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x - 2, y - 2, 2, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 3, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 2, y - 1, 2, flameColor2);
  screen->SetLightsByColorRef(x + 0, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 0, 4, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 4, y + 1, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 1, 1, flameColor3);
  screen->SetLightsByColorRef(x - 1, y + 1, 3, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 3, y + 2, 4, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 2, 2, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 3, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 3, 1, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 4, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 3, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 3, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 3, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 3, y + 6, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 3, y + 7, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame04(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x - 3, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x - 4, y - 2, 1, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 3, y - 2, 1, flameColor2);
  screen->SetLightsByColorRef(x - 2, y - 2, 2, flameColor1);
  screen->SetLightsByColorRef(x - 4, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 3, y - 1, 3, flameColor2);
  screen->SetLightsByColorRef(x + 0, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 0, 1, flameColor3);
  screen->SetLightsByColorRef(x - 2, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 4, y + 1, 4, flameColor2);
  screen->SetLightsByColorRef(x + 0, y + 1, 2, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 4, y + 2, 3, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 2, 1, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 2, 2, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 6, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 5, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 3, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 4, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 3, y + 5, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 6, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 7, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame05(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x - 1, y - 2, 3, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 3, y - 1, 2, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 3, flameColor2);
  screen->SetLightsByColorRef(x + 2, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 3, y + 0, 4, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 2, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 4, y + 1, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y + 1, 5, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 3, y + 2, 6, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 3, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x + 0, y + 3, 1, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 2, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 4, 3, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 3, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 4, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 6, 6, flameColor3);
  screen->SetLightsByColorRef(x + 3, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 7, 6, flameColor3);
  screen->SetLightsByColorRef(x + 3, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame06(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x + 0, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x - 1, y - 2, 1, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x + 0, y - 2, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 2, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 1, y - 1, 2, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 4, y + 0, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x + 3, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 3, y + 1, 5, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x + 3, y + 1, 1, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 2, y + 2, 5, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 2, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x + 0, y + 3, 2, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 3, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 3, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 4, 2, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 4, 2, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 4, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 4, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 6, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 7, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame07(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x + 0, y - 4, 1, flameColor1);   //  START ROW -4
  screen->SetLightsByColorRef(x - 1, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x + 0, y - 3, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y - 2, 1, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x + 0, y - 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y - 1, 5, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x + 0, y - 1, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x + 3, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 0, 2, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 2, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 0, 2, flameColor1);
  screen->SetLightsByColorRef(x + 3, y + 0, 1, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 1, y + 1, 2, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 1, 3, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 2, y + 2, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 2, 1, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 2, 1, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 2, 1, flameColor2);
  screen->SetLightsByColorRef(x - 4, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 3, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x + 0, y + 3, 1, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 3, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 3, 2, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 4, 3, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 4, 2, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 3, flameColor2);
  screen->SetLightsByColorRef(x + 4, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 4, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 3, y + 6, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 3, y + 7, 5, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 7, 1, flameColor1);
}

void Image2D_SimpleFlame08(LED_Screen* screen, int x, int y, CRGB& flameColor1, CRGB& flameColor2, CRGB& flameColor3)
{
  screen->SetLightsByColorRef(x + 0, y - 5, 1, flameColor1);   //  START ROW -5
  screen->SetLightsByColorRef(x - 1, y - 4, 3, flameColor1);   //  START ROW -4
  screen->SetLightsByColorRef(x + 0, y - 3, 1, flameColor1);   //  START ROW -3
  screen->SetLightsByColorRef(x - 4, y - 2, 1, flameColor1);   //  START ROW -2
  screen->SetLightsByColorRef(x - 1, y - 2, 1, flameColor1);
  screen->SetLightsByColorRef(x + 0, y - 2, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 2, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y - 1, 1, flameColor1);   //  START ROW -1
  screen->SetLightsByColorRef(x - 1, y - 1, 2, flameColor2);
  screen->SetLightsByColorRef(x + 1, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x + 3, y - 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 2, y + 0, 1, flameColor1);   //  START ROW +0
  screen->SetLightsByColorRef(x - 1, y + 0, 3, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 0, 1, flameColor1);
  screen->SetLightsByColorRef(x - 3, y + 1, 1, flameColor1);   //  START ROW +1
  screen->SetLightsByColorRef(x - 2, y + 1, 3, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 1, 1, flameColor3);
  screen->SetLightsByColorRef(x + 2, y + 1, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 2, 1, flameColor1);   //  START ROW +2
  screen->SetLightsByColorRef(x - 3, y + 2, 2, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 2, 1, flameColor3);
  screen->SetLightsByColorRef(x + 0, y + 2, 1, flameColor2);
  screen->SetLightsByColorRef(x + 1, y + 2, 2, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 3, 1, flameColor1);   //  START ROW +3
  screen->SetLightsByColorRef(x - 4, y + 3, 3, flameColor2);
  screen->SetLightsByColorRef(x - 1, y + 3, 2, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 3, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 3, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 4, 1, flameColor1);   //  START ROW +4
  screen->SetLightsByColorRef(x - 4, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 4, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 4, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 4, 1, flameColor1);
  screen->SetLightsByColorRef(x - 4, y + 5, 1, flameColor1);   //  START ROW +5
  screen->SetLightsByColorRef(x - 3, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x - 2, y + 5, 3, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 5, 1, flameColor2);
  screen->SetLightsByColorRef(x + 2, y + 5, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 6, 1, flameColor1);   //  START ROW +6
  screen->SetLightsByColorRef(x - 4, y + 6, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 6, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 6, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 6, 1, flameColor1);
  screen->SetLightsByColorRef(x - 5, y + 7, 1, flameColor1);   //  START ROW +7
  screen->SetLightsByColorRef(x - 4, y + 7, 1, flameColor2);
  screen->SetLightsByColorRef(x - 3, y + 7, 4, flameColor3);
  screen->SetLightsByColorRef(x + 1, y + 7, 2, flameColor2);
  screen->SetLightsByColorRef(x + 3, y + 7, 1, flameColor1);
}

void Image2D_PacManGhostEyes(LED_Screen* screen, int x, int y, CRGB& eyeWhite, CRGB& eyeBall)
{
  screen->SetLightsByColorRef(x - 3, y - 4, 2, eyeWhite); // START ROW -4
  screen->SetLightsByColorRef(x + 3, y - 4, 2, eyeWhite);
  screen->SetLightsByColorRef(x - 4, y - 3, 4, eyeWhite); // START ROW -3
  screen->SetLightsByColorRef(x + 2, y - 3, 4, eyeWhite);
  screen->SetLightsByColorRef(x - 4, y - 2, 2, eyeWhite); // START ROW -2
  screen->SetLightsByColorRef(x - 2, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x + 2, y - 2, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 2, 2, eyeBall);
  screen->SetLightsByColorRef(x - 4, y - 1, 2, eyeWhite); // START ROW -1
  screen->SetLightsByColorRef(x - 2, y - 1, 2, eyeBall);
  screen->SetLightsByColorRef(x + 2, y - 1, 2, eyeWhite);
  screen->SetLightsByColorRef(x + 4, y - 1, 2, eyeBall);
  screen->SetLightsByColorRef(x - 3, y + 0, 2, eyeWhite); // START ROW +0
  screen->SetLightsByColorRef(x + 3, y + 0, 2, eyeWhite);
}