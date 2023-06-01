#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class gameVictory
{
public:
	sf::Text victory_item[4];
	sf::Font font;
	void draw_victory(sf::RenderWindow& window, sf::Font font);
};

