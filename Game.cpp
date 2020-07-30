#include "Game.h"

Game::Game(int cellSize, sf::VideoMode videoMode){
   window.create(videoMode, "Game of Life", sf::Style::Default);
   gridWidth = videoMode.width;
   gridHeight = videoMode.height;
   mcellHeight = cellSize;
   mCellWidth = cellSize;
}

void Game::run(){
    window.setFramerateLimit(1);
    std::vector<std::vector<Cell>> gridVect;
    std::vector<std::vector<Cell>> gridVectCopy;



    std::vector<Cell> row;
    for (int x = 0; x < gridWidth; x += mCellWidth){
        for (int y = 0; y < gridHeight; y += mcellHeight){
            row.push_back(Cell(mCellWidth, x, y));
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
                gridVectCopy[x][y].livingStatus(x, y, gridVectCopy);
                gridVectCopy[x][y].draw(window);
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

// void Game::clone(std::vector<std::vector<Cell>> &vectOriginal, std::vector<std::vector<Cell>> &vectCloneFrom){
//     std::vector<Cell> row;
//     for (int i = 0; i < vectCloneFrom.size(); i++){
//         for (int j = 0; j < vectCloneFrom[i].size(); j++){
//             vectOriginal[i][j] = vectCloneFrom[i][j];
//         }
//     }
// }