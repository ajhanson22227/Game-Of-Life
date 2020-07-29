#pragma once

#include <SFML/Graphics.hpp>

#include <iostream> //std::cout for debugging atm

class Game{
    private:
        sf::RenderWindow window;
        sf::Vector2u gridSize;
        int gridWidth;
        int gridHeight;
        int mCellWidth;
        int mcellHeight;
        int gridCellSize;
        void checkEvents();

    public:
        Game(int cellSize, sf::VideoMode videoMode/*, uint32_t windowSettings = sf::Style::Default*/);
        void run();
};