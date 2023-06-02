#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "endGameScreen.h"
using namespace std;

class gameOver : public endGameScreen
{
public:

	/*
	* function draws end game if game is lost
	* @return return decision in int to return to menu
	*/
	int draw_game_over();

	/*
	* object to hold font for text
	*/
	sf::Font font;

	/*
	* object with items to display
	*/
	sf::Text game_over_item[4];

	/*
	* variable holds decision of returning to menu
	*/
	int decision;
};

