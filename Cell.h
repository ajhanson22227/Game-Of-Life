
#pragma once
#include "Game.h"

class Cell{

	private:
		sf::RectangleShape cellRect;
		bool isAlive;

	public:
		sf::RectangleShape livingStatus();
		void draw(sf::RenderTarget& target);
		Cell(int cellSize);

};