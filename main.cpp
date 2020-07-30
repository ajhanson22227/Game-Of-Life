#include "Game.h"
#include <cstdio>

int main(){
    srand(time(NULL));
    Game game(5, {1920, 1080});
    game.run();

    return 0;
}
