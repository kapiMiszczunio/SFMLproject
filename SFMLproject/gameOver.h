#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class gameOver
{
public:
	void draw_game_over(sf::RenderWindow& window, sf::Font font);
	sf::Font font;
	sf::Text game_over_item[4];
};

