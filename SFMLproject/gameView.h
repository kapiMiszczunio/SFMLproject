#pragma once
#include "field.h"
#include "gameModel.h"
#include "SFML/Graphics.hpp"

class gameView
{
public:
	~gameView();
	int launch(float width, float height);
	void draw_menu(sf::RenderWindow& window, sf::Font font);
	void play(float width, float height, gameModel& model);
	void setIcon(sf::RenderWindow& window);
	void gameOver();
	int fieldLeft;

private:
	int mainMenuSelected = 1;
	sf::Font font;
	sf::Text menu_item[4];
};