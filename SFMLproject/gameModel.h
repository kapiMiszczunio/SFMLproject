#pragma once
#include "field.h"

class gameModel
{
private:
	int boardSize;
	vector<vector<int>> board;

public:
	void generateBoard();
	int setBoardSize();
};

