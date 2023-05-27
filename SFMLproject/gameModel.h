#pragma once
#include "field.h"

class gameModel
{
private:
	int boardSize;
	int fieldLeft;
	int seed;
	int numberOfBombs;
	int flaggedCells = 0;
	vector<vector<int>> board;
	vector<vector<int>> grid;
	string gameStatus;
	string gameDifficulty;

public:
	~gameModel();
	void generateBoard();
	void generateGrid();
	string getGameDifficulty();
	string getGameStatus();
	vector<vector<int>> getBoard();
	vector<vector<int>> getGrid();
	void setGameStatus(string gameStatus);
	void setGameDifficulty(string difficulty);
	void addFlag();
	void subFlag();
	int getBoardSize();
	int getFieldLeft();
};

