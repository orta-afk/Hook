#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include "tilemap.h"

#define SIZE 16

typedef struct entity{
  int dir;
  int speed;
  int gravity;
  int max_gravity;
  bool isCollided;
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
void updateEntity(entity* entity, entityTexture* entityTexture, float dt);
void drawEntity(entityTexture* entityTexture);
void destroyEntity(entityTexture* entityTexture);

#endif 
