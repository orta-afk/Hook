#include "game.h"

void initGame(game *game){
  InitWindow(game->width, game->height, game->title);
}

void updateGame(game *game){
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(game->color);
    drawGame(game);
    EndDrawing();
  }
}

void drawGame(game* game){
  DrawText("lol", 100, 100, 17, WHITE);
}

void destoryGame(game *game){
  CloseWindow();
}
