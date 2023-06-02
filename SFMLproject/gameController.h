#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "gameView.h"
#include "gameModel.h"
using namespace std;

class gameController 
{
public:

	/*
	* destructor of class gameController
	*/
	~gameController();

	/*
	* function starts the game (call in main file)
	*/
	void start_menu();

private:

	/*
	* crates object od gameModel class
	*/
	gameModel model;

	/*
	* crates object od gameView class
	*/
	gameView view;

	/*
	* variable holds value of game difficulty (1, 2 or 3)
	*/
	int difficulty;
};

