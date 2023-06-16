#pragma once
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include "gameModel.h"
#include "enums.h"

class endGameScreen
{
public:
	/*
	* function renders end screen window
	* @param RenderWindow object from sfml
	* @param items to display from sfml
	* @param game difficulty
	*/
	continuation renderwindow(sf::RenderWindow& window, sf::Text *items, int number_of_items, difficulty difficulty);
	
	/*
	*virtual function 
	*/
	virtual continuation draw(sf::Time time, difficulty difficulty);
	
	/*
	* array containing text to draw on window
	*/
	sf::Text window_item[4];
	
	/*
	* object to hold font for text
	*/
	sf::Font font;

	/*
	* object to hold font for text(digit)
	*/
	sf::Font font2;

	/*
	*variable holds decision of returning to menu
	*/
	continuation decision;
};


