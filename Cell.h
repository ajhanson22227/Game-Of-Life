
#pragma once
#include "Game.h"

class Cell{

	private:
		sf::RectangleShape cellRect;
		void getColor();
		bool isAlive;
		void kill();
		void resurrect();

	public:
		void livingStatus(int x, int y, std::vector<std::vector<Cell>> &vect);
		void draw(sf::RenderTarget& target);
		Cell(int cellSize, int positionX, int positionY);

};