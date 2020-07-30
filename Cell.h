
#pragma once
#include "Game.h"

class Cell{

	private:
		sf::RectangleShape cellRect;
		void getColor();
		bool isAlive;
		void kill();
		void reborn();

	public:
		void livingStatus();
		void draw(sf::RenderTarget& target);
		Cell(int cellSize, int positionX, int positionY);

};