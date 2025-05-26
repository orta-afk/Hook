#include "game.h"
#include "entity.h"
#include "tilemap.h"

void initGame(game *game, window *window) {
  window->width = 960;
  window->height = 544;
  window->title = "HOOK";

  InitWindow(window->width, window->height, window->title);

  initEntity(&game->entity);
  initEntityTexture(&game->entityTexture);
  initTilemap(&game->tilemap);
  stuffGen(&game->tilemap);
}

void updateGame(game *game, float dt) {
  updateTilemap(&game->tilemap);
  updateEntity(&game->entity, &game->entityTexture, dt);
}

void drawGame(game *game) {
  drawTilemap(&game->tilemap);
  drawEntity(&game->entityTexture);
}

void destroyGame(game *game) {
  destroyEntity(&game->entityTexture);
  destroyTilemap(&game->tilemap);
  CloseWindow();
}
