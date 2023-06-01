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
	~gameController();
	explicit gameController();
	void start_menu();

private:
	gameModel model;
	gameView view;
	int difficulty;
	int decision;
};

