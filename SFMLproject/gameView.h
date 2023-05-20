#pragma once
#include "field.h"
#include "SFML/Graphics.hpp"


class gameView
{
public:
	void launch(double width, double height);
	void draw_menu(sf::RenderWindow &window, sf::Font font);

private:
	sf::Font font;
	sf::Text menu_item[4];
};