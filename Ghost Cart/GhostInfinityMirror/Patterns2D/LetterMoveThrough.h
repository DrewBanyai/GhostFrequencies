/*

void DrawLetter_A(int x, int y, CRGB& color)
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

void LetterMoveThrough_BRC(int x = 21, int y = 6, int frameLengthMillis = 60, int animationFrameCount = 90)
{
  int frame = FrameAnimation.GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

  DrawLetter_B(x - frame, y, 4);
  DrawLetter_R(x + 16 - frame, y, 4);
  DrawLetter_C(x + 32 - frame, y, 4);
}

*/