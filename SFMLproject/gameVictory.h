#pragma once
#include "SFML/Graphics.hpp"
#include "endGameScreen.h"
#include <iostream>

class gameVictory : public endGameScreen
{
public:
	endGameScreen* screen;

	/*
	* function draws end screen window if game is won
	* @return returns decision in int about returning to menu
	*/
	continuation draw(sf::Time time, difficulty difficulty);
	
	/*
	* object with items to display
	*/
	sf::Text victory_item[5];

	/*
	* object to hold font for text(normal)
	*/
	sf::Font font;

	/*
	* object to hold font for text(cipher display)
	*/
	sf::Font font2;

	/*
	* variable holds decision of returning to menu
	*/
	continuation decision;
};

