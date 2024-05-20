inline void SetStrip(CRGB* leds, const int ledCount, CRGB color) { fill_solid(leds, ledCount, color); }
inline void ClearStrip(CRGB* leds, const int ledCount) { SetStrip(leds, ledCount, CRGB::Black); }

inline int GetRandomVibrantColorIndex()
{
  switch (random(9))
  {
    case 0:   return 1;   break;
    case 1:   return 2;   break;
    case 2:   return 3;   break;
    case 3:   return 4;   break;
    case 4:   return 5;   break;
    case 5:   return 6;   break;
    case 6:   return 7;   break;
    case 7:   return 48;   break;
    case 8:   return 49;   break;
  }
}

//////////////////////////////
//  HELPER FUNCTIONS
//////////////////////////////
CRGB Wheel(byte wheelPosition)
{
    wheelPosition = 255 - wheelPosition;
    if(wheelPosition < 85)
    {
        return CRGB(255 - wheelPosition * 3, 0, wheelPosition * 3);
    }
    else if(wheelPosition < 170)
    {
        wheelPosition -= 85;
        return CRGB(0, wheelPosition * 3, 255 - wheelPosition * 3);
    }
    else
    {
        wheelPosition -= 170;
        return CRGB(wheelPosition * 3, 255 - wheelPosition * 3, 0);
    }
}

//  The basic colors
#define COMMON_COLOR_COUNT    62
const byte COMMON_COLORS[COMMON_COLOR_COUNT][3] = 
{
  {   0,   0,   0 },  //  Black
  { 255,   0,   0 },  //  Red
  {   0, 255,   0 },  //  Green
  {   0,   0, 255 },  //  Blue
  { 200, 200,   0 },  //  Yellow
  {   0, 255, 255 },  //  Cyan (Mario Morph BG)
  { 255,   0, 255 },  //  Magenta
  { 255, 255, 255 },  //  White
  { 100, 100, 100 },  //  Pale White (MegaMan BG)
  {  67,  79, 254 },  //  MegaMan Blue 1
  {  36, 242, 205 },  //  MegaMan Blue 2
  { 251, 236, 154 },  //  MegaMan Skin
  { 240, 208, 176 },  //  SMB3 Mario Skin
  { 248, 056,   0 },  //  SMB3 Mario Raccoon 1
  { 240, 144,  88 },  //  SMW2 Skin 1
  { 232,  96,  80 },  //  SMW2 Skin 2
  { 248, 248, 248 },  //  SMW2 Buttons
  { 168,  80,   0 },  //  SMW2 Raccoon 1
  { 120,  64,  40 },  //  SMW2 Raccoon 2
  { 224, 128,  48 },  //  SMW2 Raccoon 3
  { 240, 200,  48 },  //  SMW2 Raccoon 4
  { 248, 184, 128 },  //  SMW2 Raccoon 5
  {  40,  72, 128 },  //  SMW2 Overalls 1 (dark blue)
  {  56, 112, 168 },  //  SMW2 Overalls 2 (light blue)
  {  72, 152, 208 },  //  SMW2 Overalls 3 (lightest blue)
  { 160,   0,   0 },  //  SMW2 ShirtHat 1 (dark red)
  { 200,   0,  24 },  //  SMW2 ShirtHat 2 (light red)
  { 248,  32,  56 },  //  SMW2 ShirtHat 3 (lightest red)
  { 231,  95,  19 },  //  SMB3 Tanuki 1
  { 240, 208, 176 },  //  SMB3 Tanuki 2
  { 144,  56,  24 },  //  SMW2 Tanuki 1 (dark brown)
  { 184,  96,  24 },  //  SMW2 Tanuki 2 (light brown)
  { 216, 128,  24 },  //  SMW2 Tanuki 3 (yellow brown)
  { 184,  96,  24 },  //  SMW2 Tanuki 4 (lightest brown)
  { 248,  56,   0 },  //  SMB3 FireFlower 1
  { 255, 163,  71 },  //  SMB3 FireFlower 2
  { 200,  16,   0 },  //  SMW2 FireFlower 1 (dark red)
  { 248,  64,   0 },  //  SMW2 FireFlower 2 (orange)
  { 248, 104,  32 },  //  SMW2 FireFlower 3 (light orange)
  { 248, 208,  88 },  //  SMW2 FireHat 1 (yellow)
  { 248, 240, 176 },  //  SMW2 FireHat 2 (light yellow)
  {  88,  72,  72 },  //  SMW2 hardhat 1 (dark gray)
  { 136, 120, 120 },  //  SMW2 hardhat 2 (gray)
  { 192, 176, 176 },  //  SMW2 hardhat 3 (light gray)
  { 248, 208, 152 },  //  SMW2 YellowHat 2 (light yellow)
  { 248, 176,  48 },  //  SMW2 YellowHat 1 (yellow)
  { 176,  88,   0 },  //  SMW2 BrownSuit 1 (brown-yellow)
  { 208, 128,  24 },  //  SMW2 BrownSuit 2 (yellow-brown)
  { 255, 165,   0 },  //  Orange
  { 128,   0, 128 },  //  Purple
  { 253,  15,  15 },  //  Pac-Man Blinky Red
  { 253, 150, 180 },  //  Pac-Man Pinky Pink
  {  93, 243, 212 },  //  Pac-Man Inky Blue
  { 255, 171,  77 },  //  Pac-Man Clyde Orange
  {  40,  40,  40 },  //  Tetris Background
  { 248, 136,   0 },  //  MechaKoopa Orange 1
  { 184,  40,   0 },  //  MechaKoopa Orange 2
  {   0, 120,   0 },  //  MechaKoopa Green 1
  {   0, 184,   0 },  //  MechaKoopa Green 2
  {   0, 248,   0 },  //  MechaKoopa Green 3
  {  48, 112, 128 },  //  MechaKoopa Cyan
  { 160, 160, 255 },  //  Blue-White (fire center)
};

inline byte GetColor(byte colorIndex, int part) { return COMMON_COLORS[colorIndex][part]; }

inline void PrintColor(int r, int g, int b) {
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.println(b);
}

struct Color
{
public:
  int R, G, B;
  int NextR = 0, NextG = 0, NextB = 0;
  unsigned long lastColorChange = 0;
  Color(int r, int g, int b) : R(r), G(g), B(b), NextR(r), NextG(g), NextB(b) {}

  inline void SetNextColor(int r, int g, int b) {
    NextR = r;
    NextG = g;
    NextB = b;
  }

  void ColorShift(const int colorChangeSpeed, const unsigned long changeDelay) {
    if (R < NextR)        { R = min(255, min(NextR, R + colorChangeSpeed)); }
    else if (R > NextR)   { R = max(0, max(NextR, R - colorChangeSpeed)); }
    if (G < NextG)        { G = min(255, min(NextG, G + colorChangeSpeed)); }
    else if (G > NextG)   { G = max(0, max(NextG, G - colorChangeSpeed)); }
    if (B < NextB)        { B = min(255, min(NextB, B + colorChangeSpeed)); }
    else if (B > NextB)   { B = max(0, max(NextB, B - colorChangeSpeed)); }

    Color colorDelta = Color(NextR - R, NextG - G, NextB - B);
    if (colorDelta.isZero() && (millis() >= (lastColorChange + changeDelay))) {
      int newColorIndex = 0;
      do
      {
        newColorIndex = GetRandomVibrantColorIndex();
        colorDelta = Color(int(COMMON_COLORS[newColorIndex][0]) - R, int(COMMON_COLORS[newColorIndex][1]) - G, int(COMMON_COLORS[newColorIndex][2]) - B);
      } while (colorDelta.isLessThan(colorChangeSpeed));

      NextR = COMMON_COLORS[newColorIndex][0];
      NextG = COMMON_COLORS[newColorIndex][1];
      NextB = COMMON_COLORS[newColorIndex][2];

      lastColorChange = millis();
    }
  }

  inline bool isZero()                const { return (R == 0 && G == 0 && B == 0);  }
  inline bool isLessThan(int amount)  const { return (abs(R) < amount && abs(G) < amount && abs(B) < amount);  }
};