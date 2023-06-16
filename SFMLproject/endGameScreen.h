#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include "gameModel.h"
#include "enums.h"
//#include "scoreTable.h"

class endGameScreen
{
public:
	/*
	* function renders end screen window
	* @param RenderWindow object from sfml
	* @param items to display from sfml
	*/
	continuation renderwindow(sf::RenderWindow& window, sf::Text *items, int number_of_items, difficulty difficulty);
	virtual continuation draw(sf::Time time, difficulty difficulty);
	sf::Text window_item[4];
	sf::Font font;
	continuation decision;
};


