#include "entity.h"

void initEntity(entity *entity) {
  entity->positions = (Vector2){100, 50};
  entity->velocity = (Vector2){0, 0};
  entity->gravity = 130;
  entity->max_gravity = 150;
  entity->speed = 60;
  entity->isCollided = false;
  entity->dir = 1;
}

void initEntityTexture(entityTexture *entityTexture) {
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

void gravity(entity *entity, float dt) {
  entity->velocity.y += entity->gravity;
  if (entity->velocity.y > entity->max_gravity) {
    entity->velocity.y = entity->max_gravity;
  }
}

void move(entity *entity, float dt) {
  int tileX = (int)(entity->positions.x) / SIZE;
  if (entity->isCollided == true) {
    if (tileX <= 5) {
      entity->dir = 1;
    } else if (tileX >= 35) {
      entity->dir = -1;
    }
    entity->velocity.x = entity->dir * entity->speed;
  }
}

void updateEntity(entity *entity, entityTexture *entityTexture, float dt) {
  gravity(entity, dt);
  move(entity, dt);
  entity->positions.x += entity->velocity.x * dt;
  entity->positions.y += entity->velocity.y * dt;

  int tileX = (int)(entity->positions.x) / SIZE;
  int tileY = (int)(entity->positions.y + SIZE) / SIZE;

  if (tileY >= 0 && tileY < HEIGHT && tileX >= 0 && tileX < WIDTH) {
    if (map[tileX][tileY] == middleLeftTile ||
        map[tileX][tileY] == middleTile ||
        map[tileX][tileY] == middleRightTile) {
      entity->positions.y = tileY * SIZE - SIZE;
      entity->velocity.y = 0;
      entity->isCollided = true;
    }
  }
  entityTexture->dest = (Rectangle){
      .x = entity->positions.x,
      .y = entity->positions.y,
      .width = SIZE,
      .height = SIZE,
  };
}

void drawEntity(entityTexture *entityTexture) {
  DrawTexturePro(entityTexture->texture, entityTexture->source,
                 entityTexture->dest, (Vector2){0, 0}, 0.0f, RAYWHITE);
}

void destroyEntity(entityTexture *entityTexture) {
  UnloadTexture(entityTexture->texture);
}
