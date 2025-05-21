#include "raylib.h"
#include "game.h"

int main(){
  game game = {
    .width = 640,
    .height = 320,
    .title = "title",
    .color = BLACK};

  initGame(&game);
  updateGame(&game);
  destoryGame(&game);
}
