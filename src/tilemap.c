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
      if(i >= 6 && i <= 34 && j == 16){
        map[i][j] = middleTile;
      }else{
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
        case middleTile:
          tilemap->indexX = 19;
          tilemap->indexY = 0;
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
