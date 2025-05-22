#include "raylib.h"
#include "entity.h"
#include "tilemap.h"

int main(){
  InitWindow(640, 320, "HOOK");  

  entity entity;
  entityTexture entityTexture;
  tilemap tilemap;

  initEntity(&entity);
  initEntityTexture(&entityTexture);
  initTilemap(&tilemap);
  
  SetTargetFPS(60);

  while(!WindowShouldClose()){   

    updateTilemap(&tilemap);
    updateEntity(&entity, &entityTexture);
    
    BeginDrawing();
    ClearBackground(BLACK);  
    drawTilemap(&tilemap);
    drawEntity(&entityTexture);
    EndDrawing();
  }
  CloseWindow();
  destroyEntity(&entityTexture);
  destroyTilemap(&tilemap);
}

