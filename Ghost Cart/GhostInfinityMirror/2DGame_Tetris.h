/*

#define TETRIS_BOARD_START_X    7
#define TETRIS_BOARD_START_Y    -2
#define TETRIS_BOARD_WIDTH      14
#define TETRIS_BOARD_HEIGHT     16

void ResetTetris(int x = (SCREEN_WIDTH / 2), int y = (SCREEN_HEIGHT / 2), byte colorIndex = 54)
{
  UpdateMillisOffset();

  ghostScreen.ClearStrip(LEDs, LED_COUNT);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 7, 14, colorIndex); // START ROW -7
  ghostScreen.SetLightsByColorIndex(x - 7, y - 6, 14, colorIndex); // START ROW -6
  ghostScreen.SetLightsByColorIndex(x - 7, y - 5, 2, colorIndex); // START ROW -5
  ghostScreen.SetLightsByColorIndex(x + 5, y - 5, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 4, 2, colorIndex); // START ROW -4
  ghostScreen.SetLightsByColorIndex(x + 5, y - 4, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 3, 2, colorIndex); // START ROW -3
  ghostScreen.SetLightsByColorIndex(x + 5, y - 3, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 2, 2, colorIndex); // START ROW -2
  ghostScreen.SetLightsByColorIndex(x + 5, y - 2, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y - 1, 2, colorIndex); // START ROW -1
  ghostScreen.SetLightsByColorIndex(x + 5, y - 1, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 0, 2, colorIndex); // START ROW +0
  ghostScreen.SetLightsByColorIndex(x + 5, y + 0, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 1, 2, colorIndex); // START ROW +1
  ghostScreen.SetLightsByColorIndex(x + 5, y + 1, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 2, 2, colorIndex); // START ROW +2
  ghostScreen.SetLightsByColorIndex(x + 5, y + 2, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 3, 2, colorIndex); // START ROW +3
  ghostScreen.SetLightsByColorIndex(x + 5, y + 3, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 4, 2, colorIndex); // START ROW +4
  ghostScreen.SetLightsByColorIndex(x + 5, y + 4, 2, colorIndex);
  ghostScreen.SetLightsByColorIndex(x - 7, y + 5, 14, colorIndex); // START ROW +5
  ghostScreen.SetLightsByColorIndex(x - 7, y + 6, 14, colorIndex); // START ROW +6
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
  ghostScreen.ResetTetris();
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
*/