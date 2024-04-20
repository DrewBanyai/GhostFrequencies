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

/*
void DrawMegaManRun01(int x, int y, byte outline, byte body1, byte body2, byte skin, byte eyes)
{
 
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

*/