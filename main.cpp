#include <iostream>
#include "Game.h"

int main(){

    //std::srand(static_cast<unsigned>(time(NULL)));
    srand(time(NULL));
    Game game;

    // Loop
    while (game.running()){
        game.update();
        game.render();

    }

    return 0;
}
