#include "Cell.h"  

Cell::Cell(int cellSize, int positionX, int positionY){
    cellRect.setSize(sf::Vector2f(cellSize, cellSize));
    cellRect.setFillColor(sf::Color::Blue);
    cellRect.setPosition(sf::Vector2f(positionX, positionY));

    isAlive = true;
}

void Cell::draw(sf::RenderTarget &target){
    target.draw(cellRect);
}

void Cell::livingStatus(){
    isAlive = (rand() % 2);

    if (isAlive){
        cellRect.setFillColor(sf::Color::Blue);
    }
    else{
        cellRect.setFillColor(sf::Color::Red);
    }
}