#include "Game.h"

Game::Game(int cellSize, sf::VideoMode videoMode){
   window.create(videoMode, "Game of Life", sf::Style::Default);
   gridWidth = videoMode.width;
   gridHeight = videoMode.height;
   gridCellSize = cellSize;
}

void Game::run(){
    window.setFramerateLimit(30);
    std::vector<std::vector<Cell>> gridVect;
    std::vector<std::vector<Cell>> gridVectCopy;


    //Fill A vector with new Cell objects, copy that into a 2nd vector.
    std::vector<Cell> row;
    for (int x = 0; x < gridWidth; x += gridCellSize){
        for (int y = 0; y < gridHeight; y += gridCellSize){
            row.push_back(Cell(gridCellSize, x, y));
        }
        gridVect.push_back(row);
        gridVectCopy.push_back(row);
        row.clear();
    }

    while (window.isOpen()){
        checkEvents();
        window.clear();
        for (int x = 0; x < gridVect.size(); x += 1){
            for (int y = 0; y < gridVect[x].size(); y += 1){
                gridVect[x][y].livingStatus(x, y, gridVect, gridVectCopy);
                gridVect[x][y].draw(window);
            }
        }
        //copy the 2nd vector into the main one
        gridVect.clear();
        std::vector<Cell> row;
        for (int i = 0; i < gridVectCopy.size(); i++){
            for (int j = 0; j < gridVectCopy[i].size(); j++){
                row.push_back(gridVectCopy[i][j]);
            }
            gridVect.push_back(row);
            row.clear();
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