#include "game.h"

int main() {
  game game;
  window window;

  initGame(&game, &window);
  
  RenderTexture2D target = LoadRenderTexture(640, 320);
  SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);  

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    updateGame(&game, dt);

    BeginTextureMode(target);
    ClearBackground(BLACK);
    drawGame(&game);
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexturePro(target.texture,
                   (Rectangle){0, 0, (float)target.texture.width,
                   -(float)target.texture.height},
                   (Rectangle){0, 0, (float)window.width, (float)window.height},
                   (Vector2){0, 0}, 0.0f, RAYWHITE);
    EndDrawing();
  }

  UnloadRenderTexture(target);
  destroyGame(&game);
  return 0;
}
