#include "entity.h"

void initEntity(entity *entity){
  entity->positions = (Vector2){40,50};
  entity->velocity = (Vector2){0,0};
}

void initEntityTexture(entityTexture *entityTexture){
  entityTexture->indexX = 26;
  entityTexture->indexY = 0;
  entityTexture->texture = LoadTexture("../assest/monochrome-transparent_packed.png");    
  entityTexture->source = (Rectangle){
    .x = SIZE * entityTexture->indexX,
    .y = SIZE * entityTexture->indexY,
    .width = SIZE,
    .height = SIZE,
  };
}

void updateEntity(entity *entity, entityTexture* entityTexture){
  entityTexture->dest = (Rectangle){
    .x = entity->positions.x,
    .y = entity->positions.y,
    .width = SIZE,
    .height = SIZE,
  }; 
}

void drawEntity(entityTexture *entityTexture){
  DrawTexturePro(entityTexture->texture, entityTexture->source, entityTexture->dest, (Vector2){0,0}, 0.0f, RAYWHITE);
}

void destroyEntity(entityTexture *entityTexture){
  UnloadTexture(entityTexture->texture);
}
