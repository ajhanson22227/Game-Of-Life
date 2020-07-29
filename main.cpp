#include "Game.h"
#include <cstdio>

int main(){
    srand(time(NULL));
    Game game(20, {800, 600});
    game.run();

    return 0;
}
