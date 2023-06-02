#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "endGameScreen.h"
using namespace std;

class gameVictory : public endGameScreen
{
public:
	int draw_victory();
	sf::Text victory_item[4];
	sf::Font font;
	int decision;
};

