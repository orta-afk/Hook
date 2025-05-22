#include "entity.h"

void initEntity(entity *entity){
  entity->positions = (Vector2){100,50};
  entity->velocity = (Vector2){0,0};
  entity->gravity = 130;
  entity->max_gravity = 150;
}

void initEntityTexture(entityTexture *entityTexture){
  entityTexture->indexX = 26;
  entityTexture->indexY = 0;
  entityTexture->texture = LoadTexture("../assest/monochrome_packed.png");    
  entityTexture->source = (Rectangle){
    .x = SIZE * entityTexture->indexX,
    .y = SIZE * entityTexture->indexY,
    .width = SIZE,
    .height = SIZE,
  };
}

void gravity(entity* entity, float dt){
  entity->velocity.y += entity->gravity;
  if(entity->velocity.y > entity->max_gravity){
    entity->velocity.y = entity->max_gravity;
  }
}

void updateEntity(entity *entity, entityTexture* entityTexture, float dt){

  gravity(entity, dt);
    
  entity->positions.x += entity->velocity.x * dt;
  entity->positions.y += entity->velocity.y * dt;
  
  entity->bound = entityTexture->dest;
  entityTexture->dest = (Rectangle){
    .x = entity->positions.x,
    .y = entity->positions.y,
    .width = SIZE,
    .height = SIZE,
  }; 

  int tileX = (int)(entity->positions.x) / SIZE;
  int tileY = (int)(entity->positions.y + SIZE) / SIZE;

  if (tileY >= 0 && tileY < HEIGHT && tileX >= 0 && tileX < WIDTH) {
      if (map[tileX][tileY] != sky) {
          entity->positions.y = tileY * SIZE - SIZE;
          entity->velocity.y = 0;
      }
  }
}

void drawEntity(entityTexture *entityTexture){
  DrawTexturePro(entityTexture->texture, entityTexture->source, entityTexture->dest, (Vector2){0,0}, 0.0f, RAYWHITE);
}

void destroyEntity(entityTexture *entityTexture){
  UnloadTexture(entityTexture->texture);
}
