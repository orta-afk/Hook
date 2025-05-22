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

  stuffGen(&tilemap);
  while(!WindowShouldClose()){   
    float dt  = GetFrameTime();
    updateEntity(&entity, &entityTexture, dt);
    updateTilemap(&tilemap);
    
    BeginDrawing();
    ClearBackground(BLACK);  
    drawTilemap(&tilemap);
    drawEntity(&entityTexture);
    EndDrawing();
  }
  CloseWindow();
  destroyTilemap(&tilemap);
  destroyEntity(&entityTexture);
}

