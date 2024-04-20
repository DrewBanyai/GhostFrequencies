/*

void DrawMarioWarp01(int x, int y, CRGB& outline, CRGB& skintone, byte outfit = 34)
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

void DrawMarioWarp02(int x, int y, CRGB& outline, byte skintone1 = 15, byte raccoon1 = 17, byte skintone2 = 14, byte red3 = 27, byte raccoon2 = 18, byte red2 = 26, byte red1 = 25, byte skintone3 = 21, byte overalls2 = 23, byte overalls1 = 22, byte raccoon3 = 7, byte raccoon4 = 24, byte raccoon5 = 19, byte goldshoes = 20)
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

void DrawMarioWarp03(int x, int y, CRGB& outline, byte skintone = 12, byte raccoon = 28)
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

void DrawMarioWarp04(int x, int y, CRGB& outline, byte skintone2 = 15, byte tanuki1 = 30, byte skintone1 = 14, byte tanuki2 = 31, byte tanuki3 = 32, byte skintone3 = 21, byte belly = 16, byte tanuki4 = 17, byte tanuki5 = 19, byte goldshoes = 20)
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

void DrawMarioWarp05(int x, int y, CRGB& outline, byte skintone = 12, byte redsuit = 34)
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

void DrawMarioWarp06(int x, int y, CRGB& outline, byte red3 = 27, byte skintone1 = 14, byte red1 = 25, byte red2 = 26, byte skintone2 = 15, byte skintone3 = 21, byte overalls2 = 23, byte overalls3 = 24, byte button = 16, byte goldshoes = 20, byte shoes1 = 19, byte shoes2 = 17, byte overalls1 = 22)
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

void DrawMarioWarp07(int x, int y, CRGB& outline, byte skintone = 12, byte suit = 35)
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

void DrawMarioWarp08(int x, int y, CRGB& outline, byte hat3 = 16, byte skintone1 = 14, byte hat1 = 39, byte hat2 = 40, byte skintone2 = 15, byte skintone3 = 21, byte overalls2 = 37, byte overalls3 = 38, byte goldshoes = 20, byte shoes1 = 19, byte shoes2 = 17, byte overalls1 = 36)
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

void DrawMarioWarp09(int x, int y, CRGB& outline, byte skintone = 35, byte suit = 7)
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

void DrawMarioWarp10(int x, int y, CRGB& outline, byte hardhat1 = 41, byte hardhat2 = 42, byte hardhat3 = 43, byte skintone1 = 15, byte skintone2 = 14, byte skintone3 = 21, byte yellowhat2 = 44, byte yellowhat1 = 45, byte brownsuit1 = 46, byte brownsuit2 = 47, byte button = 16, byte brownsuit3 = 19)
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

  CRGB outline = CRGB(GetColor(0, 0), GetColor(0, 1), GetColor(0, 2));
  CRGB redsuit = CRGB(GetColor(34, 0), GetColor(34, 1), GetColor(34, 2));
  CRGB skintone = CRGB(GetColor(12, 0), GetColor(12, 1), GetColor(12, 2));
  CRGB suit = CRGB(GetColor(12, 0), GetColor(12, 1), GetColor(12, 2));

  
  if      (frameIndex == 0) DrawMarioWarp09(frame - 14, 7, redsuit);
  else if (frameIndex == 1) DrawMarioWarp10(frame - 14, 7, outline);
  else if (frameIndex == 2) DrawMarioWarp01(frame - 14, 7, outline);
  else if (frameIndex == 3) DrawMarioWarp02(frame - 14, 7, outline);
  else if (frameIndex == 4) DrawMarioWarp07(frame - 14, 7, redsuit);
  else if (frameIndex == 5) DrawMarioWarp08(frame - 14, 7, outline);
  else if (frameIndex == 6) DrawMarioWarp05(frame - 14, 7, outline);
  else if (frameIndex == 7) DrawMarioWarp06(frame - 14, 7, outline);
  else if (frameIndex == 8) DrawMarioWarp03(frame - 14, 7, outline);
  else                      DrawMarioWarp04(frame - 14, 7, outline);
}

*/