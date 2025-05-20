#include "tilemap.h"

int map[WIDTH][HEIGHT] = {};

void initT(tilemap *tilemap, tilemapTexture *tilemapTexture) {
  initTilemapTexture(tilemapTexture);
  initTilemap(tilemap, sky, tilemapTexture); 
}

void initTilemap(tilemap *tilemap, tiles tile, tilemapTexture *tilemapTexture) {
  switch (tile) {
  case sky:
    tilemapTexture->indexX = 3;
    tilemapTexture->indexY = 0;
    break;
  case topLeftTile:
    tilemapTexture->indexX = 0;
    tilemapTexture->indexY = 0;
    break;
  case topMiddleTile:
    tilemapTexture->indexX = 1;
    tilemapTexture->indexY = 0;
    break;
  case topRightTile:
    tilemapTexture->indexX = 2;
    tilemapTexture->indexY = 0;
    break;
  case middleLeftTile:
    tilemapTexture->indexX = 0;
    tilemapTexture->indexY = 1;
    break;
  case middleTile:
    tilemapTexture->indexX = 1;
    tilemapTexture->indexY = 1;
    break;
  case middleRightTile:
    tilemapTexture->indexX = 2;
    tilemapTexture->indexY = 1;
    break;
  case bottomLeftTile:
    tilemapTexture->indexX = 0;
    tilemapTexture->indexY = 2;
    break;
  case bottomMiddleTile:
    tilemapTexture->indexX = 1;
    tilemapTexture->indexY = 2;
    break;
  case bottomRightTile:
    tilemapTexture->indexX = 2;
    tilemapTexture->indexY = 2;
    break;
  }
}

void initTilemapTexture(tilemapTexture *tilemapTexture) {
  tilemapTexture->texture = LoadTexture("../assest/tilemap.png");
  tilemapTexture->indexX = 0;
  tilemapTexture->indexY = 0;
}

void updateTilemap(tilemap *tilemap, tiles tile) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (j == 7) {
        if (i == 6) {
          map[i][j] = topLeftTile;
        } else if (i == 14) {
          map[i][j] = topLeftTile;
        } else {
          map[i][j] = topMiddleTile;
        }
      }
    }
  }
}

void drawTilemap(tilemapTexture *tilemapTexture) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int tile = map[y][x];  // not map[x][y]

      tilemapTexture->source = (Rectangle){
          .x = (tile % 3) * SIZE,
          .y = (tile / 3) * SIZE,
          .width = SIZE,
          .height = SIZE};

      tilemapTexture->dest = (Rectangle){
          .x = x * SIZE, .y = y * SIZE, .width = SIZE, .height = SIZE};

      DrawTexturePro(tilemapTexture->texture, tilemapTexture->source,
                     tilemapTexture->dest, (Vector2){0, 0}, 0.0f, RAYWHITE);
    }
  }
}


void destroyTilemap(tilemapTexture *tilemapTexture) {
  UnloadTexture(tilemapTexture->texture);
}
