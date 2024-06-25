#include "LED_Screen.h"

#define TETRIS_SCREEN_WIDTH       14
#define TETRIS_SCREEN_HEIGHT      14
#define LINE_CLEAR_TIME_MILLIS    2000
#define PIECE_STARTING_POS_X      7
#define PIECE_STARTING_POS_Y      -2
#define PIECE_MOVEMENT_MILLIS     600
#define TETROMINO_SHAPE_SIZE      4
#define TETRIS_INPUT_DELAY_TIMER  200

String GetTetrominoPieceName(int shapeIndex) {
  switch (shapeIndex) {
    case 0:   return "LINE";
    case 1:   return "L-BEND (forward)";
    case 2:   return "L-BEND (backward)";
    case 3:   return "SQUARE";
    case 4:   return "S-BEND";
    case 5:   return "PYRAMID";
    case 6:   return "Z-BEND";
    default:  return "ERROR";
  }
}

String GetPieceDirectionName(int direction) {
  switch (direction) {
    case 0:   return "0 degrees";
    case 1:   return "90 degrees";
    case 2:   return "180 degrees";
    case 3:   return "270 degrees";
    default:  return "ERROR";
  }
}

Position2D TetrominoPositions[TETROMINO_SHAPE_SIZE];
Position2D* GetTetrominoPositions(int shapeIndex, int direction, int x, int y) {
  switch (shapeIndex) {
    case 0: //  Line
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 2, y + 0);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 1);
          TetrominoPositions[3] = Position2D(x + 0, y + 2);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x - 2, y + 0);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 0);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x + 0, y - 2);
          TetrominoPositions[1] = Position2D(x + 0, y - 1);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
      }
      break;
    case 1: //  L (forward)
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 2, y + 0);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 0, y + 0);
          TetrominoPositions[1] = Position2D(x + 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 1);
          TetrominoPositions[3] = Position2D(x + 0, y + 2);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x - 2, y + 0);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y - 1);
          TetrominoPositions[3] = Position2D(x + 0, y - 2);
          break;
      }
      break;
    case 2: //  L (backward)
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x - 2, y + 0);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y - 1);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y - 2);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 0);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x + 0, y + 0);
          TetrominoPositions[1] = Position2D(x + 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 2, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 1);
          TetrominoPositions[3] = Position2D(x + 0, y + 2);
          break;
      }
      break;
    case 3:
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x + 0, y + 0);
          TetrominoPositions[1] = Position2D(x + 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 1);
          TetrominoPositions[3] = Position2D(x + 1, y + 1);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x - 1, y + 1);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x - 1, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y - 1);
          TetrominoPositions[2] = Position2D(x - 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 0);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 1, y - 1);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 0);
          break;
      }
      break;
    case 4:
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y - 1);
          TetrominoPositions[3] = Position2D(x + 1, y - 1);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 1);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x + 0, y + 0);
          TetrominoPositions[1] = Position2D(x + 1, y + 0);
          TetrominoPositions[2] = Position2D(x - 1, y + 1);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x - 1, y - 1);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
      }
      break;
    case 5:
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 0);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
      }
      break;
    case 6:
      switch (direction) {
        case 0:
          TetrominoPositions[0] = Position2D(x - 1, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y - 1);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x + 1, y + 0);
          break;
        case 1:
          TetrominoPositions[0] = Position2D(x + 1, y - 1);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 1, y + 0);
          TetrominoPositions[3] = Position2D(x + 0, y + 1);
          break;
        case 2:
          TetrominoPositions[0] = Position2D(x - 1, y + 0);
          TetrominoPositions[1] = Position2D(x + 0, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 1);
          TetrominoPositions[3] = Position2D(x + 1, y + 1);
          break;
        case 3:
          TetrominoPositions[0] = Position2D(x + 0, y - 1);
          TetrominoPositions[1] = Position2D(x - 1, y + 0);
          TetrominoPositions[2] = Position2D(x + 0, y + 0);
          TetrominoPositions[3] = Position2D(x - 1, y + 1);
          break;
      }
      break;
  }
  return TetrominoPositions;
}

class Tetris_Game2D {
  public:
    Tetris_Game2D() {
      ClearBoard();
      LineClearingComplete();
      nextPieceSelectionMillis = 500;
    }

    void Input(NES_Controller* nesController) {
      if (millis() < InputDelayTimer) return;
      if (IsLineBeingCleared()) return;

      //  A button rotates a piece
      if (nesController->CheckButton(NES_A_BUTTON)) {
        if (CanRotatePiece()) {
          CurrentPieceDirection += 1;
          if (CurrentPieceDirection >= 4) CurrentPieceDirection = 0;
          InputDelayTimer = millis() + TETRIS_INPUT_DELAY_TIMER;
          return;
        }
      }

      if (nesController->CheckButton(NES_DOWN_BUTTON)) {
        MovePieceDown();
        InputDelayTimer = millis() + TETRIS_INPUT_DELAY_TIMER;
        return;
      }

      if (nesController->CheckButton(NES_LEFT_BUTTON)) {
        if (CanMovePiece(-1)) {
          CurrentPieceXY[0] -= 1;
          InputDelayTimer = millis() + TETRIS_INPUT_DELAY_TIMER;
          return;
        }
      }

      if (nesController->CheckButton(NES_RIGHT_BUTTON)) {
        if (CanMovePiece(1)) {
          CurrentPieceXY[0] += 1;
          InputDelayTimer = millis() + TETRIS_INPUT_DELAY_TIMER;
          return;
        }
      }

      if (nesController->CheckButton(NES_B_BUTTON)) {
        //  TODO: Move the piece immediately as low as it can go and select a new piece
          InputDelayTimer = millis() + TETRIS_INPUT_DELAY_TIMER;
      }
    }

    void Update() {
      //  Grab the latest millis() and if we've overrun back to the start, reset timers accordingly and return
      unsigned long currentMillis = millis();
      if (currentMillis < lastPieceMoveMillis) { lastPieceMoveMillis = 0; clearLineTimerMillis = 0; return; }

      UpdateLineClearing(currentMillis);
      if (IsLineBeingCleared()) return;

      if (CurrentPieceIndex == -1 && currentMillis > nextPieceSelectionMillis) {
        //Serial.println("SELECTING NEXT PIECE AS CURRENTPIECEINDEX IS -1");
        SelectNextPiece();
      }

      unsigned long diffTime = currentMillis - lastPieceMoveMillis;
      if (diffTime > PIECE_MOVEMENT_MILLIS) {
        MovePieceDown();
        lastPieceMoveMillis = currentMillis;
      }
    }

    void Render(LED_Screen* screen) {
      Update();

      //  First, render the board
      for (int i = 0; i < TETRIS_SCREEN_WIDTH; ++i) {
        for (int j = 0; j < TETRIS_SCREEN_HEIGHT; ++j) {
          CRGB colorRef = GetCRGBColor(Board[i][j]);
          screen->SetLEDByColorRef(i, j, colorRef);
        }
      }

      //  Second, render the current floating piece
      if (CurrentPieceIndex != -1) {
        Position2D* piecePositions = GetTetrominoPositions(CurrentPieceIndex, CurrentPieceDirection, CurrentPieceXY[0], CurrentPieceXY[1]);
        for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {    
          CRGB pieceColor = CRGB(GetColor(CurrentPieceColor, 0), GetColor(CurrentPieceColor, 1), GetColor(CurrentPieceColor, 2));
          screen->SetLEDByColorRef(piecePositions[i].X, piecePositions[i].Y, pieceColor);
        }
      }

      //  Third, if we are clearing a line, render the animation
      RenderLineClearing(screen);
    }

  private:
    unsigned char Board[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT];
    unsigned long lastPieceMoveMillis = 0;
    unsigned long clearLineTimerMillis = 0;
    unsigned long nextPieceSelectionMillis = 0;
    unsigned long InputDelayTimer = 0;
    int LineClearedIndices[TETROMINO_SHAPE_SIZE];
    long CurrentPieceIndex = -1;
    long CurrentPieceDirection = 0;
    unsigned int CurrentPieceColor = 0;
    int CurrentPieceXY[2];

    bool CanRotatePiece() {
      if (CurrentPieceIndex == -1) return false;

      int newDirection = CurrentPieceDirection + 1;
      if (newDirection >= 4) newDirection = 1;

      Position2D* newPositions = GetTetrominoPositions(CurrentPieceIndex, newDirection, CurrentPieceXY[0], CurrentPieceXY[1]);
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        Position2D newPoint = Position2D(newPositions[i].X, newPositions[i].Y);
        if (newPoint.X < 0) return false;
        if (newPoint.X >= 14) return false;
        if (newPoint.Y >= 14) return false;
        if (newPoint.Y < 0) continue;
        if (Board[newPoint.X][newPoint.Y] != 0) return false;
      }
      return true;
    }

    bool CanMovePiece(int deltaX) {
      if (CurrentPieceIndex == -1) return false;

      Position2D* newPositions = GetTetrominoPositions(CurrentPieceIndex, CurrentPieceDirection, CurrentPieceXY[0] + deltaX, CurrentPieceXY[1]);
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        Position2D newPoint = Position2D(newPositions[i].X, newPositions[i].Y);
        if (newPoint.X < 0) return false;
        if (newPoint.X >= 14) return false;
        if (newPoint.Y >= 14) return false;
        if (newPoint.Y < 0) continue;
        if (Board[newPoint.X][newPoint.Y] != 0) return false;
      }
      return true;
    }

    void SelectNextPiece() {
      CurrentPieceIndex = random(7);
      CurrentPieceDirection = random(4);
      CurrentPieceXY[0] = PIECE_STARTING_POS_X;
      CurrentPieceXY[1] = PIECE_STARTING_POS_Y;
      CurrentPieceColor = GetRandomVibrantColorIndex();
      /*
      Serial.print("New Piece Selected: ");
      Serial.print(GetTetrominoPieceName(CurrentPieceIndex));
      Serial.print(" (direction ");
      Serial.print(GetPieceDirectionName(CurrentPieceDirection));
      Serial.println(")");
      */
    }

    void MovePieceDown() {
      if (CurrentPieceIndex == -1) return;

      //  Check the position to see if we need to stop the piece as it has hit its end point
      //Serial.print("CurrentPieceXY[1] == "); Serial.println(CurrentPieceXY[1]);
      Position2D* shapePositions = GetTetrominoPositions(CurrentPieceIndex, CurrentPieceDirection, CurrentPieceXY[0], CurrentPieceXY[1]);
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        Position2D belowPoint = Position2D(shapePositions[i].X, shapePositions[i].Y + 1);
        /*
        Serial.print("Checking Below Point: ");
        Serial.print(belowPoint.X);
        Serial.print(", ");
        Serial.print(belowPoint.Y);
        Serial.print(" [");
        Serial.print(Board[belowPoint.X][belowPoint.Y]);
        Serial.println("]");
        */
        if (belowPoint.Y < 0) continue;
        if ((belowPoint.Y >= 14) || (Board[belowPoint.X][belowPoint.Y] != 0)) {
          //Serial.println("Unable to drop the piece by 1 position.");
          CommitCurrentPiece();
          return;
        }
      }

      //  Move the piece down
      //Serial.println("MOVING PIECE DOWN 1");
      CurrentPieceXY[1] += 1;
    }

    void CommitCurrentPiece() {
      Position2D* shapePositions = GetTetrominoPositions(CurrentPieceIndex, CurrentPieceDirection, CurrentPieceXY[0], CurrentPieceXY[1]);

      //  Check if any position we're about to commit to is above the top of the screen. If so, the player has lost the game
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        Position2D point = Position2D(shapePositions[i].X, shapePositions[i].Y);
        if (point.Y < 0) {
          PlayerLost();
          return;
        }
      }

      //Serial.print("COMMITTING PIECE: ");
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        Position2D point = Position2D(shapePositions[i].X, shapePositions[i].Y);
        /*
        Serial.print("[");
        Serial.print(point.X);
        Serial.print(", ");
        Serial.print(point.Y);
        Serial.print("]");
        */
        Board[point.X][point.Y] = CurrentPieceColor;
      }
      //Serial.println("");

      CheckBoardForLineClears();
      SelectNextPiece();
    }

    void CheckBoardForLineClears() {
      for (int y = 0; y < TETRIS_SCREEN_HEIGHT; ++y) {
        bool lineCleared = true;
        for (int x = 0; x < TETRIS_SCREEN_WIDTH; ++x) lineCleared &= (Board[x][y] != 0);
        if (lineCleared == true) {
          AddLineToBeCleared(y);
        }
      }
    }

    void PlayerLost() {
      //Serial.println("Player has lost the game!");
      ClearBoard();
      SelectNextPiece();
    }

    void UpdateLineClearing(unsigned long currentMillis) {
      if (clearLineTimerMillis == 0) return;
      if (IsLineBeingCleared() == false) {
        //Serial.println("LINE IS NOT CURRENTLY BEING CLEARED");
        return LineClearingComplete();
      }
      
      if (currentMillis > clearLineTimerMillis) {
        //Serial.println("LINE CLEAR TIMER IS COMPLETE");
        return LineClearingComplete();
      }
    }

    void RenderLineClearing(LED_Screen* screen) {
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i)
        if (LineClearedIndices[i] != -1)
          Anim2D_TetrisLineClear(screen, LineClearedIndices[i]);
    }

    void AddLineToBeCleared(int lineIndex = -1) {
      //Serial.print("Adding Line To Be Cleared (index "); Serial.print(lineIndex); Serial.println(")");

      unsigned long currentMillis = millis();
      clearLineTimerMillis = millis() + LINE_CLEAR_TIME_MILLIS;
      if (clearLineTimerMillis < currentMillis) clearLineTimerMillis = LINE_CLEAR_TIME_MILLIS;

      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        if (LineClearedIndices[i] != -1) continue;
        LineClearedIndices[i] = lineIndex;
        //Serial.print("LineClearedIndices["); Serial.print(i); Serial.print("] = "); Serial.println(LineClearedIndices[i]);
        return;
      }
    }

    bool IsLineBeingCleared() {
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i)
        if (LineClearedIndices[i] != -1)
          return true;
      return false;
    }

    void LineClearingComplete() {
      //  First, move all lines above down one
      for (int i = 0; i < TETROMINO_SHAPE_SIZE; ++i) {
        if (LineClearedIndices[i] != -1)
          ClearLineAndMoveBoard(LineClearedIndices[i]);
          LineClearedIndices[i] = -1;
          //Serial.print("LineClearedIndices["); Serial.print(i); Serial.print("] = "); Serial.println(LineClearedIndices[i]);
      }

      //  Third, reset the clearLineTimerMillis
      clearLineTimerMillis = 0;

      //Serial.println("LINE CLEARING COMPLETE");
    }

    void ClearLineAndMoveBoard(int lineIndex) {
      /*
      Serial.print("ClearLineAndMoveBoard(");
      Serial.print(lineIndex);
      Serial.println(")");
      */
      for (int y = lineIndex; y >= 1; --y) {
        for (int x = 0; x < TETRIS_SCREEN_WIDTH; ++x) {
          Board[x][y] = Board[x][y - 1];
        }
      }
    }

    void ClearBoard() {
      for (int i = 0; i < TETRIS_SCREEN_WIDTH; ++i) {
        for (int j = 0; j < TETRIS_SCREEN_HEIGHT; ++j) {
          Board[i][j] = 0;
        }
      }
    }
};

static Tetris_Game2D TETRIS_INSTANCE;

void Game2D_Tetris(LED_Screen* screen) {
  //  Render
  TETRIS_INSTANCE.Render(screen);
}