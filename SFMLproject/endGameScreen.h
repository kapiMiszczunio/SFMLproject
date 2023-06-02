#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

class endGameScreen
{
public:
	/*
	* function renders end screen window
	* @param RenderWindow object from sfml
	* @param items to display from sfml
	*/
	int renderwindow(sf::RenderWindow& window, sf::Text *items);
};

