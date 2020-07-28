#include "Game.h"

Game::Game(sf::VideoMode videoMode) :  window(videoMode, "Game of Life", sf::Style::Default){
   
}

void Game::run(){
    window.setFramerateLimit(60);
     while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
        }

        window.clear();
        window.display();
    }
}