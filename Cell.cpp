#include "Cell.h"  

Cell::Cell(int cellSize, int positionX, int positionY){
    cellRect.setSize(sf::Vector2f(cellSize, cellSize));
    cellRect.setPosition(sf::Vector2f(positionX, positionY));

    isAlive = (rand() % 2);
    this->getColor();
}

void Cell::draw(sf::RenderTarget &target){
    target.draw(cellRect);
}

void Cell::getColor(){
    if (isAlive){
        cellRect.setFillColor(sf::Color::White);
    }
    else{
        cellRect.setFillColor(sf::Color::Black);
    }
}

void Cell::kill(){
    this->isAlive = false;
    this->getColor();
}

void Cell::resurrect(){
    this->isAlive = true;
    this->getColor();
}

void Cell::livingStatus(int x, int y, std::vector<std::vector<Cell>> &vect){
    int liveNeighbors = 0;
    for (int i = x - 1; i <= x + 1; i++){
        if (i < 0) continue;
        if (i >= vect.size()) break;

        for (int j = y - 1; j <= y + 1; j++){
            if (j < 0) continue;
            if (j >= vect[i].size()) break;
            if (i == j) continue;
            if (vect[i][j].isAlive == true) liveNeighbors++;
        }
    }
    if (this->isAlive == true &&  liveNeighbors > 3 || liveNeighbors < 2){
        this->kill();
    }
    else if (this->isAlive == false && liveNeighbors == 3){
        this->resurrect();
    }

}