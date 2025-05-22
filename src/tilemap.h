#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"
#define SIZE 16
#define WIDTH 40
#define HEIGHT 20

typedef enum tiles{
  sky,
  leftTile,
  middleTile,
  rightTile,
  middleLeftTile,
  middleRightTile,
  bottomLeftTile,
  bottomRightTile,
  bottomtile,
}tiles;

typedef struct tilemap{
  int indexX;
  int indexY;
  tiles tile;
  Texture2D texture;
  Rectangle source;
  Rectangle dest;
}tilemap;

void initTilemap(tilemap* tilemap);
void updateTilemap(tilemap* tilemap);
void drawTilemap(tilemap* tilemap);
void destroyTilemap(tilemap* tilemap);

#endif
