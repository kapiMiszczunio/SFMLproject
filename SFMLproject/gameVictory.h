#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "endGameScreen.h"
using namespace std;

class gameVictory : public endGameScreen
{
public:

	/*
	* function draws end screen window if game is won
	* @return returns decision in int about returning to menu
	*/
	int draw_victory();

	/*
	* object with items to display
	*/
	sf::Text victory_item[4];

	/*
	* object to hold font for text
	*/
	sf::Font font;

	/*
	* variable holds decision of returning to menu
	*/
	int decision;
};

