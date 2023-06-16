#pragma once
#include "SFML/Graphics.hpp"
#include "endGameScreen.h"

class gameOver : public endGameScreen
{
public:
	endGameScreen* screen;
	/*
	* function draws end game if game is lost
	* @return return decision in int to return to menu
	*/
	continuation draw(sf::Time time, difficulty difficulty);

	/*
	* object to hold font for text
	*/
	sf::Font font;

	/*
	* object to hold font for text
	*/
	sf::Font font2;

	/*
	* object with items to display
	*/
	sf::Text game_over_item[4];

	/*
	* variable holds decision of returning to menu
	*/
	continuation decision;
};

