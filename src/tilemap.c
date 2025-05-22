#include "tilemap.h"
#include <raylib.h>

int map[WIDTH][HEIGHT] = {0};

void initTilemap(tilemap *tilemap){
  tilemap->tile = sky;
  tilemap->indexX = 0;
  tilemap->indexY = 0;
  tilemap->texture = LoadTexture("../assest/monochrome-transparent_packed.png");
}


void updateTilemap(tilemap *tilemap){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      if (j == 15) {
        if (i == 5) {
          map[i][j] = rightTile;
        } else if (i == 35) {
          map[i][j] = leftTile;
        } else if (i > 5 && i < 35) {
          map[i][j] = middleTile;
        } else {
          map[i][j] = sky;
        }
      } else if (j > 15 && j < 18) {
        if (i == 5) {
          map[i][j] = middleLeftTile;
        } else if (i == 35) {
          map[i][j] = middleRightTile;
        } else {
          map[i][j] = sky;
        } 
      } else if(j == 18){
        if(i == 5){
          map[i][j] = bottomLeftTile;
        }else if(i > 5 && i < 35){
          map[i][j] = bottomtile;
        } else if(i == 35){
          map[i][j] = bottomRightTile;
        }
      } else {
        map[i][j] = sky;
      }
    }
  }
}

void drawTilemap(tilemap *tilemap){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      tiles tile = (tiles)map[i][j];  
      switch(tile){
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
      }

      tilemap->source = (Rectangle){
        .x = tilemap->indexX * SIZE,  
        .y = tilemap->indexY * SIZE,
        .width = SIZE,
        .height = SIZE
      };

      tilemap->dest = (Rectangle){
        .x = i * SIZE,
        .y = j * SIZE,
        .width = SIZE,
        .height = SIZE,
      };

      DrawTexturePro(tilemap->texture, tilemap->source, tilemap->dest, (Vector2){0, 0}, 0.0f, RAYWHITE);
    }
  }  
}


void destroyTilemap(tilemap *tilemap){
  UnloadTexture(tilemap->texture);
}
