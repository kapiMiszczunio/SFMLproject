#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "endGameScreen.h"
//#include "scoreTable.h"


class gameVictory : public endGameScreen
{
public:
	endGameScreen* screen;
	/*
	* function draws end screen window if game is won
	* @return returns decision in int about returning to menu
	*/
	int draw(sf::Time time, int difficulty);
	/*
	* object with items to display
	*/
	sf::Text victory_item[5];

	/*
	* object to hold font for text
	*/
	sf::Font font;

	/*
	* variable holds decision of returning to menu
	*/
	int decision;
};

