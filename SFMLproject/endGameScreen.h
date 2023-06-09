#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <stdlib.h>

class endGameScreen
{
public:
	/*
	* function renders end screen window
	* @param RenderWindow object from sfml
	* @param items to display from sfml
	*/
	int renderwindow(sf::RenderWindow& window, sf::Text *items);
	virtual int draw(sf::Time time);
	sf::Text window_item[4];
	sf::Font font;
	int decision;
};

