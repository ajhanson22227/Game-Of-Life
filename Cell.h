
#pragma once
#include "Game.h"

class Cell{

	private:
		sf::RectangleShape cellRect;
		bool isAlive;

	public:
		void livingStatus();
		void draw(sf::RenderTarget& target);
		Cell(int cellSize, int positionX, int positionY);

};