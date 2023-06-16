#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include "gameModel.h"
#include "enums.h"
#include <fstream>
#include <string>

class scoreTable
{
public:
	/*
	* function read data (best scores) from text file
	* @param variable holding value of difficulty (easy/medium/hard)
	*/
	void readTable(difficulty difficulty);
	
	/*
	* function drawing window with best scores
	*/
	void displayTable();
	
private:
	/*
	* array containing scores
	*/
	std::string tablescore[5];
	
	/*
	* array containing elements of the window
	*/
	sf::Text scoreTable_item[5];
	
};


 