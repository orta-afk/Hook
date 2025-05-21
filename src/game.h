#ifndef GAME_H
#define GAME_H

#include "raylib.h"

typedef struct game{
  const int width;
  const int height;
  const char *title;
  float dt;
  Color color;
}game;

void initGame(game* game);
void updateGame(game* game);
void drawGame(game* game);
void destoryGame(game* game);

#endif
