#include <FastLED.h>

class GhostScreen {
  public:
    void Initialize(bool ledChutesLayout) {
      Chutes = ledChutesLayout;

      TranslateScreenVirtualIndices();
    }

    inline void SetScreen(CRGB color) { fill_solid(LEDs, LED_COUNT, color); }
    inline void ClearScreen() { SetScreen(CRGB::Black); }
    

    inline bool IsPixelBlack(int x, int y) { int index = PositionToIndex(x, y); return (index != -1) ? (LEDs[index].r == 0 && LEDs[index].g == 0 && LEDs[index].b == 0) : false; }
    inline const CRGB& GetPixel(int x, int y) { return (IsPosOnScreen(x, y)) ? LEDs[PositionToIndex(x, y)] : CRGB::Black; }

    inline void SetLEDByColorIndex(int x, int y, byte colorIndex) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = CRGB(GetColor(colorIndex, 0), GetColor(colorIndex, 1), GetColor(colorIndex, 2)); }
    inline void SetLEDByColorRef(int x, int y, const CRGB& color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDByColor(int x, int y, const CRGB color) { if (IsPosOnScreen(x, y) == true) LEDs[PositionToIndex(x, y)] = color; }
    inline void SetLEDIndexByColor(int index, CRGB color) { if (IsIndexOnScreen(index) == true) LEDs[index] = color; }
    inline void SetLightsByColorIndex(int x, int y, int count, byte colorIndex) { CRGB color = CRGB(GetColor(colorIndex, 0), GetColor(colorIndex, 1), GetColor(colorIndex, 2)); for (int i = 0; i < count; ++i) SetLEDByColorRef(x + i, y, color); }

    const int BUTTON_DELAY = 400;
    int ButtonIterationTimer = 0;

    static const int LED_COUNT = 158;
    static const int SCREEN_WIDTH = 14;
    static const int SCREEN_HEIGHT = 14;
    CRGB LEDs[LED_COUNT];

    void ResetTetris(int x, int y, byte colorIndex);

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