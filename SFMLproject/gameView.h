#pragma once
#include "gameModel.h"
#include "gameOver.h"
#include "gameVictory.h"
#include "SFML/Graphics.hpp"

class gameView
{
public:

	/*
	* gameView class destructor
	*/
	~gameView();

	/*
	* function with main menu functionalities and key actions
	* @param window width
	* @param window height
	* @return returns difficulty level (1, 2 or 3)
	*/
	int launch(float width, float height);

	/*
	* function renders main menu
	* @param RenderWindow object from sfml
	* @param font used for text from sfml
	*/
	void draw_menu(sf::RenderWindow& window, sf::Font font);

	/*
	* function draws game board
	* @param window width
	* @param window height
	* @param object of gameModel
	* @return returns end screen
	*/
	int play(float width, float height, gameModel& model);

	/*
	* function sets window icon picture
	* @param RenderWindow object from sfml
	*/
	void setIcon(sf::RenderWindow& window);

	/*
	* variable holds number of unrevealed fields
	*/
	int fieldLeft;
	sf::Time curr_time;
	//sf::Clock timer;

private:

	/*
	* object holds object of font from sfml
	*/
	sf::Font font;
	int start_timer;

	/*
	* object holds menu items (title "Saper" and buttons with difficulty level) from sfml
	*/
	sf::Text menu_item[4];
};