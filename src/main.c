#include "raylib.h"
#include "tilemap.h"

typedef struct {
  const int width;
  const int height;
  const char *title;
  Color color;
} window;

int main() {
  window window = {.width = 640, .height = 320, .title = "Hook", .color = WHITE};

  tilemapTexture tilemapTexture;
  tilemap tilemap;

  InitWindow(window.width, window.height, window.title);
  initT(&tilemap, &tilemapTexture);

  updateTilemap(&tilemap, sky); 
  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(window.color);
    drawTilemap(&tilemapTexture);
    EndDrawing();
  }

  destroyTilemap(&tilemapTexture);
  CloseWindow();
  return 0;
}
