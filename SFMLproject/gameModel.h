#pragma once
#include "field.h"

class gameModel
{
private:
	int boardSize;
	int numberOfBombs;
	int flaggedCells = 0;
	vector<vector<int>> board;
	string gameStatus;
	string gameDifficulty;

public:
	void generateBoard();
	string getGameDifficulty();
	string getGameStatus();
	vector<vector<int>> getBoard();
	void setGameStatus(string gameStatus);
	void setGameDifficulty(string difficulty);
	void addFlag();
	void subFlag();
	int getBoardSize();
};

