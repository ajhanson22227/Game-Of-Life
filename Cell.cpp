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
        cellRect.setFillColor(sf::Color::Blue);
    }
    else{
        cellRect.setFillColor(sf::Color::Red);
    }
}

void Cell::kill(){
    this->isAlive = false;
    this->getColor();
}

void Cell::reborn(){
    this->isAlive = true;
    this->getColor();
}

void Cell::livingStatus(){

}