#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include "gameModel.h"
#include "enums.h"
#include <fstream>
#include "vector"
#include <string>
class scoreTable
{
public:
	void readTable(int difficulty);
	void displayTable();
	std::string tablescore[5];
	sf::Text ranking[5];
	
};


 