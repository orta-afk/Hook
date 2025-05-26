#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "entity.h"
#include "tilemap.h"

typedef struct window {
  int width;
  int height;
  char *title;
} window;

typedef struct game {
  entity entity;
  entityTexture entityTexture;
  tilemap tilemap;
} game;

void initGame(game *game, window *window);
void updateGame(game *game, float dt);
void drawGame(game *game);
void destroyGame(game *game);

#endif
