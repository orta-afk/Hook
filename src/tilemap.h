#ifndef TILEMAP_H
#define TILEMAP_H

#include <time.h>
#include <stdlib.h>
#include "raylib.h"

#define SIZE 16
#define WIDTH 40
#define HEIGHT 20

extern int map[WIDTH][HEIGHT];

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
  
  grass1,
  grass2,
  grass3,
  grass4,
  grass5,
  grass6,
}tiles;

typedef enum iTiles{
  tree1,
  tree2,
  rock1,
  rock2,
  rock3,
}iTiles;

typedef struct tilemap{
  int indexX;
  int indexY;
  int number;
  tiles tile;
  iTiles itiles;
  Texture2D texture;
  Texture2D otherTexture;
  Rectangle source;
  Rectangle dest;
}tilemap;

void initTilemap(tilemap* tilemap);
void updateTilemap(tilemap* tilemap);
void stuffGen(tilemap *tilemap);
void drawTilemap(tilemap* tilemap);
void destroyTilemap(tilemap* tilemap);

#endif
