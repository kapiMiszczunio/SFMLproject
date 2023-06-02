#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "endGameScreen.h"
using namespace std;

class gameOver : public endGameScreen
{
public:
	int draw_game_over();
	sf::Font font;
	sf::Text game_over_item[4];
	int decision;
};

