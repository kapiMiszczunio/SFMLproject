#pragma once
#include "gameModel.h"
#include "gameOver.h"
#include "gameVictory.h"
#include "SFML/Graphics.hpp"

class gameView
{
public:
	~gameView();
	int launch(float width, float height);
	void draw_menu(sf::RenderWindow& window, sf::Font font);
	//void draw_game_over(sf::RenderWindow& window, sf::Font font);
	//void draw_victory(sf::RenderWindow& window, sf::Font font);
	int play(float width, float height, gameModel& model);
	void setIcon(sf::RenderWindow& window);
	int fieldLeft;
	//int gameOver();
	//int Victory();

private:
	int mainMenuSelected = 1;
	sf::Font font;
	sf::Text menu_item[4];
	//sf::Text game_over_item[4];
	//sf::Text victory_item[4];
};