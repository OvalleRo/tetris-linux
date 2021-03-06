#include "RotableTetrimino.h"
#include <array>

unsigned short * RotableTetrimino::rotate()
{
  unsigned short * new_map = new unsigned short[MAP_LENGTH*MAP_LENGTH]{0};
  int x, y, pos, new_x, new_y;
  int minX, minY;
  minX = minY = MAP_LENGTH;
  for (x = 0; x < MAP_LENGTH; x++)
  {
    for (y = 0; y < MAP_LENGTH; y++)
    {
      new_x = (4 * (3 - y));
      new_y = x;
      pos = (4 * x) + y;

      if (map[pos] == 1) {
        if ((new_x / MAP_LENGTH) < minX) {
          minX = (new_x / MAP_LENGTH);
        }
        if (new_y < minY) {
          minY = new_y;
        }
      }

      new_map[new_x + new_y] = map[pos];
    }
  }
  if (minX == 0 && minY == 0) {
    return new_map;
  }
  
  unsigned short * corrected = new unsigned short[MAP_LENGTH*MAP_LENGTH]{ 0 };
  for (int i = minX; i < MAP_LENGTH; i++)
  {
    for (int j = minY; j < MAP_LENGTH; j++)
    {
      pos = (4 * i) + j;
      int newPos = pos - minY - (4 * minX);

      corrected[newPos] = new_map[pos];
      corrected[pos] = 0;
    }
  }
  delete[] new_map;
  return corrected;
}
