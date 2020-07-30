#include "Game.h"
#include "Cell.h"
#include <vector>

Game::Game(int cellSize, sf::VideoMode videoMode){
   window.create(videoMode, "Game of Life", sf::Style::Default);
   gridWidth = videoMode.width;
   //std::cout << "width: " << gridWidth << "\n";
   gridHeight = videoMode.height;
   //std::cout << "height: " << gridHeight << "\n";
   mcellHeight = cellSize;
   mCellWidth = cellSize;
}

void Game::run(){
    window.setFramerateLimit(2);
    std::vector<std::vector<Cell>> gridVect;
    std::vector<Cell> row;
    for (int x = 0; x < gridWidth; x += mCellWidth){
        for (int y = 0; y < gridHeight; y += mcellHeight){
            row.push_back(Cell(mCellWidth, x, y));
        }
        gridVect.push_back(row);
    }

     while (window.isOpen()){
        checkEvents();
        window.clear();
        for (int x = 0; x < gridVect.size(); x += 1){
            for (int y = 0; y < gridVect[x].size(); y += 1){
                // gridVect[x][y].livingStatus();
                gridVect[x][y].draw(window);
        }
    }
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