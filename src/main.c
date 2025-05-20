#include "raylib.h"

int main(){
  InitWindow(600, 320, "lol");
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(SKYBLUE);
    EndDrawing();
  }
}
