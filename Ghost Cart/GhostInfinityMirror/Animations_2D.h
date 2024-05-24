#pragma once

#include "LED_Screen.h"
#include "Images_2D.h"

///////////////
// 2D Patterns
///////////////
void Anim2D_RainbowFlow2(LED_Screen* screen, const int colorChangeSpeed = 1, bool berzerk = false)
{
  static int delayTime = 125;
  
  if (screen->FrameAnimation.IterateFrame(delayTime))
  {
    static int rainbowPosition = 0;
    for (int i = 0; i < screen->SCREEN_WIDTH * 2; ++i)
    {
      CRGB color = Wheel(((i * 1024 / screen->LED_COUNT) + rainbowPosition) & 255);
      for (int j = 0; j < screen->SCREEN_HEIGHT; ++j)
      {
        if (j < 0 || j >= screen->SCREEN_WIDTH) continue;
        if ((i - j) < 0 || (i - j) >= screen->SCREEN_WIDTH) continue;

        screen->SetLEDByColorRef(i - j, j, color);
        if (berzerk) rainbowPosition += colorChangeSpeed;
      }
    }
    
    if (!berzerk) rainbowPosition += colorChangeSpeed;
    FastLED.show();
  }
}


void Anim2D_PacManChompDanceThrough(LED_Screen* screen, int x = -6, int y = 7, int frameLengthMillis = 150, int animationFrameCount = 46, int frame = 255)
{
  if (frame == 255) frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);
  
  CRGB color1 = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));

  if (frame % 8 == 0)       Image2D_PacManChomp01(screen, frame + x, y, color1);
  else if (frame % 8 == 1)  Image2D_PacManChomp02(screen, frame + x, y, color1);
  else if (frame % 8 == 2)  Image2D_PacManChomp03(screen, frame + x, y, color1);
  else if (frame % 8 == 3)  Image2D_PacManChomp02(screen, frame + x, y, color1);
  else if (frame % 8 == 4)  Image2D_PacManChomp01(screen, frame + x, y, color1);
  else if (frame % 8 == 5)  Image2D_PacManChomp02(screen, frame + x, y, color1);
  else if (frame % 8 == 6)  Image2D_PacManChomp03(screen, frame + x, y, color1);
  else                      Image2D_PacManChomp02(screen, frame + x, y, color1);
}


void Anim2D_PacManGhostDanceThrough(LED_Screen* screen, int x = 6, int y = 7, int frameLengthMillis = 48, int body = 50, int eyeWhite = 7, int eyeBall = 0, int animationFrameCount = 100, int frame = 255)
{
  if (frame == 255) frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  CRGB bodyColor = CRGB(GetColor(body, 0), GetColor(body, 1), GetColor(body, 2));
  CRGB eyeWhiteColor = CRGB(GetColor(eyeWhite, 0), GetColor(eyeWhite, 1), GetColor(eyeWhite, 2));
  CRGB eyeBallColor = CRGB(GetColor(eyeBall, 0), GetColor(eyeBall, 1), GetColor(eyeBall, 2));
  
  if (frame % 4 == 0)       Image2D_PacManGhostWalk01(screen, frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 1)  Image2D_PacManGhostWalk01(screen, frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 2)  Image2D_PacManGhostWalk02(screen, frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
  else if (frame % 4 == 3)  Image2D_PacManGhostWalk02(screen, frame + x, y, bodyColor, eyeWhiteColor, eyeBallColor);
}


void Anim2D_PacManChompDanceThroughPlusGhost(LED_Screen* screen, int frameLengthMillis = 100, int animationFrameCount = 140, int frame = 255)
{
  if (frame == 255) frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  Anim2D_PacManChompDanceThrough(screen, -6, 7, frameLengthMillis, animationFrameCount, frame);
  Anim2D_PacManGhostDanceThrough(screen, -26, 7, frameLengthMillis, 50, 7, 0, animationFrameCount, frame);
  Anim2D_PacManGhostDanceThrough(screen, -46, 7, frameLengthMillis, 51, 7, 0, animationFrameCount, frame);
  Anim2D_PacManGhostDanceThrough(screen, -66, 7, frameLengthMillis, 52, 7, 0, animationFrameCount, frame);
  Anim2D_PacManGhostDanceThrough(screen, -86, 7, frameLengthMillis, 53, 7, 0, animationFrameCount, frame);
}


void Anim2D_MsPacManChompDanceThrough(LED_Screen* screen, int frameLengthMillis = 100, int animationFrameCount = 48, int frame = 255)
{
  if (frame == 255) frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);
  
  CRGB body = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));
  CRGB bow = CRGB(GetColor(1, 0), GetColor(1, 1), GetColor(1, 2));
  CRGB eye = CRGB(GetColor(3, 0), GetColor(3, 1), GetColor(3, 2));

  if (frame % 8 == 0)       Image2D_MsPacManChomp01(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 1)  Image2D_MsPacManChomp01(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 2)  Image2D_MsPacManChomp02(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 3)  Image2D_MsPacManChomp02(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 4)  Image2D_MsPacManChomp03(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 5)  Image2D_MsPacManChomp03(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else if (frame % 8 == 6)  Image2D_MsPacManChomp02(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
  else                      Image2D_MsPacManChomp02(screen, screen->SCREEN_WIDTH - frame + 6, 7, body, bow, eye);
}


void Anim2D_SpaceInvaderDanceThrough(LED_Screen* screen, byte body = 7, byte mask = 7, int frame = 255)
{
  if (frame == 255) frame = screen->FrameAnimation.GetCurrentFrameIndex(333, 40);

  CRGB color1 = CRGB(GetColor(body, 0), GetColor(body, 1), GetColor(body, 2));
  CRGB color2 = CRGB(GetColor(mask, 0), GetColor(mask, 1), GetColor(mask, 2));
  
  if (frame & 1)  Image2D_SpaceInvader01(screen, frame - 6, 7, color1, color2);
  else            Image2D_SpaceInvader02(screen, frame - 6, 7, color1, color2);
}


void Anim2D_LetterMoveThrough_BRC(LED_Screen* screen, int x = 21, int y = 6, int frameLengthMillis = 60, int animationFrameCount = 90)
{
  int frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  CRGB yellow = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));
  
  Image2D_Letter_B(screen, x - frame, y, yellow);
  Image2D_Letter_R(screen, x + 16 - frame, y, yellow);
  Image2D_Letter_C(screen, x + 32 - frame, y, yellow);
}


void Anim2D_SimpleFlame(LED_Screen* screen, int x = 7, int y = 6, int frameLengthMillis = 140, int animationFrameCount = 8)
{
  int frame = screen->FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  CRGB flameColor1 = CRGB(GetColor(55, 0), GetColor(55, 1), GetColor(55, 2));
  CRGB flameColor2 = CRGB(GetColor(4, 0), GetColor(4, 1), GetColor(4, 2));
  CRGB flameColor3 = CRGB(GetColor(61, 0), GetColor(61, 1), GetColor(61, 2));
  
  switch (frame) {
    case 0: Image2D_SimpleFlame01(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 1: Image2D_SimpleFlame02(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 2: Image2D_SimpleFlame03(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 3: Image2D_SimpleFlame04(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 4: Image2D_SimpleFlame05(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 5: Image2D_SimpleFlame06(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 6: Image2D_SimpleFlame07(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
    case 7: Image2D_SimpleFlame08(screen, x, y, flameColor1, flameColor2, flameColor3);   break;
  }
}


void Anim2D_PacManGhostEyesOnly(LED_Screen* screen, int x = 6, int y = 7, int frameLengthMillis = 48, int eyeWhite = 7, int eyeBall = 0)
{
  CRGB eyeWhiteColor = CRGB(GetColor(eyeWhite, 0), GetColor(eyeWhite, 1), GetColor(eyeWhite, 2));
  CRGB eyeBallColor = CRGB(GetColor(eyeBall, 0), GetColor(eyeBall, 1), GetColor(eyeBall, 2));
  
  Image2D_PacManGhostEyes(screen, x, y, eyeWhiteColor, eyeBallColor);
}