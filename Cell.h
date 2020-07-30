
#pragma once
#include "Game.h"

class Cell{

	private:
		sf::RectangleShape cellRect;
		void getColor();
		void kill();
		void resurrect();

	public:
			bool isAlive;
		void livingStatus(int x, int y, std::vector<std::vector<Cell>> &vectOrig, std::vector<std::vector<Cell>> &vectCopy);
		void draw(sf::RenderTarget& target);
		Cell(int cellSize, int positionX, int positionY);

};