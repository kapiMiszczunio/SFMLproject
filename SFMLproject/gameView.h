#pragma once
#include "field.h"
#include "SFML/Graphics.hpp"

class gameView
{
public:
	int launch(float width, float height);
	void draw_menu(sf::RenderWindow &window, sf::Font font);
	void play(float width, float height);

private:
	sf::Font font;
	sf::Text menu_item[4];
};