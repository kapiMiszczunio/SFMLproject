#pragma once
#include "gameVictory.h"
#include "gameOver.h"
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

class endGameScreen : public gameOver, public gameVictory
{
public:
	int gameover();
	int victory();
};

