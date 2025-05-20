#ifndef TILEMAP_H
#define TILEMAP_H

#define SIZE 32
#define WIDTH 20
#define HEIGHT 10

#include "raylib.h"

typedef enum {
  topLeftTile,
  topMiddleTile,
  topRightTile,
  middleLeftTile,
  middleTile,
  middleRightTile,
  bottomLeftTile,
  bottomMiddleTile,
  bottomRightTile,
  sky,
} tiles;

typedef struct {
  tiles tile;
} tilemap;

typedef struct {
  int indexX;
  int indexY;
  tiles tile;
  Texture2D texture;
  Rectangle source;
  Rectangle dest;
} tilemapTexture;

void initT(tilemap *tilemap, tilemapTexture *tilemapTexture);
void initTilemap(tilemap *tilemap, tiles tile, tilemapTexture *tilemapTexture);
void initTilemapTexture(tilemapTexture *tilemapTexture);
void updateTilemap(tilemap *tilemap, tiles tile);
void drawTilemap(tilemapTexture *tilemapTexture);
void destroyTilemap(tilemapTexture *tilemapTexture);

#endif
