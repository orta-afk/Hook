#include "tilemap.h"

int map[WIDTH][HEIGHT] = {0};

void initTilemap(tilemap *tilemap) {
  srand(time(NULL));
  tilemap->tile = sky;
  tilemap->indexX = 0;
  tilemap->indexY = 0;
  tilemap->texture = LoadTexture("../assest/monochrome-transparent_packed.png");
}

void stuffGen(tilemap *tilemap) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (j == 14 && i >= 5 && i <= 35) {
        int grassType = rand() % 6;
        switch (grassType) {
        case 0:
          map[i][j] = grass1;
          break;
        case 1:
          map[i][j] = grass2;
          break;
        case 2:
          map[i][j] = grass3;
          break;
        case 3:
          map[i][j] = grass4;
          break;
        case 4:
          map[i][j] = grass5;
          break;
        case 5:
          map[i][j] = grass6;
          break;
        }
      } else {
        map[i][j] = sky;
      }
    }
  }
}

void updateTilemap(tilemap *tilemap) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (j == 14) continue; 
      if (j == 15) {
        if (i == 5)
          map[i][j] = rightTile;
        else if (i == 35)
          map[i][j] = leftTile;
        else if (i > 5 && i < 35)
          map[i][j] = middleTile;
        else
          map[i][j] = sky;
      } else if (j > 15 && j < 18) {
        if (i == 5)
          map[i][j] = middleLeftTile;
        else if (i == 35)
          map[i][j] = middleRightTile;
        else
          map[i][j] = sky;
      } else if (j == 18) {
        if (i == 5)
          map[i][j] = bottomLeftTile;
        else if (i > 5 && i < 35)
          map[i][j] = bottomtile;
        else if (i == 35)
          map[i][j] = bottomRightTile;
      } else {
        map[i][j] = sky;
      }
    }
  }
}

void drawTilemap(tilemap *tilemap) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      tiles tile = (tiles)map[i][j];
      switch (tile) {
      case sky:
        tilemap->indexX = 0;
        tilemap->indexY = 0;
        break;
      case rightTile:
        tilemap->indexX = 18;
        tilemap->indexY = 0;
        break;
      case leftTile:
        tilemap->indexX = 20;
        tilemap->indexY = 0;
        break;
      case middleTile:
        tilemap->indexX = 19;
        tilemap->indexY = 0;
        break;
      case middleLeftTile:
        tilemap->indexX = 18;
        tilemap->indexY = 1;
        break;
      case middleRightTile:
        tilemap->indexX = 20;
        tilemap->indexY = 1;
        break;
      case bottomLeftTile:
        tilemap->indexX = 18;
        tilemap->indexY = 2;
        break;
      case bottomtile:
        tilemap->indexX = 19;
        tilemap->indexY = 2;
        break;
      case bottomRightTile:
        tilemap->indexX = 20;
        tilemap->indexY = 2;
        break;
      case grass1:
        tilemap->indexX = 49;
        tilemap->indexY = 0;
        break;
      case grass2:
        tilemap->indexX = 50;
        tilemap->indexY = 0;
        break;
      case grass3:
        tilemap->indexX = 51;
        tilemap->indexY = 0;
        break;
      case grass4:
        tilemap->indexX = 49;
        tilemap->indexY = 1;
        break;
      case grass5:
        tilemap->indexX = 50;
        tilemap->indexY = 1;
        break;
      case grass6:
        tilemap->indexX = 51;
        tilemap->indexY = 1;
        break;
      }

      tilemap->source = (Rectangle){.x = tilemap->indexX * SIZE,
                                    .y = tilemap->indexY * SIZE,
                                    .width = SIZE,
                                    .height = SIZE};

      tilemap->dest = (Rectangle){
          .x = i * SIZE,
          .y = j * SIZE,
          .width = SIZE,
          .height = SIZE,
      };

      DrawTexturePro(tilemap->texture, tilemap->source, tilemap->dest,
                     (Vector2){0, 0}, 0.0f, RAYWHITE);
    }
  }
}

void destroyTilemap(tilemap *tilemap) { UnloadTexture(tilemap->texture); }
