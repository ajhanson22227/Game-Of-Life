#include "Game.h"
#include "Cell.h"

Game::Game(int cellSize, sf::VideoMode videoMode){
   window.create(videoMode, "Game of Life", sf::Style::Default);
}

void Game::run(){
    window.setFramerateLimit(60);
    Cell cell(100);

     while (window.isOpen()){
        checkEvents();
        window.clear();
        cell.draw(window);
        window.display();
    }
}

void Game::checkEvents(){
    //Checks for events and handles them accordingly
    sf::Event event;
    while (window.pollEvent(event)){
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }
    }
}