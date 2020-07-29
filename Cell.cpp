#include "Cell.h"  

Cell::Cell(int cellSize){
    cellRect.setSize(sf::Vector2f(cellSize, cellSize));
    cellRect.setFillColor(sf::Color::Blue);
}

void Cell::draw(sf::RenderTarget &target){
    target.draw(cellRect);
}