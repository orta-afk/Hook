#include "raylib.h"
#include "entity.h"

int main(){
  InitWindow(640, 320, "HOOK");  

  entity entity;
  entityTexture entityTexture;

  initEntity(&entity);
  initEntityTexture(&entityTexture);
  
  while(!WindowShouldClose()){   

    updateEntity(&entity, &entityTexture);
    
    BeginDrawing();
    ClearBackground(BLACK);  
    drawEntity(&entityTexture);
    EndDrawing();
  }
  CloseWindow();
  destroyEntity(&entityTexture);
}

