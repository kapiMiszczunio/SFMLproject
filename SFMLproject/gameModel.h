#pragma once
#include "field.h"
#include "ctime"

class gameModel
{
private:
	unsigned seed;
	int boardSize;
	int numberOfBombs;
	int fieldLeft;
	int flaggedCells = 0;
	vector<vector<int>> board;
	vector<vector<int>> grid;
	int gameStatus;
	string gameDifficulty;

public:
	~gameModel();
	void generateBoard();
	void generateGrid();
	vector<vector<int>> getGrid();
	string getGameDifficulty();
	int getGameStatus();
	vector<vector<int>> getBoard();
	void setGameStatus(int gameStatus);
	void setGameDifficulty(string difficulty);
	void addFlag();
	void subFlag();
	int getBoardSize();
	int getFieldLeft();

};
