#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

class Game{
    private:
        sf::RenderWindow window;
        sf::Vector2u gridSize;
        int gridWidth;
        int gridHeight;
        int mCellWidth;
        int mcellHeight;
        int gridCellSize;
        //int gridCellSize;
        void checkEvents();

    public:
        Game(int cellSize, sf::VideoMode videoMode);
        void run();
};