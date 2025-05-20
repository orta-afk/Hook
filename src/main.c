#include "raylib.h"

typedef struct {
  const int width;
  const int height;
  const char *title;
  Color color;
} window;

int main() {
  window window = {
      .width = 640, .height = 320, .title = "Hook", .color = BLACK};
  InitWindow(window.width, window.height, window.title);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(window.color);
    EndDrawing();
  }
  return 0;
}
