#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#define SIZE 16

typedef struct entity{
  Vector2 velocity;
  Vector2 positions;
}entity;

typedef struct entityTexture{
  int indexX;
  int indexY;
  Texture2D texture;
  Rectangle source;
  Rectangle dest;
}entityTexture;

void initEntity(entity* entity);
void initEntityTexture(entityTexture* entityTexture);
void updateEntity(entity* entity, entityTexture* entityTexture);
void drawEntity(entityTexture* entityTexture);
void destroyEntity(entityTexture* entityTexture);

#endif 
